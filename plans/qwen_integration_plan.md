# Integration Plan: Replace API with Local Qwen Model for Test Generation

## Overview
The goal is to replace the OpenAI (or other API) client used in the test generation module with a local Qwen model. Additionally, we will adjust the local model client to support loading LLaMA in 4-bit quantization (down from 8-bit) and Qwen in 8-bit quantization to efficiently utilize the available GPU VRAM.

## Sub-tasks

### 1. Refactor Local Model Client
**File:** `autograder-ai/src/autograder_ai/clients/huggingface_client.py`
- Refactor `HuggingFaceClient` to support loading different models with specific configurations.
- Update the existing LLaMA initialization to use 4-bit quantization (using `BitsAndBytesConfig(load_in_4bit=True)`).
- Add support for initializing the Qwen model using 8-bit quantization (`BitsAndBytesConfig(load_in_8bit=True)`).
- Implement dynamic loading so that only the required model is loaded into VRAM, or both can be loaded if VRAM permits (or singleton pattern for each model).

### 2. Update Test Generation Workflow
**File:** `autograder-ai/src/autograder_ai/workflows/builders/test_generation.py`
- Modify the builder to fetch and inject the Qwen model client instead of the OpenAI API client when constructing the `generate_test_cases_node`.

### 3. Update Test Generation Node Logging
**File:** `autograder-ai/src/autograder_ai/workflows/nodes/test_generation.py`
- Update the `generate_test_cases_node` to log the usage of the local Qwen model. For example, logging `[LOCAL MODEL - Qwen]` to match the evaluation module's logging style.

### 4. Verify Output Parsing & Consistency
**File:** `autograder-ai/src/autograder_ai/workflows/nodes/test_generation.py`
- Ensure that the JSON extraction logic (`extract_json`) correctly handles any quirks in Qwen's output format.
- The output format must remain strictly identical to what the API key setup produced to avoid breaking downstream nodes.