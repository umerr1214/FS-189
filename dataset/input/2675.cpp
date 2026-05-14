#include <iostream>
#include <cmath> // Required for sqrt

class Point2D {
private:
    int x;
    int y;

public:
    // Parameterized constructor
    Point2D(int valX, int valY) : x(valX), y(valY) {}

    // Public method to calculate Euclidean distance to origin
    double getDistanceToOrigin() {
        // LOGICAL ERROR: Returns the squared Euclidean distance instead of the distance itself.
        // The sqrt function is missing.
        return static_cast<double>(x) * x + static_cast<double>(y) * y;
    }
};

int main() {
    // Test cases for Point2D class
    Point2D p1(3, 4);
    std::cout << "Distance for (3, 4): " << p1.getDistanceToOrigin() << std::endl; // Expected: 5.0 (Buggy output: 25.0)

    Point2D p2(0, 0);
    std::cout << "Distance for (0, 0): " << p2.getDistanceToOrigin() << std::endl; // Expected: 0.0 (Buggy output: 0.0)

    Point2D p3(-3, -4);
    std::cout << "Distance for (-3, -4): " << p3.getDistanceToOrigin() << std::endl; // Expected: 5.0 (Buggy output: 25.0)

    Point2D p4(5, 12);
    std::cout << "Distance for (5, 12): " << p4.getDistanceToOrigin() << std::endl; // Expected: 13.0 (Buggy output: 169.0)

    Point2D p5(1, 0);
    std::cout << "Distance for (1, 0): " << p5.getDistanceToOrigin() << std::endl; // Expected: 1.0 (Buggy output: 1.0)

    return 0;
}