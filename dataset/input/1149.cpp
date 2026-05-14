#define _USE_MATH_DEFINES // Required for M_PI on some compilers (e.g., MSVC)
#include <iostream>
#include <cmath>   // For M_PI
#include <limits>  // For numeric_limits

class Circle {
private:
    double radius;

public:
    // Constructor: Initializes radius, validates input.
    // If radius is negative, it sets it to 0 and prints a warning.
    Circle(double r) {
        if (r < 0.0) {
            std::cerr << "Warning: Radius cannot be negative. Setting radius to 0." << std::endl;
            radius = 0.0;
        } else {
            radius = r;
        }
    }

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
    // Set output precision for floating-point numbers
    std::cout.precision(std::numeric_limits<double>::max_digits10);

    // Test case 1: Valid positive radius
    Circle c1(5.0);
    std::cout << "Circle with radius " << c1.getRadius() << ", Area: " << c1.calculateArea() << std::endl;

    // Test case 2: Zero radius
    Circle c2(0.0);
    std::cout << "Circle with radius " << c2.getRadius() << ", Area: " << c2.calculateArea() << std::endl;

    // Test case 3: Negative radius (should be handled gracefully)
    Circle c3(-3.0); // Expect warning and radius set to 0
    std::cout << "Circle with radius " << c3.getRadius() << ", Area: " << c3.calculateArea() << std::endl;

    // Test case 4: Another positive radius
    Circle c4(1.0);
    std::cout << "Circle with radius " << c4.getRadius() << ", Area: " << c4.calculateArea() << std::endl;

    return 0;
}