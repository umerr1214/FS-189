#include <iostream>
#include <cmath> // Required for sqrt
#include <limits> // For numeric_limits

class Point2D {
private:
    int x;
    int y;

public:
    // Parameterized constructor
    Point2D(int valX, int valY) : x(valX), y(valY) {}

    // Public method to calculate Euclidean distance to origin
    double getDistanceToOrigin() {
        // SEMANTIC ERROR: Potential integer overflow before type promotion.
        // x*x and y*y are calculated using integer arithmetic.
        // If x or y are large, x*x or y*y, or their sum (x*x + y*y) can exceed
        // the maximum value for an 'int' before being converted to 'double' for sqrt.
        // This leads to incorrect results due to integer overflow (undefined behavior or wrap-around).
        return sqrt(x*x + y*y); // Should be: sqrt(static_cast<double>(x) * x + static_cast<double>(y) * y);
    }
};

int main() {
    // Test cases for Point2D class
    Point2D p1(3, 4);
    std::cout << "Distance for (3, 4): " << p1.getDistanceToOrigin() << std::endl; // Expected: 5.0 (Correct for small numbers)

    Point2D p2(0, 0);
    std::cout << "Distance for (0, 0): " << p2.getDistanceToOrigin() << std::endl; // Expected: 0.0

    Point2D p3(-3, -4);
    std::cout << "Distance for (-3, -4): " << p3.getDistanceToOrigin() << std::endl; // Expected: 5.0

    // Test case designed to expose the integer overflow semantic error
    // For x = 50000, x*x = 2,500,000,000, which overflows a 32-bit signed int (max ~2.147 billion).
    // The result of x*x will wrap around, becoming a negative number, leading to sqrt(negative) = NaN.
    Point2D p4(50000, 0);
    std::cout << "Distance for (50000, 0): " << p4.getDistanceToOrigin() << std::endl; // Expected: 50000.0 (Buggy output: NaN or other incorrect value)

    Point2D p5(1, 0);
    std::cout << "Distance for (1, 0): " << p5.getDistanceToOrigin() << std::endl; // Expected: 1.0

    return 0;
}