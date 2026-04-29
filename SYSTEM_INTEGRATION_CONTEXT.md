# System Integration Context — EvalBright

> **Purpose of this file:** LLM context injection document. Read this before making changes that touch the boundary between the React frontend, the Express.js backend, and the Python autograder. It describes how all three components connect, the API contracts, authentication, data flow, and deployment setup.

---

## System Overview

EvalBright consists of three distinct processes that must be running together:

| Component | Language/Runtime | Default Port | Role |
|---|---|---|---|
| `evalbright-frontend/frontend` | React + Vite | 5173 (dev) | Browser UI |
| `evalbright-frontend/Backend` | Express.js / Node.js | 3000 | API gateway + DB |
| `autograder-ai` | Python 3.13 | CLI / subprocess | Grading pipeline |

The React frontend never talks to the Python backend directly. All traffic flows through Express.

```
[Browser / React SPA]
        │  HTTP + JWT
        ▼
[Express.js Backend]
        │  PostgreSQL queries
        ▼
[PostgreSQL Database]

[Express.js Backend]
        │  Subprocess spawn OR HTTP call
        ▼
[autograder-ai Python Pipeline]
        │  Returns results (stdout / HTTP response)
        ▼
[Express.js Backend stores results in PostgreSQL]
```

---

## API Contracts

All endpoints are prefixed with `/api`. The Express backend serves them. The React frontend calls them via Axios with `Authorization: Bearer <JWT>` on every protected request.

### Authentication

#### `POST /api/auth/register`
**Request:**
```json
{ "name": "string", "email": "string", "password": "string", "role": "student|instructor|admin" }
```
**Response `200`:**
```json
{ "token": "eyJ…", "user": { "id": "uuid", "name": "string", "email": "string", "role": "string" } }
```

#### `POST /api/auth/login`
**Request:**
```json
{ "email": "string", "password": "string" }
```
**Response `200`:**
```json
{ "token": "eyJ…", "user": { "id": "uuid", "name": "string", "email": "string", "role": "string" } }
```

**JWT payload fields:** `id`, `role`, `name`. Token is signed with `JWT_SECRET` env var. Expiry should be set in `auth_controller.js`.

---

### Submissions

#### `POST /api/submissions`
Upload code files for an assignment.

**Auth:** Required (student)  
**Content-Type:** `multipart/form-data`  
**Form fields:**
- `assignment_id` — string (UUID of the assignment)
- `code_files` — array of `.py` files (up to 20), file names must follow `q_1.py`, `q_2.py` pattern

**Response `201`:**
```json
{ "submission_id": "uuid", "status": "pending" }
```

#### `GET /api/submissions/my`
**Auth:** Required  
**Response `200`:**
```json
[
  { "id": "uuid", "assignment_id": "uuid", "status": "pending|evaluated", "submitted_at": "ISO8601", "assignment_title": "string" }
]
```

#### `GET /api/submissions/stats`
**Auth:** Required  
**Response `200`:** Aggregate stats (submission count, evaluation count, avg score — shape determined by `submission_controller.js`).

#### `GET /api/submissions/assignments`
**Auth:** Required  
**Response `200`:**
```json
[{ "id": "uuid", "title": "string", "due_date": "ISO8601" }]
```

#### `GET /api/submissions/assignments/:assignmentId`
**Auth:** Required  
**Response `200`:** Single assignment object with full details.

#### `GET /api/submissions/assignments/:assignmentId/pdf`
**Auth:** Required  
**Response:** Binary PDF file stream (`Content-Type: application/pdf`).

---

### Evaluation (Instructor-Only)

#### `POST /api/evaluations/:submissionId/trigger`
Triggers the Python autograder for a specific submission.

**Auth:** Required — role must be `instructor`  
**Response `202`:**
```json
{ "evaluation_id": "uuid", "status": "running" }
```

