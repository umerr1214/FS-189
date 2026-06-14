# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

**EvalBright** is an automated programming assignment grader. Students submit code; an LLM pipeline generates tests, executes them, and evaluates quality. Three separate services must run together:

1. **`autograder-ai/`** — Python 3.13 pipeline (LangGraph + local HuggingFace models + OpenAI)
2. **`evalbright-frontend/Backend/`** — Express.js REST API (Node.js, PostgreSQL, JWT auth)
3. **`evalbright-frontend/frontend/`** — React 18 + Vite SPA (TypeScript, Tailwind, React Query)

## Commands

### autograder-ai (Python)

```bash
cd autograder-ai

# First-time setup
python -m venv .venv
.venv\Scripts\activate          # Windows
pip install poetry && poetry install

# Run grader
python main.py --assignment path/to/assignment.pdf --submission path/to/submission/

# Run tests
python -m unittest discover -s tests

# Fine-tune Qwen (run from autograder-ai/)
python finetune_qwen.py

# Docker
docker-compose build
docker-compose up               # reads ./input/, writes to ./output/
```

Required `.env` (copy from `.env.example`):
```
OPENAI_API_KEY=...
OPENAI_MODEL_NAME=gpt-4o-mini
HF_MODEL_NAME=meta-llama/Llama-3.2-3B-Instruct
QWEN_MODEL_NAME=Qwen/Qwen2.5-Coder-7B-Instruct
QWEN_MAX_NEW_TOKENS=2048
QWEN_ADAPTER_PATH=./fine_tuned_adapter   # omit or leave blank to use base model only
```

### Backend (Express.js)

```bash
cd evalbright-frontend/Backend
npm install
npm run dev     # nodemon, port 3001
npm start       # production
```

Required `.env`:
```
DATABASE_URL=postgresql://user:pass@localhost:5432/evalbright
JWT_SECRET=...
CORS_ORIGINS=http://localhost:5173
PORT=3001
AUTOGRADER_PATH=/path/to/autograder-ai
```

### Frontend (React + Vite)

```bash
cd evalbright-frontend/frontend
npm install
npm run dev     # Vite dev server on http://localhost:8080
npm run build   # production bundle to dist/
npm run lint    # ESLint
npm run preview # preview production build
```

The Vite dev server proxies `/api` → `http://localhost:3001`.

## Architecture

### Request lifecycle (submission → grade)

1. Student uploads `q_1.py`, `q_2.py`, … via `POST /api/submissions`
2. Multer saves files to disk; Express creates a `pending` submission record in PostgreSQL
3. Instructor triggers `POST /api/evaluations/:submissionId/trigger`
4. `evaluation_controller.js` spawns `python main.py --assignment <pdf> --submission <dir>` as a child process
5. autograder-ai runs three sequential LangGraph workflows; outputs JSON to stdout
6. Controller parses the JSON and writes results to `evaluations` + `feedback` tables
7. Frontend polls for `evaluated` status and renders `FeedbackReport.tsx`

### autograder-ai pipeline (three LangGraph workflows)

| Workflow | File | LLM | Output |
|---|---|---|---|
| Test generation | `workflows/builders/test_generation.py` | Qwen 2.5-Coder 7B (local, 4-bit) + optional QLoRA adapter | 8–15 test cases per question; malformed JSON is recovered via object salvage then a repair prompt |
| Test execution | `workflows/builders/test_execution.py` | GPT-4o-mini (OpenAI, ReAct agent with ShellTool) | pass/fail + actual output per test |
| Evaluation | `workflows/builders/evaluation.py` | LLaMA 3.2 3B (local, 4-bit) | correctness, quality scores, feedback |

`EvaluationEngine` (`engine.py`) orchestrates all three phases. State types are TypedDicts in each workflow builder.

Test execution runs student code via stdin: `echo "{input}" | python {code_file}`. The agent response is parsed for `RESULT: PASSED/FAILED`, `ACTUAL OUTPUT:`, and `REASONING:`.

### Backend structure

- `src/app.js` — Express setup and route mounting
- `src/server.js` — entry point; calls `initSchema.js` to create tables on startup
- `src/config/db.js` — `pg` connection pool
- Route → Controller → DB pattern; controllers are named `*_controller.js`
- `auth_middleware.js` decodes JWT and attaches user to `req`
- `upload_middleware.js` configures Multer

