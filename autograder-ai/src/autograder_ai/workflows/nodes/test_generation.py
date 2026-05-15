import json
from typing import Any, Dict

from ..states import TestGenerationState, TestCase
from ..prompts import TEST_GENERATION_PROMPT
from ...utils import extract_json


REPAIR_JSON_PROMPT = """
The previous response should have been a single valid JSON array of test cases.

Convert the content below into valid JSON only:
- Return one JSON array.
- Do not use markdown code fences.
- Do not include explanations or comments.
- Preserve the fields "input", "expected_output", and "description".
- Close all arrays and objects.

CONTENT TO REPAIR:
{content}
"""


def analyze_question_node(state: TestGenerationState) -> TestGenerationState:
    """Node: Analyze the assignment question"""
    print(f"  -> Analyzing question: {state['question_id']}")
    return state


def analyze_code_node(state: TestGenerationState) -> TestGenerationState:
    """Node: Analyze the submitted code"""
    print("  -> Analyzing submitted code")
    return state


def is_valid_test_case(case: Any) -> bool:
    """Check if a test case matches the TestCase schema"""
    if not isinstance(case, dict):
        return False

    # Check required fields
    if "input" not in case or "expected_output" not in case:
        return False

    # Validate input is a dict or a plain string (fine-tuned model outputs strings)
    if not isinstance(case["input"], (dict, str)):
        return False

    # Description is optional but must be string if present
    if "description" in case and not isinstance(case["description"], str):
        return False

    return True


def _compact_preview(text: str, limit: int = 300) -> str:
    compact = text.replace("\r", "\\r").replace("\n", "\\n")
    return compact[:limit]


def _print_response_diagnostics(content: str, json_str: str | None = None) -> None:
    print(f"  Raw response length: {len(content)} chars")
    print(f"  Raw response start: {_compact_preview(content)}")

    if len(content) > 300:
        print(f"  Raw response end: {_compact_preview(content[-300:])}")

    if json_str is not None:
        print(f"  Extracted JSON length: {len(json_str)} chars")
        print(f"  Extracted JSON start: {_compact_preview(json_str)}")


def _parse_test_cases(content: str) -> tuple[list[Any], str]:
    json_str = extract_json(content)
    parsed = json.loads(json_str)

    if isinstance(parsed, dict) and isinstance(parsed.get("test_cases"), list):
        parsed = parsed["test_cases"]

    if not isinstance(parsed, list):
        raise ValueError("LLM response must be a JSON array of test cases")

    return parsed, json_str


def _salvage_test_case_objects(content: str) -> list[Any]:
    decoder = json.JSONDecoder()
    sanitized = content.strip()
    sanitized = sanitized.removeprefix("```json").removeprefix("```").strip()
    cases: list[Any] = []
    index = 0

    while index < len(sanitized):
        start = sanitized.find("{", index)
        if start == -1:
            break

        try:
            candidate, end = decoder.raw_decode(sanitized[start:])
        except json.JSONDecodeError:
            index = start + 1
            continue

        if is_valid_test_case(candidate):
            cases.append(candidate)

        index = start + end

    return cases


def generate_test_cases_node(llm):
    def node(state):
        from ...clients.huggingface_client import HuggingFaceLLMWrapper
        if isinstance(llm, HuggingFaceLLMWrapper):
            source = f"[LOCAL MODEL - {llm.model_name}]"
        else:
            source = "[OpenAI API]"
        print(f"\n{source} Generating test cases...")

        prompt = TEST_GENERATION_PROMPT.format(
            question=state["question"],
            code=state["code"]
        )

        response = llm.invoke(prompt)
        content = str(response.content)

        try:
            test_cases, _ = _parse_test_cases(content)
            state["test_cases"] = test_cases
        except (json.JSONDecodeError, ValueError) as e:
            print(f"  x Failed to parse JSON: {e}")
            _print_response_diagnostics(content)

            salvaged_cases = _salvage_test_case_objects(content)
            if salvaged_cases:
                state["test_cases"] = salvaged_cases
                print(f"  ok Salvaged {len(salvaged_cases)} complete test cases")
                return state

            repaired_content = ""
            try:
                repair_prompt = REPAIR_JSON_PROMPT.format(content=content)
                repaired_response = llm.invoke(repair_prompt)
                repaired_content = str(repaired_response.content)
                test_cases, repaired_json = _parse_test_cases(repaired_content)
                state["test_cases"] = test_cases
                print("  ok Repaired JSON parsed successfully")
                _print_response_diagnostics(repaired_content, repaired_json)
            except (json.JSONDecodeError, ValueError) as repair_error:
                print(f"  x JSON repair failed: {repair_error}")
                _print_response_diagnostics(repaired_content)
                state["test_cases"] = []
            except Exception as repair_error:
                print(f"  x JSON repair request failed: {repair_error}")
                state["test_cases"] = []

            return state

        return state

    return node

def validate_tests_node(state: TestGenerationState) -> TestGenerationState:
    """Validate that test cases match the TestCase schema"""
    raw_cases = state.get("test_cases", None)

    if not isinstance(raw_cases, list):
        print("  x LLM returned a non-list -- resetting test_cases to empty list")
        state["test_cases"] = []
        return state

    validated: list[TestCase] = []

    for index, case in enumerate(raw_cases):
        if is_valid_test_case(case):
            validated.append(case)
        else:
            # Provide specific feedback on what's wrong
            if not isinstance(case, dict):
                print(f"  x Test case {index} is not a dict. Skipping.")
            elif "input" not in case:
                print(f"  x Test case {index} missing 'input' field. Skipping.")
            elif "expected_output" not in case:
                print(f"  x Test case {index} missing 'expected_output' field. Skipping.")
            elif not isinstance(case["input"], (dict, str)):
                print(f"  x Test case {index} 'input' is not a dict or string. Skipping.")
            elif "description" in case and not isinstance(case["description"], str):
                print(f"  x Test case {index} 'description' is not a string. Skipping.")

    print(f"  ok Validated {len(validated)}/{len(raw_cases)} test cases")
    state["test_cases"] = validated
    return state

