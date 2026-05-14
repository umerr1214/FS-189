#include <iostream>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed, std::setprecision

// Define M_PI if not available (e.g., on MSVC without _USE_MATH_DEFINES)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Circle {
private:
    double radius;

public:
    // Default constructor
    Circle() : radius(1.0) {}

    // Constructor with radius argument
    Circle(double r) : radius(r) {}

    // Method to calculate area
    double calculateArea() {
        return M_PI * radius * radius;
    }

    void printRadius() {
        std::cout << "Radius: " << radius << std::endl;
    } // SYNTAX ERROR: Missing semicolon here
};

int main() {
    Circle c1; // Default constructor
    std::cout << "Circle 1 (default):" << std::endl;
    c1.printRadius();
    std::cout << "Area: " << std::fixed << std::setprecision(4) << c1.calculateArea() << std::endl;

    Circle c2(5.0); // Parameterized constructor
    std::cout << "\nCircle 2 (radius 5.0):" << std::endl;
    c2.printRadius();
    std::cout << "Area: " << std::fixed << std::setprecision(4) << c2.calculateArea() << std::endl;

    Circle c3(0.0); // Parameterized constructor
    std::cout << "\nCircle 3 (radius 0.0):" << std::endl;
    c3.printRadius();
    std::cout << "Area: " << std::fixed << std::setprecision(4) << c3.calculateArea() << std::endl;

    return 0;
}