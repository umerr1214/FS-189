# Backend Context — autograder-ai

> **Purpose of this file:** LLM context injection document. Read this before making any changes to the Python autograder backend. It describes the architecture, module responsibilities, data flow, and setup so that an LLM can reason accurately about where to make changes and how the system behaves.

---

## What This System Does

`autograder-ai` is a Python pipeline that automatically grades student code submissions. Given an assignment PDF and a directory of student `.py` files, it:

1. Extracts questions from the PDF and maps them to submitted code files.
2. Uses an LLM to generate comprehensive test cases for each question.
3. Uses an LLM agent to execute those tests against the student code in a real shell.
4. Evaluates correctness, code quality, and generates human-readable feedback.
5. Produces a final grading report with scores and feedback per question.

---

## Directory Structure

```
autograder-ai/
├── main.py                             # CLI entry point
├── pyproject.toml                      # Python dependencies (Poetry)
├── Dockerfile / docker-compose.yml     # Container config
├── input/
│   ├── assignment.pdf                  # Assignment with questions
│   └── submission/                     # Student code files (q_1.py, q_2.py, …)
└── src/autograder_ai/
    ├── engine.py                       # Main orchestrator — EvaluationEngine
    ├── clients/
    │   ├── openai_client.py            # OpenAI (GPT-4o-mini) wrapper
    │   ├── huggingface_client.py       # HuggingFace local model wrapper
    │   └── ollama_client.py            # Ollama local model wrapper
    ├── core/
    │   ├── file_hanlders/              # NOTE: intentional typo in folder name
    │   │   ├── base.py                 # Abstract file handler
    │   │   ├── pdf.py                  # PDF text extraction (PyPDF2)
    │   │   └── code.py                 # Source code file reader
    │   ├── pre_processors/
    │   │   ├── base.py                 # Abstract pre-processor
    │   │   ├── assignment.py           # Parses PDF → {q_1: text, q_2: text, …}
    │   │   └── submission.py           # Reads submission dir → {q_1.py: code, …}
    │   └── tools.py                    # Shared utilities
    ├── utils/
    │   ├── json_helpers.py             # JSON extraction/sanitization from LLM output
    │   └── code_execution.py           # stdin formatting, agent response parsing
    └── workflows/
        ├── states/                     # TypedDict state definitions
        │   ├── test_generation.py      # TestGenerationState, TestCase
        │   ├── evaluation.py           # TestExecutionState, EvaluationState, TestResult
        │   └── __init__.py
        ├── nodes/                      # Individual LangGraph node functions
        │   ├── test_generation.py      # analyze_question, analyze_code, generate_test_cases, validate_tests
        │   ├── test_execution.py       # setup_code_file, initialize, execute_single_test, finalize
        │   └── evaluation.py          # evaluate_correctness, evaluate_code_quality, handle_partial_credit, apply_rubric, generate_feedback
        ├── prompts/                    # All LLM prompt templates
        │   ├── test_generation.py      # TEST_GENERATION_PROMPT
        │   ├── test_execution.py       # TEST_EXECUTION_PROMPT
        │   ├── evaluation.py           # CORRECTNESS_PROMPT, CODE_QUALITY_PROMPT, FEEDBACK_PROMPT
        │   └── __init__.py
        └── builders/                  # LangGraph StateGraph assemblers
            ├── test_generation.py      # TestGenerationBuilder
            ├── test_execution.py       # TestExecutionBuilder
            └── evaluation.py          # EvaluationBuilder
```

---

## Key Modules and Responsibilities

### `engine.py` — EvaluationEngine

The top-level orchestrator. Instantiated once per run. Holds all LLM clients and pre-processors. Exposes four public methods called in sequence:

| Method | Responsibility |
|---|---|
| `_generate_tests()` | Runs TestGenerationBuilder per question; stores `TestCase` lists |
| `_run_tests()` | Runs TestExecutionBuilder per question; stores `TestResult` lists |
| `_run_evaluation()` | Runs EvaluationBuilder per question; produces scores and feedback |
| `generate_report()` | Formats all results into a printable report |
| `run()` | Calls all four methods in order |

LLM model assignments at construction time:
- **Qwen2.5-Coder-7B** (HuggingFace) → test case generation
- **GPT-4o-mini** (OpenAI) → test execution agent
- **LLaMA 3.2 3B** (HuggingFace, 4-bit quantized) → correctness eval, code quality, feedback

### `core/pre_processors/assignment.py` — AssignmentPreProcessor

