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
    // Parameterized constructor to initialize x and y
    Point2D(int initialX, int initialY) : x(initialX), y(initialY) {}

    // Public const method to get x (for driver and good practice)
    int getX() const {
        return x;
    }

    // Public const method to get y (for driver and good practice)
    int getY() const {
        return y;
    }

    // Calculates and returns the Euclidean distance from the point to (0,0)
    // Marked as const as it does not modify the object's state.
    // Uses long long for intermediate calculations to prevent integer overflow.
    double getDistanceToOrigin() const {
        // Use long long for intermediate calculations to prevent overflow
        // when squaring potentially large integer coordinates.
        long long x_ll = x;
        long long y_ll = y;
        long long sum_of_squares = x_ll * x_ll + y_ll * y_ll;
        
        // Cast the sum to double before taking the square root for precision
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

    // Test case with large coordinates to ensure robustness against overflow
    Point2D large_point(50000, 50000);
    std::cout << "--- Testing point with large coordinates (correct result) ---\n";
    std::cout << "Point: (" << large_point.getX() << ", " << large_point.getY() << ")\n";
    std::cout << "Distance to origin: " << std::fixed << std::setprecision(8) << large_point.getDistanceToOrigin() << "\n\n";

    return 0;
}