"""
prepare_dataset.py

Reads all 1200 C++ dataset pairs from dataset/input/ and dataset/output/,
groups them by question (every 6 consecutive files = one question),
pools and cleans test cases from all variants, then writes:
  - dataset/train.jsonl  (90% of groups)
  - dataset/val.jsonl    (10% of groups)

Each line is a Qwen chat-format JSON object:
  { "messages": [ {system}, {user: question+code}, {assistant: JSON test cases} ] }

Run from the repo root:
  python dataset/prepare_dataset.py
"""

import json
import os
import random
import re
from pathlib import Path

# ── Paths ──────────────────────────────────────────────────────────────────────
SCRIPT_DIR   = Path(__file__).parent
INPUT_DIR    = SCRIPT_DIR / "input"
OUTPUT_DIR   = SCRIPT_DIR / "output"
TRAIN_OUT    = SCRIPT_DIR / "train.jsonl"
VAL_OUT      = SCRIPT_DIR / "val.jsonl"

# ── Config ─────────────────────────────────────────────────────────────────────
FIRST_FILE   = 601          # lowest numbered file in the dataset
GROUP_SIZE   = 6            # files per question group
CORRECT_POS  = 5            # position of the correct version within a group (0-indexed)
VAL_RATIO    = 0.10         # fraction of groups held out for validation
RANDOM_SEED  = 42

# Regex to catch vague / non-concrete expected values or inputs
VAGUE_PATTERN = re.compile(
    r"graceful|handled|no.?crash|n/?a|segfault|crash|"
    r"full.{0,10}array|shorter than|longer than|"
    r"^description$|^n/a$|^none$|^undefined$|"
    r"^any input$|^any.{0,10}input$|uninitialized|"
    r"^no input$|^no.{0,15}input$|"
    r"compilation.{0,10}fail|syntax.{0,10}error",  # untestable compilation errors
    re.IGNORECASE
)

SYSTEM_PROMPT = (
    "You are an expert software tester. "
    "Given a programming question and a code submission, generate comprehensive "
    "test cases as a valid JSON array. "
    'Each test case must have: "input" (the test input as a string), '
    '"expected_output" (the correct result), and '
    '"description" (what the test verifies). '
    "Output ONLY the JSON array with no explanation, no markdown, no code fences."
)


# ── Helpers ────────────────────────────────────────────────────────────────────

def is_vague(value: str) -> bool:
    """Return True if value is a behavioural description rather than a concrete value."""
    return bool(VAGUE_PATTERN.search(str(value).strip()))


def load_json_safe(path: Path):
    """Return parsed JSON or None on error, logging the filename."""
    try:
        with open(path, encoding="utf-8") as f:
            return json.load(f)
    except Exception as exc:
        print(f"  [SKIP] JSON parse error in {path.name}: {exc}")
        return None


def pool_test_cases(group_files: list[Path]) -> list[dict]:
    """
    Collect, filter, and deduplicate test cases from all files in a group.

    Filtering rules:
      - Skip if test_cases is missing or empty
      - Skip individual cases where input or expected is vague
      - Skip cases where input has no concrete value markers (=, {, digit)
      - Deduplicate on the normalised input string (first occurrence wins)
    """
    seen_inputs: set[str] = set()
    result: list[dict] = []

    for path in group_files:
        data = load_json_safe(path)
        if data is None:
            continue
        for tc in data.get("test_cases") or []:
            raw_input    = str(tc.get("input",    "")).strip()
            raw_expected = str(tc.get("expected", tc.get("expected_output", ""))).strip()

            if not raw_expected:   # empty expected is never useful; empty input is OK
                continue
            if is_vague(raw_input) or is_vague(raw_expected):
                continue

            key = raw_input.lower()
            if key in seen_inputs:
                continue
            seen_inputs.add(key)

            result.append({
                "input":           raw_input,
                "expected_output": raw_expected,
            })

    # Attach auto-generated descriptions (dataset has none)
    for i, tc in enumerate(result):
        tc["description"] = f"Test case {i + 1}"

    return result


