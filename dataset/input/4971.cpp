#include <iostream>
#include <cmath> // For std::fmod
#include <vector>
#include <iomanip>

void normalizeAngle(double& angle) {
    // Normalize the angle to be within the range [0, 360).
    // std::fmod calculates the floating-point remainder.
    // The sign of the result of std::fmod is the same as the sign of the dividend (first argument).
    angle = std::fmod(angle, 360.0);

    // If the result is negative (which happens for negative input angles),
    // add 360.0 to bring it into the [0, 360) range.
    // This correctly handles all negative input angles.
    if (angle < 0.0) {
        angle += 360.0;
    }
    // Angles that are exact multiples of 360 (e.g., 360, 720, -360) will result in 0.0
    // after fmod, which is correctly within [0, 360).
    // This approach is robust, efficient, and readable.
}

int main() {
    std::vector<double> test_angles = {
        10.0, 360.0, 370.0, -10.0, -360.0, -370.0, 720.0, 0.0,
        180.0, 540.0, -180.0, -540.0,
        1000000000.0, -1000000000.0,
        -0.000000001, 359.999999999
    };

    std::cout << std::fixed << std::setprecision(10);

    for (double angle : test_angles) {
        double original_angle = angle;
        normalizeAngle(angle);
        std::cout << "Original: " << original_angle << ", Normalized: " << angle << std::endl;
    }

    return 0;
}