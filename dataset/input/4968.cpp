#include <cmath>

// Semantic error: The angle is passed by value, not by reference.
// Although the function's internal logic correctly normalizes the 'angle' parameter,
// this modification is applied only to a local copy.
// The original variable passed from the caller (e.g., in main) will remain unchanged,
// violating the requirement to "modify it" (the original variable).
void normalizeAngle(double angle) { // Missing '&' for pass-by-reference
    angle = fmod(angle, 360.0);
    if (angle < 0) {
        angle += 360.0;
    }
}