**What happens on the backend:**
1. `evaluation_controller.js` retrieves the submission's code file paths and the assignment PDF path from the database.
2. Spawns the Python autograder (subprocess or HTTP, see "Autograder Integration" below).
3. When the autograder completes, stores the results in the `evaluations` and `feedback` tables.
4. Updates `submissions.status` to `"evaluated"`.

---

### Feedback

#### `GET /api/feedback/:submissionId`
**Auth:** Required  
**Response `200`:**
```json
{
  "submission_id": "uuid",
  "questions": [
    {
      "question_id": "q_1",
      "correctness": { "status": "fully_correct|partially_correct|incorrect", "explanation": "string", "confidence": 0.95 },
      "code_quality": { "readability": 8, "structure": 7, "best_practices": 9, "efficiency": 6 },
      "partial_credit": { "eligible": true, "suggested_score": 0.7, "reason": "string" },
      "final_score": { "total": 82, "breakdown": {} },
      "feedback": "string (LLM-generated paragraph)"
    }
  ]
}
```

---

### Instructor Routes

`/instructor/*` — Instructor-specific operations (view all submissions for their assignments, manage assignment uploads). Exact shapes defined in `instructor_controller.js`.

### Admin Routes

`/admin/*` — User management, system configuration. Exact shapes defined in `admin_controller.js`.

---

## Autograder Integration

The Express backend calls the Python autograder when an instructor triggers evaluation. There are two possible integration patterns — confirm which is active in `evaluation_controller.js`:

### Pattern A: Subprocess (current most likely)
```javascript
const { spawn } = require('child_process');
const proc = spawn('python', [
  'main.py',
  '--assignment', assignmentPdfPath,
  '--submission', submissionDirPath
], { cwd: '/path/to/autograder-ai' });
```
- Output is captured from `stdout` and parsed.
- This is synchronous from the controller's perspective (awaited via promise wrapper).
- The `AUTOGRADER_PATH` environment variable should point to the `autograder-ai` directory.

### Pattern B: HTTP API (if autograder is wrapped in FastAPI/Flask)
```javascript
const response = await axios.post(process.env.AUTOGRADER_API_URL + '/evaluate', {
  assignment_path: assignmentPdfPath,
  submission_path: submissionDirPath
});
```
- Currently `autograder-ai` has no HTTP server — only `main.py` CLI. Adding an HTTP wrapper would require a new `api.py` entry point.

**To add HTTP API support to autograder-ai:** Create a `FastAPI` or `Flask` app in `autograder-ai/src/autograder_ai/api.py` that exposes `POST /evaluate`, calls `EvaluationEngine.run()`, and returns the report as JSON.

---

## File Storage

Uploaded submission files are stored on the Express server's filesystem (via Multer). The path is stored in `submissions.file_paths` in the database. When triggering the autograder, the backend must pass the directory containing those files.

Assignment PDFs are similarly stored on the filesystem with the path in the `assignments` table.

**Critical constraint:** The Express backend and the autograder-ai process must share filesystem access to the uploaded files. In Docker, this requires a shared volume mount.

---

## CORS Configuration

The Express backend restricts cross-origin requests to origins listed in the `CORS_ORIGINS` environment variable:

```
CORS_ORIGINS=http://localhost:5173,http://localhost:8080
```

In production, this must be updated to the actual frontend domain. The `cors` middleware in `app.js` reads this variable.

---

## Full Request Lifecycle: Student Submits and Gets Feedback