def build_example(question: str, cpp_code: str, test_cases: list[dict]) -> dict:
    """Wrap one training example in Qwen's chat message format."""
    assistant_content = json.dumps(test_cases, ensure_ascii=False, separators=(",", ":"))
    return {
        "messages": [
            {"role": "system",    "content": SYSTEM_PROMPT},
            {"role": "user",      "content": f"Question: {question}\n\nCode:\n{cpp_code}"},
            {"role": "assistant", "content": assistant_content},
        ]
    }


# ── Main ───────────────────────────────────────────────────────────────────────

def main():
    # Collect all JSON files, sort numerically
    json_files = sorted(
        OUTPUT_DIR.glob("*.json"),
        key=lambda p: int(p.stem) if p.stem.isdigit() else -1
    )
    if not json_files:
        print(f"No JSON files found in {OUTPUT_DIR}")
        return

    file_nums  = [int(p.stem) for p in json_files if p.stem.isdigit()]
    first_num  = min(file_nums)
    last_num   = max(file_nums)
    num_groups = (last_num - first_num + 1) // GROUP_SIZE

    print(f"Files: {first_num}–{last_num}  |  Groups of {GROUP_SIZE}  |  "
          f"Expected groups: {num_groups}")

    # Build group indices and shuffle for train/val split
    group_ids = list(range(num_groups))
    random.seed(RANDOM_SEED)
    random.shuffle(group_ids)

    val_size   = max(1, round(len(group_ids) * VAL_RATIO))
    val_ids    = set(group_ids[:val_size])
    train_ids  = set(group_ids[val_size:])

    stats = {"total": 0, "skipped_no_tc": 0, "skipped_missing": 0,
             "train": 0, "val": 0, "total_tc": 0}

    train_examples: list[dict] = []
    val_examples:   list[dict] = []

    for gid in range(num_groups):
        stats["total"] += 1
        base = first_num + gid * GROUP_SIZE

        # Paths for all 6 files in this group
        group_json = [OUTPUT_DIR / f"{base + i}.json" for i in range(GROUP_SIZE)]
        correct_json = group_json[CORRECT_POS]
        correct_cpp  = INPUT_DIR  / f"{base + CORRECT_POS}.cpp"

        # Check correct-version files exist
        if not correct_json.exists() or not correct_cpp.exists():
            stats["skipped_missing"] += 1
            continue

        correct_data = load_json_safe(correct_json)
        if correct_data is None:
            stats["skipped_missing"] += 1
            continue

        question = correct_data.get("question", "").strip()
        if not question:
            stats["skipped_missing"] += 1
            continue

        cpp_code = correct_cpp.read_text(encoding="utf-8", errors="replace").strip()

        # Pool test cases from all 6 variants
        existing = [p for p in group_json if p.exists()]
        test_cases = pool_test_cases(existing)

        if not test_cases:
            stats["skipped_no_tc"] += 1
            continue

        example = build_example(question, cpp_code, test_cases)
        stats["total_tc"] += len(test_cases)

        if gid in val_ids:
            val_examples.append(example)
            stats["val"] += 1
        else:
            train_examples.append(example)
            stats["train"] += 1

    # Write JSONL files
    for path, examples in [(TRAIN_OUT, train_examples), (VAL_OUT, val_examples)]:
        with open(path, "w", encoding="utf-8") as f:
            for ex in examples:
                f.write(json.dumps(ex, ensure_ascii=False) + "\n")
        print(f"Wrote {len(examples):>4} examples → {path.name}")

    usable = stats["train"] + stats["val"]
    avg_tc = stats["total_tc"] / usable if usable else 0
    print(f"\n── Summary ──────────────────────────────")
    print(f"  Total groups processed : {stats['total']}")
    print(f"  Skipped (missing files): {stats['skipped_missing']}")
    print(f"  Skipped (no test cases): {stats['skipped_no_tc']}")
    print(f"  Usable examples        : {usable}  "
          f"(train={stats['train']}, val={stats['val']})")
    print(f"  Avg test cases/example : {avg_tc:.2f}")
    print(f"─────────────────────────────────────────")


if __name__ == "__main__":
    main()