Reads the assignment PDF using `PDFFileHandler`, then extracts questions with the regex:
```
Q(\d+)\s*[:.]\s*(.*?)(?=(?:Q\d+[:.])|\Z)
```
Returns a dict like `{"q_1": "Write a function that…", "q_2": "…"}`.

Questions **must** be labeled `Q1`, `Q2`, etc. in the PDF for extraction to work.

### `core/pre_processors/submission.py` — SubmissionPreProcessor

Scans the submission directory. Only files matching the glob `q_*` (case-insensitive) are accepted. Returns `{"q_1.py": "<code>", "q_2.py": "<code>"}`. Mismatched filenames are silently skipped.

### `clients/huggingface_client.py` — HuggingFaceClient

Loads HuggingFace Transformers models locally with BitsAndBytes quantization (4-bit or 8-bit). Wraps the pipeline in `HuggingFaceLLMWrapper`, which implements the LangChain `BaseLLM` interface so it can be used anywhere an LLM is expected. The `invoke()` call is the primary interface used by workflow nodes.

### `clients/openai_client.py` — OpenaiClient

Thin wrapper around `langchain_openai.ChatOpenAI`. Reads `OPENAI_API_KEY` and `OPENAI_MODEL_NAME` from `.env`. The `client` attribute is the `ChatOpenAI` instance passed to nodes.

---

## Workflow Architecture (LangGraph)

All three workflows use `langgraph.graph.StateGraph`. Each workflow is a directed graph of node functions that read and write a shared `TypedDict` state.

### Workflow 1: Test Generation

**Graph:** `analyze_question → analyze_code → generate_tests → validate_tests → END`

**Key node — `generate_test_cases_node(llm)`:**
- Sends `TEST_GENERATION_PROMPT` (with question + code) to the Qwen LLM.
- Expects a JSON array of `{input, expected_output, description}` objects.
- Parses via `extract_json()` from `utils/json_helpers.py`.
- Target: 8–15 test cases covering normal, boundary, edge, and invalid inputs.

**Key node — `validate_tests_node()`:**
- Filters out any test cases missing `input` or `expected_output`, or where `input` is not a dict.

### Workflow 2: Test Execution

**Graph:** `setup_code_file → initialize → execute_test ⟲ (loop) → finalize → END`

The loop continues via the conditional edge `should_continue_testing()` until all test cases are exhausted.

**Key node — `execute_single_test_node(llm)`:**
- Writes the student code to a temp file.
- Creates a `langchain_community.tools.ShellTool` and an LLM agent (ReAct style).
- Instructs the agent to run: `echo "{stdin_input}" | python {code_file_path}`
- Parses the agent's natural-language response for `RESULT: PASSED/FAILED`, `ACTUAL OUTPUT:`, and `REASONING:` using regex in `parse_agent_response()`.

**Key node — `finalize_execution_node()`:**
- Deletes the temp code file.
- Calculates aggregate pass/fail statistics.

### Workflow 3: Evaluation

**Graph:** `correctness → quality → partial_credit → (rubric if provided) → feedback → finalize → END`

**`evaluate_correctness()`:** Short-circuits if all tests pass (fully correct) or none pass (incorrect); otherwise calls LLM for partial analysis.

**`evaluate_code_quality()`:** LLM scores `readability`, `structure`, `best_practices`, `efficiency` each 0–10.

**`handle_partial_credit()`:** Score ratio = passed/total. Eligible if ratio > 0.3.

**`apply_rubric()`:** Only runs if a rubric dict was provided. Applies weights to produce a weighted final score.

**`generate_feedback()`:** LLM produces a mentor-tone paragraph addressing what went right, what went wrong, and concrete suggestions.

---

## State Types Reference

### `TestGenerationState`
```python
{
    "question_id": str,           # "q_1", "q_2", …
    "question": str,              # Full question text from PDF
    "code": str,                  # Student's submitted code
    "test_cases": List[TestCase]  # Populated by generate_test_cases_node
}
```

### `TestCase`
```python
{
    "input": Dict[str, Any],       # Parameter names → values (used as stdin)
    "expected_output": Any,         # Expected return value or stdout
    "description": Optional[str]    # Human-readable test description
}
```

### `TestExecutionState`
```python
{
    "question_id": str,
    "code": str,
    "code_file_path": str,          # Temp file written by setup_code_file_node
    "test_cases": List[Dict],
    "current_test_index": int,      # Incremented each loop iteration
    "test_results": List[TestResult],
    "status": EvaluationStatus      # PENDING | PROCESSING | COMPLETED | FAILED
}
```

