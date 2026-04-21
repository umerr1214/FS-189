const express = require("express");
const { triggerEvaluation } = require("../controllers/evaluation_controller");
const { authenticateJWT, requireRole } = require("../middleware/auth_middleware");

const router = express.Router();

router.post("/:submissionId/trigger", authenticateJWT, requireRole("instructor"), triggerEvaluation);

module.exports = router;
