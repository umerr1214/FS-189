#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath> // For std::sqrt and std::pow
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
    // Readability / Efficiency Issue: Using std::pow for squaring and missing const
    double getDistanceToOrigin() { // Missing const keyword
        // Convert integer coordinates to double for std::pow function
        double dx = x;
        double dy = y;

        // Using std::pow(value, 2) is less efficient than value * value for squaring
        // It also can be less readable for simple integer squaring.
        double distance_squared = std::pow(dx, 2) + std::pow(dy, 2);

        // Calculate the square root to get the final Euclidean distance
        return std::sqrt(distance_squared);
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

    // This point will work correctly because std::pow operates on doubles
    // preventing the integer overflow seen in the robustness example.
    Point2D large_point(50000, 50000);
    std::cout << "--- Testing point with large coordinates (correct result) ---\n";
    std::cout << "Point: (" << large_point.getX() << ", " << large_point.getY() << ")\n";
    std::cout << "Distance to origin: " << std::fixed << std::setprecision(8) << large_point.getDistanceToOrigin() << "\n\n";

    return 0;
}