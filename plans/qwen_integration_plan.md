# Integration Plan: Replace API with Local Qwen Model for Test Generation

## Overview
The goal is to replace the OpenAI (or other API) client used in the test generation module with a local Qwen model. OpenAI is **kept for test execution** because that module uses `create_agent` with `ShellTool`, which requires LangChain's function-calling interface that the local wrapper does not implement. Additionally, we will adjust the local model client to support loading LLaMA in 4-bit quantization (down from 8-bit) and Qwen in 8-bit quantization to efficiently utilize the available GPU VRAM.

---

## Sub-tasks

### 1. Refactor Local Model Client
**File:** `autograder-ai/src/autograder_ai/clients/huggingface_client.py`

**Changes:**
- Add `model_name`, `quantization_bits`, and `max_new_tokens` constructor parameters to `HuggingFaceClient` so it can be instantiated for different models without subclassing.
- Add `model_name` and `max_new_tokens` parameters to `HuggingFaceLLMWrapper.__init__`, and store `self.model_name` as a public attribute (used for logging in evaluation and test generation nodes).
- Replace `max_new_tokens=500` in `HuggingFaceLLMWrapper.invoke()` with `self._max_new_tokens` so callers can control output length per model.
- In `_load_model()`, use `BitsAndBytesConfig(load_in_4bit=True)` when `quantization_bits == 4`, otherwise `load_in_8bit=True`.
- Update the `_load_model()` print message to include the bit-width: `Loading {model_name} ({bits}-bit quantized)...`
- Pass `model_name` and `max_new_tokens` through to `HuggingFaceLLMWrapper` when constructing it inside `_load_model()`.

**Critical note on `max_new_tokens`:**
The current value of `500` is sufficient for the short structured responses in the evaluation module, but is far too low for test generation. Qwen must generate 8–15 test cases in full JSON (each with `input`, `expected_output`, `description`), which can easily exceed 2000 tokens. The Qwen client must be created with `max_new_tokens=2048`.

---

### 2. Update Engine to Wire Qwen for Test Generation
**File:** `autograder-ai/src/autograder_ai/engine.py`

This is the **real injection point** — not the builder. The builder is already model-agnostic; it just accepts whatever `llm` is passed in.

**Changes:**
- Add `import os` if not already present.
- Keep `self.llm = openai_client.llm` unchanged — this continues to be used by `_run_tests()` (test execution via LangChain agent).
- Create a separate Qwen client for test generation:
  ```python
  qwen_model = os.getenv("QWEN_MODEL_NAME", "Qwen/Qwen2.5-Coder-7B-Instruct")
  qwen_client = HuggingFaceClient(model_name=qwen_model, quantization_bits=8, max_new_tokens=2048)
  self.test_gen_llm = qwen_client.get_llm()
  ```
- Change LLaMA from 8-bit to 4-bit by updating its instantiation:
  ```python
  llama_model = os.getenv("HF_MODEL_NAME", "meta-llama/Llama-3.2-3B-Instruct")
  hf_client = HuggingFaceClient(model_name=llama_model, quantization_bits=4, max_new_tokens=500)
  self.quality_llm = hf_client.get_llm()
  ```
- In `_generate_tests()`, pass `self.test_gen_llm` instead of `self.llm` to `TestGenerationBuilder`:
  ```python
  builder = TestGenerationBuilder(self.test_gen_llm)
  ```
- `_run_tests()` is **not changed** — it continues to use `self.llm` (OpenAI).

---

### 3. Add Logging to Test Generation Node
**File:** `autograder-ai/src/autograder_ai/workflows/nodes/test_generation.py`

**Changes:**
- At the top of the inner `node` function inside `generate_test_cases_node`, add a model source log that mirrors the evaluation module's style:
  ```python
  from ...clients.huggingface_client import HuggingFaceLLMWrapper
  if isinstance(llm, HuggingFaceLLMWrapper):
      source = f"[LOCAL MODEL - {llm.model_name}]"
  else:
      source = "[OpenAI API]"
  print(f"\n{source} Generating test cases...")
  ```

---

### 4. Fix Hardcoded Model Name in Evaluation Logging
**File:** `autograder-ai/src/autograder_ai/workflows/nodes/evaluation.py`

**Context:** The current logging line (line 19) hardcodes `"LLaMA 3.2 3B"`:
```python
source = "[LOCAL MODEL - LLaMA 3.2 3B]" if isinstance(llm, HuggingFaceLLMWrapper) else "[OpenAI API - gpt-4o-mini]"
```
Since `HuggingFaceLLMWrapper` now carries a `model_name` attribute (added in Sub-task 1), this can be made dynamic so it automatically reflects whatever model is actually loaded.

**Change:**
```python
source = f"[LOCAL MODEL - {llm.model_name}]" if isinstance(llm, HuggingFaceLLMWrapper) else "[OpenAI API - gpt-4o-mini]"
```
This applies to all three functions that use this pattern: `evaluate_correctness`, `evaluate_code_quality`, and `generate_feedback`.

---

### 5. Update Environment Variable Files
**Files:** `autograder-ai/.env` and `autograder-ai/.env.example`

Add the following new entries under the HuggingFace section (create the section if it does not exist):

```
# HuggingFace Local Models
HF_MODEL_NAME=meta-llama/Llama-3.2-3B-Instruct
QWEN_MODEL_NAME=<path-or-huggingface-id-of-your-downloaded-qwen-model>
```

The `QWEN_MODEL_NAME` value should be the local directory path or HuggingFace model ID of the Qwen model you downloaded (e.g., `Qwen/Qwen2.5-Coder-7B-Instruct` or an absolute local path like `/models/qwen2.5-coder-7b`).

---

### 6. Verify Output Parsing & Consistency
**File:** `autograder-ai/src/autograder_ai/workflows/nodes/test_generation.py`

**What to verify:**
- After first run with Qwen, inspect the raw `content` from `llm.invoke()` before `extract_json` processes it.
- Qwen models sometimes wrap their JSON in markdown code fences (` ```json ... ``` `). Confirm that the existing `extract_json` utility handles this. If not, update `extract_json` to strip code fences before parsing.
- The output format must remain strictly identical to what the API produced: a JSON array where each element has `input` (dict), `expected_output`, and optionally `description` (string). Any test case that fails `is_valid_test_case()` is silently dropped by `validate_tests_node`, so a broken format will reduce test case count rather than crash — watch for `0/N validated` in logs.

---

## Execution Order
Run the sub-tasks in this order to avoid broken intermediate states:
1. Sub-task 1 (client refactor) — foundation everything else depends on
2. Sub-task 5 (env vars) — needed before engine loads models
3. Sub-task 2 (engine wiring) — wires the new client into the pipeline
4. Sub-task 3 (test gen logging) — cosmetic, safe to do any time after Sub-task 1
5. Sub-task 4 (evaluation logging fix) — cosmetic, safe to do any time after Sub-task 1
6. Sub-task 6 (output verification) — done at runtime after first test run

## Summary of LLM Routing After Implementation

| Module | Model | Quantization | max_new_tokens | API key needed |
|---|---|---|---|---|
| Test Generation | Qwen (local) | 8-bit | 2048 | No |
| Test Execution | OpenAI gpt-4o-mini | — | — | Yes |
| Evaluation (all 3 nodes) | LLaMA 3.2 3B (local) | 4-bit | 500 | No |
