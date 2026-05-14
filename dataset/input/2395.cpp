#include <iostream>
#include <cmath> // For M_PI

// Define M_PI if not defined (e.g., on MSVC without specific flags)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Circle {
public:
    double radius;

    // Default constructor
    Circle() {
        radius = 0.0;
    }

    // Parameterized constructor
    // Robustness issue: Does not validate if r is non-negative.
    // Allows negative radius, which is physically meaningless.
    Circle(double r) {
        radius = r;
    }

    // Copy constructor
    Circle(const Circle& other) {
        radius = other.radius;
    }

    // Getter for radius
    double getRadius() const {
        return radius;
    }

    // A method that might produce misleading results with a negative radius
    double getArea() const {
        // If radius is negative, the area will be calculated as positive,
        // which is mathematically correct for (-r)^2 but physically incorrect
        // for a circle's area. A robust implementation would handle negative
        // radii either by clamping them or returning 0 for area.
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

    // Test parameterized constructor with negative input - demonstrates Robustness Issue
    Circle c3(-3.0);
    std::cout << "Circle c3 (param -3.0): Radius = " << c3.getRadius() << ", Area = " << c3.getArea() << std::endl;

    // Test copy constructor
    Circle c4 = c2;
    std::cout << "Circle c4 (copy of c2): Radius = " << c4.getRadius() << ", Area = " << c4.getArea() << std::endl;

    Circle c5 = c3; // Copying a circle with a potentially invalid state
    std::cout << "Circle c5 (copy of c3): Radius = " << c5.getRadius() << ", Area = " << c5.getArea() << std::endl;

    return 0;
}