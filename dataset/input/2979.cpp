#define _USE_MATH_DEFINES // Required for M_PI on some compilers (e.g., MSVC)
#include <iostream>
#include <cmath>    // For M_PI
#include <iomanip>  // For std::fixed, std::setprecision

class Circle {
private:
    double radius;
    // Using a static const member for PI is good practice for a class-specific constant
    static const double PI;

public:
    // Constructor with input validation for robustness
    Circle(double r) : radius(r) {
        if (radius < 0) {
            std::cerr << "Warning: Radius cannot be negative. Setting to 0." << std::endl;
            radius = 0;
        }
    }

    // Public method to calculate the area
    double calculateArea() const { // const method as it doesn't modify the object state
        return PI * radius * radius;
    }

    // Public method to calculate the circumference
    double calculateCircumference() const { // const method
        return 2 * PI * radius;
    }
};

// Initialize the static const member outside the class definition
const double Circle::PI = M_PI;

int main() {
    // Demonstrate creating a Circle object with a valid radius
    Circle circle1(7.5);
    std::cout << "Circle 1 (radius 7.5):" << std::endl;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "  Area: " << circle1.calculateArea() << std::endl;
    std::cout << "  Circumference: " << circle1.calculateCircumference() << std::endl;

    std::cout << std::endl;

    // Demonstrate with an invalid radius to show robustness (handled by constructor)
    Circle circle2(-4.0);
    std::cout << "Circle 2 (radius -4.0, corrected to 0):" << std::endl;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "  Area: " << circle2.calculateArea() << std::endl;
    std::cout << "  Circumference: " << circle2.calculateCircumference() << std::endl;

    return 0;
}