```
1. Student navigates to /assignments/:assignmentId
   → GET /api/submissions/assignments/:assignmentId  (Express → PostgreSQL)

2. Student downloads PDF
   → GET /api/submissions/assignments/:assignmentId/pdf  (Express streams file)

3. Student uploads code files
   → POST /api/submissions  multipart/form-data
   → Multer saves files to disk
   → Express creates submission record (status: "pending") in PostgreSQL
   → Returns {submission_id, status: "pending"}

4. Instructor views InstructorDashboard, sees pending submission
   → GET /instructor/submissions  (Express → PostgreSQL)

5. Instructor clicks "Evaluate"
   → POST /api/evaluations/:submissionId/trigger
   → Express calls autograder-ai with assignment PDF + submission dir
   → autograder-ai runs full pipeline (generate tests → execute → evaluate)
   → Express stores results in evaluations + feedback tables
   → Updates submission status to "evaluated"

6. Student's dashboard shows "evaluated" status
   → GET /api/submissions/my  (Express → PostgreSQL)

7. Student clicks "View Feedback"
   → Navigate to /feedback/:submissionId
   → GET /api/feedback/:submissionId  (Express → PostgreSQL)
   → FeedbackReport.tsx renders scores, quality breakdown, and LLM feedback
```

---

## Environment Variables — Master Reference

### Express Backend (`evalbright-frontend/Backend/.env`)
```
DATABASE_URL=postgresql://user:password@localhost:5432/evalbright
JWT_SECRET=<long-random-string>
CORS_ORIGINS=http://localhost:5173
PORT=3000
AUTOGRADER_PATH=/absolute/path/to/autograder-ai   # Used when spawning subprocess
AUTOGRADER_API_URL=http://localhost:8000           # Used if autograder has HTTP server
```

### autograder-ai (`autograder-ai/.env`)
```
OPENAI_API_KEY=sk-...
OPENAI_MODEL_NAME=gpt-4o-mini
```

### React Frontend
No `.env` at runtime — the Vite dev proxy forwards `/api` to the Express backend. In production, build with `VITE_API_BASE_URL=https://api.yourdomain.com` and configure Axios to use it.

---

## Docker Deployment

`autograder-ai` has its own `docker-compose.yml`:
```yaml
volumes:
  - ./input:/app/input:ro      # Assignment PDF + submission files (read-only)
  - ./output:/app/output:rw    # Grading report output
```

For a full-stack Docker deployment (not yet present in the repo), you would need a `docker-compose.yml` at the repo root with services:
1. `postgres` — database
2. `backend` — Express.js (mounts the uploads volume)
3. `autograder` — Python pipeline (mounts the same uploads volume)
4. `frontend` — Nginx serving the built React SPA + reverse proxy to backend

---

## Where to Make Common Changes

| Task | File(s) to Edit |
|---|---|
| Change how autograder is invoked | `evalbright-frontend/Backend/src/controllers/evaluation_controller.js` |
| Add HTTP API to autograder | Create `autograder-ai/src/autograder_ai/api.py` with FastAPI/Flask |
| Change CORS allowed origins | `evalbright-frontend/Backend/.env` → `CORS_ORIGINS` |
| Change JWT expiration | `evalbright-frontend/Backend/src/controllers/auth_controller.js` |
| Change file upload storage path | `evalbright-frontend/Backend/src/middleware/upload_middleware.js` |
| Add a new API endpoint end-to-end | Backend route → controller → DB query; Frontend React Query hook → UI |
| Add a new user role | Update JWT payload, `requireRole` middleware, `ProtectedRoute`, dashboard routing |
| Connect autograder output to DB | `evaluation_controller.js` — parse autograder output and `INSERT` into `feedback` table |
| Add Docker Compose for full stack | Create root-level `docker-compose.yml` with shared volume for uploaded files |

---

## Maintenance Note

**Keep this file updated whenever:**
- A new API endpoint is added, removed, or its request/response shape changes.
- The method of calling the autograder changes (subprocess → HTTP, or vice versa).
- New environment variables are introduced in either service.
- Authentication logic changes — new roles, new JWT fields, expiry policy.
- File storage strategy changes (local disk → S3, etc.).
- A Docker or deployment configuration is added or changed.
- The data flow through the system changes (e.g., async evaluation via job queue).
- New services are introduced (e.g., a Redis queue, an email service).

**How to update:** Edit the relevant section above. The "Full Request Lifecycle" walkthrough and the API contracts table are the most valuable sections for an LLM — keep them accurate and complete.