### `EvaluationState`
```python
{
    "question_id": str,
    "question": str,
    "code": str,
    "test_results": List[TestResult],
    "rubric": Optional[Dict[str, float]],

    # Populated by evaluation nodes:
    "correctness": Optional[Dict],   # {status, explanation, confidence}
    "code_quality": Optional[Dict],  # {readability, structure, best_practices, efficiency}
    "partial_credit": Optional[Dict],# {eligible, suggested_score, reason}
    "final_score": Optional[Dict],   # {total, breakdown}
    "feedback": Optional[str],

    "status": EvaluationStatus
}
```

---

## Data Flow Summary

```
CLI (main.py)
  └─ EvaluationEngine.run()
       ├─ AssignmentPreProcessor  →  {q_1: question_text, …}
       ├─ SubmissionPreProcessor  →  {q_1.py: code, …}
       │
       ├─ [per question] TestGenerationBuilder (Qwen LLM)
       │       →  List[TestCase]
       │
       ├─ [per question] TestExecutionBuilder (GPT-4o-mini + ShellTool)
       │       →  List[TestResult]  (each has passed: bool, actual_output, reasoning)
       │
       └─ [per question] EvaluationBuilder (LLaMA 3.2 3B)
               →  correctness, code_quality, partial_credit, feedback
               →  generate_report() prints final grades
```

---

## Dependencies and Setup

### Runtime Requirements
- Python 3.13
- Poetry (or `pip install -e .`)
- GPU recommended for HuggingFace local models (LLaMA, Qwen); CPU fallback is very slow.

### Key Python Dependencies
| Package | Version | Purpose |
|---|---|---|
| `langgraph` | ^1.0.3 | Workflow state machine |
| `langchain` | ^1.0.8 | LLM abstractions |
| `langchain-openai` | ^1.0.3 | OpenAI integration |
| `langchain-ollama` | ^1.0.0 | Ollama local model support |
| `langchain-community` | ^0.4.1 | ShellTool for code execution |
| `transformers` | (via HF) | Local model loading |
| `bitsandbytes` | (via HF) | 4-bit/8-bit quantization |
| `pypdf2` | ^3.0.1 | PDF text extraction |
| `python-dotenv` | ^1.2.1 | `.env` file loading |

### Environment Variables (`.env` in `autograder-ai/`)
```
OPENAI_API_KEY=sk-...            # Required for test execution and evaluation
OPENAI_MODEL_NAME=gpt-4o-mini    # Optional, defaults to gpt-4o-mini
HF_MODEL_NAME=meta-llama/Llama-3.2-3B-Instruct  # Optional
OLLAMA_MODEL_NAME=<model>        # Optional, only if using Ollama
```

### Running the Pipeline
```bash
cd autograder-ai
poetry install
cp .env.example .env             # Fill in API keys
python main.py --assignment input/assignment.pdf --submission input/submission/
```

### Docker
```bash
docker-compose up --build
# Reads from ./input/, writes report to stdout
```

---

## Where to Make Common Changes

| Task | File(s) to Edit |
|---|---|
| Change LLM model assignments | `engine.py` constructor |
| Modify test generation prompt | `workflows/prompts/test_generation.py` |
| Change how tests are executed | `workflows/nodes/test_execution.py` → `execute_single_test_node` |
| Change scoring/rubric logic | `workflows/nodes/evaluation.py` → `apply_rubric`, `handle_partial_credit` |
| Change feedback tone/content | `workflows/prompts/evaluation.py` → `FEEDBACK_PROMPT` |
| Add a new file type (e.g., `.cpp`) | `core/file_hanlders/code.py` and `core/pre_processors/submission.py` |
| Add a new LLM provider | Add a new client in `clients/`, follow `openai_client.py` as a template |
| Change question parsing regex | `core/pre_processors/assignment.py` |
| Change JSON extraction logic | `utils/json_helpers.py` |

---

## Maintenance Note

**Keep this file updated whenever:**
- A new LLM client or model is added or swapped out.
- Workflow nodes are added, removed, or re-ordered in any builder.
- State TypedDicts gain or lose fields.
- A new pre-processor or file handler is added.
- The CLI interface (`main.py`) changes arguments or behavior.
- New environment variables are introduced.
- The scoring or rubric logic changes.
- The dependency versions in `pyproject.toml` change significantly.

**How to update:** Edit the relevant section above. Keep the "Where to Make Common Changes" table current — it is the first thing an LLM or developer will consult when deciding where to make an edit.
