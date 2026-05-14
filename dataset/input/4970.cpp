#include <iostream>
#include <cmath> // For std::fmod
#include <vector>
#include <iomanip>

void normalizeAngle(double& angle) {
    // This implementation is correct but has a minor efficiency issue
    // for large negative angles and is less readable than a more concise approach.
    if (angle < 0.0) {
        // For negative angles, repeatedly add 360 until it's non-negative.
        // This 'while' loop is less efficient than directly using fmod and
        // then adjusting the result once if negative. For example, -700.0
        // would require two additions (to -340.0, then to 20.0).
        while (angle < 0.0) {
            angle += 360.0;
        }
        // After the loop, angle is in [0, 360), [360, 720), etc.
        // Now apply fmod to bring it into the final [0, 360) range.
        angle = std::fmod(angle, 360.0);
    } else {
        // For non-negative angles, a direct fmod is efficient.
        angle = std::fmod(angle, 360.0);
    }
    // The conditional structure and the while loop for negative numbers
    // make this less efficient and less readable than the optimal solution,
    // which handles both positive and negative cases more uniformly.
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