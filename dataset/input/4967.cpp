#include <cmath>

void normalizeAngle(double& angle) {
    // Logical error: This logic only handles positive angles correctly,
    // or angles greater than or equal to 360.
    // It fails to normalize negative angles into the [0, 360) range.
    while (angle >= 360.0) {
        angle -= 360.0;
    }
    // Example: For angle = -90.0, the loop is skipped, and angle remains -90.0.
    // The expected output for -90.0 is 270.0.
}