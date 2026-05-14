#define _USE_MATH_DEFINES // Required for M_PI on some compilers (e.g., MSVC)
#include <iostream>
#include <cmath>   // For M_PI
#include <iomanip> // For std::fixed and std::setprecision

// Define M_PI if not defined by cmath
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Base class
class Shape {
public:
    // Pure virtual function to make Shape an abstract class
    virtual double calculateArea() const = 0;
    virtual ~Shape() {} // Virtual destructor for proper cleanup
};

// Derived class
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    // Override the virtual function
    double calculateArea() const override {
        return M_PI * radius * radius;
    }
};

int main() {
    double test_radius = 5.0;
    Circle myCircle(test_radius);
    Shape* shapePtr = &myCircle;

    std::cout << "Calculating area for a circle with radius " << test_radius << std::endl;
    std::cout << std::fixed << std::setprecision(12); // Format output for precision
    // Syntax Error: Missing semicolon after the previous statement
    std::cout << "Area of the circle (via Shape*): " << shapePtr->calculateArea() << std::endl
    return 0;
}