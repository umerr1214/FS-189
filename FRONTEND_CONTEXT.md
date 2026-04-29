# Frontend Context — EvalBright

> **Purpose of this file:** LLM context injection document. Read this before making any changes to the `evalbright-frontend/` directory. It describes the tech stack, component tree, routing, state management, API interaction patterns, and where specific features live.

---

## What This System Does

EvalBright is a web application that serves as the interface layer on top of the `autograder-ai` grading pipeline. It supports three user roles:

- **Students** — submit code files for assignments and view their feedback reports.
- **Instructors** — view student submissions and trigger the autograder to evaluate them.
- **Admins** — manage users, assignments, and system settings.

Authentication is JWT-based. All API calls go through the Express.js backend, which sits between the React frontend and the PostgreSQL database (and calls out to the Python autograder when triggered).

---

## Directory Structure

```
evalbright-frontend/
├── Backend/                        # Express.js API server
│   └── src/
│       ├── app.js                  # Express app setup, middleware registration
│       ├── server.js               # HTTP server entry point
│       ├── config/
│       │   ├── db.js               # PostgreSQL connection pool (pg)
│       │   └── initSchema.js       # Creates tables on startup if they don't exist
│       ├── controllers/            # Business logic, one file per domain
│       │   ├── auth_controller.js
│       │   ├── submission_controller.js
│       │   ├── evaluation_controller.js
│       │   ├── feedback_controller.js
│       │   ├── instructor_controller.js
│       │   └── admin_controller.js
│       ├── middleware/
│       │   ├── auth_middleware.js  # JWT decode + attach user to req
│       │   ├── error_middleware.js # Global error handler
│       │   └── upload_middleware.js# Multer config for code file uploads
│       └── routes/
│           ├── auth_router.js
│           ├── submission_router.js
│           ├── evaluation_router.js
│           ├── feedback_router.js
│           ├── instructor_router.js
│           └── admin_router.js
│
└── frontend/                       # React (Vite) SPA
    ├── src/
    │   ├── App.tsx                 # Root component — router configuration
    │   ├── pages/
    │   │   ├── Landing.tsx
    │   │   ├── Login.tsx
    │   │   ├── Register.tsx
    │   │   ├── StudentDashboard.tsx
    │   │   ├── InstructorDashboard.tsx
    │   │   ├── AdminDashboard.tsx
    │   │   ├── FeedbackReport.tsx
    │   │   ├── Assignments.tsx
    │   │   ├── AssignmentDetails.tsx
    │   │   └── NotFound.tsx
    │   └── components/
    │       ├── Navigation.tsx
    │       ├── ProtectedRoute.tsx
    │       └── ui/                 # Radix UI primitive wrappers
    ├── package.json
    ├── vite.config.ts
    ├── tailwind.config.js
    └── tsconfig.json
```

---

## Tech Stack

### Express.js Backend
| Package | Purpose |
|---|---|
| `express` ^5.2.1 | HTTP framework |
| `jsonwebtoken` ^9.0.3 | JWT sign/verify |
| `bcryptjs` ^3.0.3 | Password hashing |
| `pg` ^8.20.0 | PostgreSQL client |
| `multer` ^2.1.1 | Multipart file upload handling |
| `axios` ^1.15.1 | Outbound HTTP (calls autograder-ai) |
| `cors` ^2.8.6 | Cross-origin headers |
| `dotenv` ^17.4.2 | Environment variables |

### React Frontend (Vite)
| Package | Purpose |
|---|---|
| `react` ^18.3.1 | UI framework |
| `react-router-dom` ^6.30.1 | Client-side routing |
| `@tanstack/react-query` ^5.83.0 | Server state caching and fetching |
| `axios` ^1.15.1 | HTTP calls to Express backend |
| `react-hook-form` ^7.61.1 | Form state management |
| `zod` ^3.25.76 | Schema validation (used with react-hook-form) |
| `@radix-ui/*` | Headless accessible component primitives |
| `tailwindcss` ^3.4.17 | Utility-first CSS |
| `recharts` ^2.15.4 | Data visualization charts |
| `lucide-react` | Icon set |

---

## Routing

All routes are defined in [frontend/src/App.tsx](evalbright-frontend/frontend/src/App.tsx).

| Path | Component | Access |
|---|---|---|
| `/` | `Landing` | Public |
| `/login` | `Login` | Public |
| `/register` | `Register` | Public |
| `/dashboard/student` | `StudentDashboard` | Protected — student |
| `/dashboard/instructor` | `InstructorDashboard` | Protected — instructor |
| `/dashboard/admin` | `AdminDashboard` | Protected — admin |
| `/feedback/:submissionId` | `FeedbackReport` | Protected |
| `/assignments` | `Assignments` | Protected |
| `/assignments/:assignmentId` | `AssignmentDetails` | Protected |
| `*` | `NotFound` | — |

**`ProtectedRoute`** wraps any route that requires authentication. It reads the JWT token from storage, and if absent or expired, redirects to `/login`.

---

## Pages and Their Responsibilities

### `Landing.tsx`
Public marketing/info page. No API calls. Entry point for unauthenticated users.

### `Login.tsx` / `Register.tsx`
Forms managed by `react-hook-form` + `zod`. On submit, call `POST /api/auth/login` or `POST /api/auth/register`. On success, store JWT and redirect to the appropriate dashboard based on the role in the token payload.

### `StudentDashboard.tsx`
- Lists the student's submissions via `GET /api/submissions/my`.
- Shows submission status (pending, evaluated).
- Links to `FeedbackReport` for evaluated submissions.
- May include summary stats from `GET /api/submissions/stats`.

### `InstructorDashboard.tsx`
- Lists all student submissions for the instructor's assignments.
- Provides a button to trigger evaluation: `POST /api/evaluations/:submissionId/trigger`.
- Shows evaluation status.

