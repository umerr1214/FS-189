#include <iostream>
#include <cmath> // Not strictly needed for this implementation, but good practice

void normalizeAngle(double& angle) {
    // This implementation uses repeated addition/subtraction in while loops.
    // While logically correct for typical angles, it is highly inefficient
    // for very large positive or negative input angles (e.g., 1e9 or -1e9).
    // For such inputs, it will perform millions of iterations, leading to
    // significant performance degradation and potential timeouts, which is
    // considered a robustness issue for valid but extreme inputs.
    while (angle >= 360.0) {
        angle -= 360.0;
    }
    while (angle < 0.0) {
        angle += 360.0;
    }
}

int main() {
    std::vector<double> test_angles = {
        10.0, 360.0, 370.0, -10.0, -360.0, -370.0, 720.0, 0.0,
        180.0, 540.0, -180.0, -540.0,
        1000000000.0, -1000000000.0, // Extreme values to highlight inefficiency
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