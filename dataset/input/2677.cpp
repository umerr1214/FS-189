#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath> // For std::sqrt
#include <iomanip> // For std::fixed, std::setprecision

class Point2D {
private:
    int x;
    int y;

public:
    // Parameterized constructor
    Point2D(int initialX, int initialY) : x(initialX), y(initialY) {}

    // Public method to get x (for driver)
    int getX() const {
        return x;
    }

    // Public method to get y (for driver)
    int getY() const {
        return y;
    }

    // Calculates and returns the Euclidean distance from the point to (0,0)
    // Robustness Issue: Integer overflow for large coordinates
    double getDistanceToOrigin() {
        // For very large x or y, x*x or y*y can exceed INT_MAX, leading to overflow
        // The sum x*x + y*y can also overflow even if individual squares don't.
        // This will result in an incorrect sum_sq value before passing to sqrt.
        int x_squared = x * x;
        int y_squared = y * y;
        int sum_of_squares = x_squared + y_squared; // Potential overflow here
        return std::sqrt(static_cast<double>(sum_of_squares));
    }
};

int main() {
    std::vector<Point2D> points = {
        Point2D(0, 0),
        Point2D(3, 4),
        Point2D(5, 12),
        Point2D(1, 1),
        Point2D(-3, -4) // Test with negative coordinates
    };

    std::cout << "--- Testing various points ---\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << "Point " << i + 1 << ": (" << points[i].getX() << ", " << points[i].getY() << ")\n";
        std::cout << "Distance to origin: " << std::fixed << std::setprecision(8) << points[i].getDistanceToOrigin() << "\n\n";
    }

    // Test case demonstrating the robustness issue (integer overflow)
    // 50000 * 50000 = 2,500,000,000, which overflows a 32-bit signed int (max approx 2.1 * 10^9)
    Point2D large_point(50000, 50000);
    std::cout << "--- Testing point with large coordinates (potential overflow) ---\n";
    std::cout << "Point: (" << large_point.getX() << ", " << large_point.getY() << ")\n";
    std::cout << "Distance to origin (incorrect due to overflow): " << std::fixed << std::setprecision(8) << large_point.getDistanceToOrigin() << "\n\n";

    return 0;
}