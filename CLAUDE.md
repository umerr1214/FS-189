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

# Docker
docker-compose build
docker-compose up               # reads ./input/, writes to ./output/
```

Required `.env` (copy from `.env.example`):
```
OPENAI_API_KEY=...
OPENAI_MODEL_NAME=gpt-4o-mini
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
| Test generation | `workflows/builders/test_generation.py` | Qwen 2.5-Coder 7B (local, 4-bit) | 8–15 test cases per question |
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
- HuggingFace models (Qwen, LLaMA) are loaded with 4-bit quantization via `bitsandbytes`; they require a CUDA-capable GPU. `HuggingFaceClient` (`clients/huggingface_client.py`) handles loading.
- No automated test suite exists for any of the three services.

## Useful Context Docs

Three comprehensive markdown files explain the system in depth:
- `BACKEND_CONTEXT.md` — autograder-ai architecture & modules
- `FRONTEND_CONTEXT.md` — React/Express stack details
- `SYSTEM_INTEGRATION_CONTEXT.md` — end-to-end API contracts & deployment notes
- `autograder-ai/LEARNING_PATH.md` — guided reading order (19 files, 7 phases)