### Frontend structure

- `App.tsx` — all routes; protected routes wrapped in `<ProtectedRoute>`
- Server state via **React Query** (`useQuery`/`useMutation`)
- Form state via **react-hook-form** + **zod** validation
- JWT stored in localStorage; Axios interceptor attaches it to every request on 401 it clears storage
- Path alias `@/` → `./src/`

### Database tables

`users`, `assignments`, `assignment_documents`, `submissions`, `evaluations`, `feedback`, `rubrics`, `user_sessions` — all auto-created by `initSchema.js` at backend startup.

## Key Constraints

- **Assignment PDFs** must label questions as `Q1:`, `Q2:`, etc. for the regex extractor to find them (`core/pre_processors/assignment.py`).
- **Student submission files** must match the glob `q_*.py` (`core/pre_processors/submission.py`).
- The folder `core/file_hanlders/` has a deliberate typo — do not rename it.
- HuggingFace models require a CUDA-capable GPU and are loaded via `bitsandbytes` through `HuggingFaceClient` (`clients/huggingface_client.py`). Both Qwen and LLaMA use 4-bit quantization (`max_new_tokens=2048` and `500` respectively). Both models load eagerly on `EvaluationEngine` startup (~10–11 GB VRAM combined).
- The fine-tuned Qwen adapter may produce test case `input` fields as plain strings instead of dicts; `_format_input_for_stdin` and `is_valid_test_case` both accept `str | dict` to handle this.
- The backend and frontend have no automated test suite. `autograder-ai` has unit tests in `autograder-ai/tests/` covering `json_helpers` and `generate_test_cases_node` (run with `python -m unittest discover -s tests` from inside `autograder-ai/`).

## Dataset

`dataset/` holds a fine-tuning dataset for Qwen (~1,200 C++ problems):
- `dataset/input/` — buggy C++ student submissions (numbered e.g. `601.cpp`, `1000.cpp`, …). Files are grouped in sets of 6 consecutive numbers; each group represents one question with 6 variants, where index 5 (0-based) is the correct version.
- `dataset/output/` — corresponding JSON per file with fields: `language`, `question`, `test_cases` (array of `{input, expected}` pairs), `driver` (C++ harness that `#include`s the submission), `code_quality` (int), `correctness` (int), `error_type` (e.g. `"Syntax Error"`, `"Logical Error"`), `errors` (array of strings)
- `dataset/prepare_dataset.py` — preprocessing script; groups files by 6, pools test cases from all variants, and writes a 90/10 train/val split. Run from repo root: `python dataset/prepare_dataset.py`
- `dataset/train.jsonl` / `dataset/val.jsonl` — Qwen chat-format JSONL produced by the above script (`messages`: system + user(question+code) + assistant(JSON test cases))

### Fine-tuned adapter

`autograder-ai/fine_tuned_adapter/` contains a QLoRA adapter trained on the EvalBright dataset:
- Base model: `Qwen/Qwen2.5-Coder-7B-Instruct`
- Config: rank=16, alpha=32, dropout=0.05, 5 epochs, all projection layers targeted
- Trained with `peft` + `trl` (SFTTrainer); adapter weights stored via Git LFS
- **Integrated into the main pipeline** — `EvaluationEngine` reads `QWEN_ADAPTER_PATH` from the environment and passes it to `HuggingFaceClient`, which calls `peft.PeftModel.from_pretrained(base_model, adapter_path)` after loading the base model. Set `QWEN_ADAPTER_PATH=./fine_tuned_adapter` (default in `.env.example`) to enable it; leave the variable unset or empty to use the base model only.
- Fine-tuning script: `autograder-ai/finetune_qwen.py` (requires `peft`, `trl`, `datasets` — all declared in `pyproject.toml`)

## Useful Context Docs

Three comprehensive markdown files explain the system in depth:
- `BACKEND_CONTEXT.md` — autograder-ai architecture & modules
- `FRONTEND_CONTEXT.md` — React/Express stack details
- `SYSTEM_INTEGRATION_CONTEXT.md` — end-to-end API contracts & deployment notes
- `autograder-ai/LEARNING_PATH.md` — guided reading order (19 files, 7 phases)
