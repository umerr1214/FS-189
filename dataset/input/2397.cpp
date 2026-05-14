#include <iostream>
#include <cmath> // For M_PI
#include <algorithm> // For std::max

// Define M_PI if not defined (e.g., on MSVC without specific flags)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Circle {
private:
    double radius; // Encapsulate radius as private

public:
    // Default constructor using member initializer list
    Circle() : radius(0.0) {
        // Body can be empty as initialization is done in the initializer list
    }

    // Parameterized constructor using member initializer list
    // 'explicit' keyword prevents unintended implicit conversions.
    // Input validation for radius (good practice for robustness).
    explicit Circle(double r) : radius(std::max(0.0, r)) { // Ensures radius is non-negative
        // Body can be empty
    }

    // Copy constructor using member initializer list and const reference
    Circle(const Circle& other) : radius(other.radius) {
        // Body can be empty
    }

    // Getter for radius
    double getRadius() const {
        return radius;
    }

    // Method to calculate area
    double getArea() const {
        return M_PI * radius * radius;
    }
};

int main() {
    std::cout.precision(10); // Set precision for output
    std::cout << std::fixed;

    // Test default constructor
    Circle c1;
    std::cout << "Circle c1 (default): Radius = " << c1.getRadius() << ", Area = " << c1.getArea() << std::endl;

    // Test parameterized constructor with valid input
    Circle c2(5.0);
    std::cout << "Circle c2 (param 5.0): Radius = " << c2.getRadius() << ", Area = " << c2.getArea() << std::endl;

    // Test parameterized constructor with negative input (should be handled robustly by clamping to 0.0)
    Circle c3(-3.0);
    std::cout << "Circle c3 (param -3.0): Radius = " << c3.getRadius() << ", Area = " << c3.getArea() << std::endl;

    // Test copy constructor (direct initialization)
    Circle c4 = c2;
    std::cout << "Circle c4 (copy of c2): Radius = " << c4.getRadius() << ", Area = " << c4.getArea() << std::endl;

    // Test copy constructor (explicit copy construction)
    Circle c5(c3);
    std::cout << "Circle c5 (copy of c3): Radius = " << c5.getRadius() << ", Area = " << c5.getArea() << std::endl;

    return 0;
}