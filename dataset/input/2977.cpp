#define _USE_MATH_DEFINES // Required for M_PI on some compilers (e.g., MSVC)
#include <iostream>
#include <cmath>    // For M_PI
#include <iomanip>  // For std::fixed, std::setprecision

class Circle {
private:
    double radius;

public:
    // Constructor
    Circle(double r) : radius(r) {}

    // Method to calculate area
    double calculateArea() {
        return M_PI * radius * radius;
    }

    // Method to calculate circumference
    double calculateCircumference() {
        return 2 * M_PI * radius;
    }
};

int main() {
    // Demonstrate with a valid radius
    Circle circle1(5.0);
    std::cout << "Circle 1 (radius 5.0):" << std::endl;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "  Area: " << circle1.calculateArea() << std::endl;
    std::cout << "  Circumference: " << circle1.calculateCircumference() << std::endl;

    std::cout << std::endl;

    // Demonstrate with a negative radius - robustness issue here
    // The class does not validate the input, leading to potentially
    // meaningless or unexpected results (e.g., negative circumference).
    Circle circle2(-3.0);
    std::cout << "Circle 2 (radius -3.0):" << std::endl;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "  Area: " << circle2.calculateArea() << std::endl; // Area will be positive
    std::cout << "  Circumference: " << circle2.calculateCircumference() << std::endl; // Circumference will be negative

    return 0;
}