### `AdminDashboard.tsx`
- User management and system-level operations.
- Calls admin-specific endpoints under `/admin`.

### `FeedbackReport.tsx`
- Fetches detailed evaluation results via `GET /api/feedback/:submissionId`.
- Displays: correctness status, code quality scores, partial credit info, and the LLM-generated feedback paragraph.
- Likely uses `recharts` for score visualization.

### `Assignments.tsx` / `AssignmentDetails.tsx`
- `Assignments`: lists available assignments via `GET /api/submissions/assignments`.
- `AssignmentDetails`: shows a single assignment, allows downloading the PDF (`GET /api/submissions/assignments/:assignmentId/pdf`), and provides a file upload form to submit code.

---

## State Management

### Server State — TanStack React Query
All API data is managed through React Query. Standard pattern:

```typescript
const { data, isLoading, error } = useQuery({
  queryKey: ['submissions', 'my'],
  queryFn: () => axios.get('/api/submissions/my').then(r => r.data)
});
```

Mutations (POST/trigger actions) use `useMutation`. React Query handles caching, background refetching, and loading/error states — do not introduce `useState` + `useEffect` for server data.

### Form State — React Hook Form + Zod
All forms use `react-hook-form` with `zodResolver`. Validation schemas live alongside the form component. Pattern:

```typescript
const schema = z.object({ email: z.string().email(), password: z.string().min(8) });
const { register, handleSubmit, formState } = useForm({ resolver: zodResolver(schema) });
```

### Auth State
JWT token is stored (likely `localStorage` or `sessionStorage`). The `ProtectedRoute` component and Axios interceptors both read from this storage. If the backend returns `401`, the interceptor should redirect to `/login` and clear the stored token.

---

## API Interaction Pattern

All requests from the React frontend go to the Express backend at `http://localhost:<BACKEND_PORT>`. Axios is configured with a base URL and an interceptor that attaches the `Authorization: Bearer <token>` header to every request automatically.

File uploads (code submissions) use `multipart/form-data` with the field name `code_files` (array, up to 20 files). The Multer middleware on the backend handles parsing.

---

## Authentication Flow

```
User submits login form
  → POST /api/auth/login  {email, password}
  ← 200 {token: "eyJ…", user: {id, role, name}}

Frontend stores token + user role
  → Redirects to /dashboard/{role}

Subsequent requests:
  → Authorization: Bearer eyJ…
  → auth_middleware.js decodes JWT, sets req.user

Protected Express routes:
  → requireRole("instructor") middleware checks req.user.role
```

Token fields expected in payload: `id`, `role` (student | instructor | admin), `name`.

---

## Database Schema (PostgreSQL)

Schema is initialized by [Backend/src/config/initSchema.js](evalbright-frontend/Backend/src/config/initSchema.js) on server startup. Core tables (inferred from controllers):

| Table | Key Columns |
|---|---|
| `users` | `id`, `email`, `password_hash`, `role`, `name` |
| `assignments` | `id`, `title`, `pdf_path`, `created_by` |
| `submissions` | `id`, `user_id`, `assignment_id`, `file_paths`, `status`, `submitted_at` |
| `evaluations` | `id`, `submission_id`, `triggered_by`, `status`, `created_at` |
| `feedback` | `id`, `evaluation_id`, `question_id`, `correctness`, `code_quality`, `score`, `feedback_text` |

---

## Environment Variables (Backend `.env`)

```
DATABASE_URL=postgresql://user:password@localhost:5432/evalbright
JWT_SECRET=<long-random-string>
CORS_ORIGINS=http://localhost:5173,http://localhost:8080
AUTOGRADER_API_URL=http://localhost:<autograder-port>   # If autograder exposes HTTP
PORT=3000
```

---

## Development Setup

```bash
# Backend
cd evalbright-frontend/Backend
npm install
cp .env.example .env    # Fill in DB and JWT vars
npm run dev             # Starts Express with nodemon

# Frontend
cd evalbright-frontend/frontend
npm install
npm run dev             # Starts Vite dev server at http://localhost:5173
```

The Vite dev server proxies `/api` requests to the Express backend (see `vite.config.ts` proxy setting).

---

## Where to Make Common Changes

| Task | File(s) to Edit |
|---|---|
| Add a new page | Create `pages/NewPage.tsx`, add route in `App.tsx` |
| Add a new API endpoint | Add route in `routes/`, add controller in `controllers/`, register in `app.js` |
| Change JWT payload fields | `auth_controller.js` (sign) + `auth_middleware.js` (decode) |
| Change file upload limits | `middleware/upload_middleware.js` (Multer config) |
| Add a new form | Use `react-hook-form` + `zod` schema, call `useMutation` for submission |
| Add a chart/visualization | `recharts` is already installed; add in the relevant page component |
| Change database schema | Edit `config/initSchema.js` — add `ALTER TABLE` or drop/recreate logic |
| Change CORS allowed origins | Backend `.env` `CORS_ORIGINS` variable |
| Change protected route logic | `components/ProtectedRoute.tsx` |

---

## Maintenance Note

**Keep this file updated whenever:**
- A new page or route is added.
- A new API endpoint is created or an existing one changes its path, method, or request/response shape.
- Authentication or authorization logic changes (new roles, new token fields, session handling).
- The database schema changes (new tables, columns, or relationships).
- A new npm package is added that affects architecture (new state management library, new component library, etc.).
- The Vite proxy configuration or backend port changes.
- File upload behavior changes (allowed file types, size limits, field names).

**How to update:** Edit the relevant section above. The routing table, API interaction pattern, and "Where to Make Common Changes" sections are most likely to go stale — prioritize keeping those current.
