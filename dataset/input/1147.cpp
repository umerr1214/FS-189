#define _USE_MATH_DEFINES // Required for M_PI on some compilers (e.g., MSVC)
#include <iostream>
#include <cmath> // For M_PI

class Circle {
private:
    double radius;

public:
    // Constructor: Does not validate radius, allowing negative values.
    Circle(double r) : radius(r) {}

    // Public method to retrieve the radius
    double getRadius() const {
        return radius;
    }

    // Method to calculate and return the circle's area
    double calculateArea() const {
        return M_PI * radius * radius;
    }
};

int main() {
    // Test case 1: Positive radius
    Circle c1(5.0);
    std::cout << "Circle with radius " << c1.getRadius() << std::endl;
    std::cout << "Area: " << c1.calculateArea() << std::endl;

    // Test case 2: Zero radius
    Circle c2(0.0);
    std::cout << "Circle with radius " << c2.getRadius() << std::endl;
    std::cout << "Area: " << c2.calculateArea() << std::endl;

    // Test case 3: Negative radius - Robustness Issue
    // The class allows a negative radius to be stored, which is geometrically nonsensical.
    // While calculateArea() will return a positive value (due to radius*radius),
    // the internal state is invalid from a real-world perspective.
    Circle c3(-3.0);
    std::cout << "Circle with radius " << c3.getRadius() << std::endl;
    std::cout << "Area: " << c3.calculateArea() << std::endl;

    return 0;
}