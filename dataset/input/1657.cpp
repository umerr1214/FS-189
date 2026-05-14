#include <iostream>
#include <cmath> // For std::sqrt

class Vector2D {
private:
    double x;
    double y;

public:
    // Parameterized constructor
    Vector2D(double x_val, double y_val) : x(x_val), y(y_val) {}

    // Copy constructor (performs member-wise copy, which is a deep copy for primitive doubles)
    Vector2D(const Vector2D& other) : x(other.x), y(other.y) {}

    // Getter for x
    double getX() const {
        return x;
    }

    // Getter for y
    double getY() const {
        return y;
    }

    // Method to normalize the vector - ROBUSTNESS ISSUE: No check for zero magnitude
    void normalize() {
        double magnitude = std::sqrt(x * x + y * y);
        // Robustness Issue: If magnitude is 0, this will result in division by zero,
        // leading to NaN (Not a Number) or Inf (Infinity) values for x and y,
        // or potentially a runtime error depending on compiler/platform.
        x /= magnitude;
        y /= magnitude;
    }

    // Utility method to print the vector
    void print() const {
        std::cout.precision(2);
        std::cout << std::fixed << "(" << x << ", " << y << ")";
    }
};

int main() {
    // Test parameterized constructor
    Vector2D v1(3.0, 4.0);
    std::cout << "Original vector v1: ";
    v1.print();
    std::cout << std::endl;

    // Test copy constructor
    Vector2D v2 = v1; // Uses copy constructor
    std::cout << "Copied vector v2 (from v1): ";
    v2.print();
    std::cout << std::endl;

    // Demonstrate robustness issue: normalizing a zero vector
    Vector2D v_zero(0.0, 0.0);
    std::cout << "Vector v_zero: ";
    v_zero.print();
    std::cout << std::endl;

    std::cout << "Attempting to normalize v_zero (0.0, 0.0)..." << std::endl;
    // Calling normalize on a zero vector will cause division by zero.
    // The output will likely be (nan, nan) or similar.
    v_zero.normalize();
    std::cout << "Normalized v_zero: ";
    v_zero.print();
    std::cout << std::endl;

    // Normalizing v1 (should work correctly)
    std::cout << "Normalizing v1..." << std::endl;
    v1.normalize();
    std::cout << "Normalized v1: ";
    v1.print();
    std::cout << std::endl;

    return 0;
}