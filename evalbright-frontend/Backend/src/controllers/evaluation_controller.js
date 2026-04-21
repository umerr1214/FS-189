const axios = require("axios");
const path = require("path");
const { pool } = require("../config/db");

async function persistFeedback(submissionId, feedbackText, generatedBy) {
  const updated = await pool.query(
    `UPDATE feedback
     SET feedback_text = $1, generated_by = $2, created_at = NOW()
     WHERE submission_id = $3`,
    [feedbackText, generatedBy, submissionId],
  );

  if (updated.rowCount > 0) {
    return;
  }

  await pool.query(
    `INSERT INTO feedback (submission_id, feedback_text, generated_by)
     VALUES ($1, $2, $3)`,
    [submissionId, feedbackText, generatedBy],
  );
}

async function triggerEvaluationForSubmission(submissionId) {
  try {
    const submissionResult = await pool.query(
      `SELECT
         s.submission_id,
         s.file_path,
         s.language,
         s.assignment_id,
         ad.file_path AS assignment_pdf_path
       FROM submissions s
       LEFT JOIN assignment_documents ad ON ad.assignment_id = s.assignment_id
       WHERE s.submission_id = $1`,
      [submissionId],
    );

    if (!submissionResult.rows.length) {
      throw new Error("Submission not found");
    }

    const submission = submissionResult.rows[0];
    let parsedFilePaths = [];
    try {
      parsedFilePaths = JSON.parse(submission.file_path);
      if (!Array.isArray(parsedFilePaths)) parsedFilePaths = [];
    } catch (_error) {
      parsedFilePaths = [];
    }
    const rawFilePaths = parsedFilePaths.length ? parsedFilePaths : [submission.file_path];
    const filePaths = rawFilePaths.map((p) => path.resolve(String(p)));
    const assignmentPdfPath = submission.assignment_pdf_path
      ? path.resolve(String(submission.assignment_pdf_path))
      : null;
    const serviceBaseURL = process.env.LANGGRAPH_SERVICE_URL || "http://localhost:8000";
    const endpoint = `${serviceBaseURL}/evaluate`;

    let serviceData = {};
    let evaluationSucceeded = false;
    try {
      const response = await axios.post(endpoint, {
        submission_id: submission.submission_id,
        assignment_id: submission.assignment_id,
        assignment_pdf_path: assignmentPdfPath,
        file_path: filePaths[0],
        file_paths: filePaths,
        language: submission.language,
      });
      serviceData = response.data || {};
      evaluationSucceeded = true;
    } catch (serviceError) {
      serviceData = {
        feedback_text: `Evaluation service unavailable. ${serviceError?.message || ""}`.trim(),
      };
    }

    const fullReportText =
      serviceData.feedback_text ||
      serviceData.report ||
      serviceData.feedback ||
      "No evaluation report was returned.";

    await persistFeedback(submission.submission_id, fullReportText, "AI");

    await pool.query(
      "UPDATE submissions SET status = $1 WHERE submission_id = $2",
      [evaluationSucceeded ? "Evaluated" : "Error", submission.submission_id],
    );
  } catch (error) {
    // Never rethrow from failure handler; ensure we keep error visibility.
    // eslint-disable-next-line no-console
    console.error("Evaluation pipeline failed:", error);

    try {
      await persistFeedback(submissionId, `Evaluation pipeline error: ${error?.message || "Unknown error"}`, "AI");
    } catch (persistErr) {
      // eslint-disable-next-line no-console
      console.error("Failed to persist feedback row:", persistErr);
    }

    try {
      await pool.query("UPDATE submissions SET status = 'Error' WHERE submission_id = $1", [submissionId]);
    } catch (statusErr) {
      // eslint-disable-next-line no-console
      console.error("Failed to set submission status Error:", statusErr);
    }
  }
}

async function triggerEvaluation(req, res) {
  const submissionId = Number(req.params.submissionId);
  if (!submissionId) {
    return res.status(400).json({ success: false, message: "Invalid submission id" });
  }

  await triggerEvaluationForSubmission(submissionId);
  return res.json({ success: true, submissionId, message: "Evaluation completed" });
}

module.exports = { triggerEvaluation, triggerEvaluationForSubmission };
