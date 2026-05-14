#include <iostream>
#include <cmath> // For M_PI

// Define M_PI if not available (e.g., on some Windows compilers without _USE_MATH_DEFINES)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Base class Shape
class Shape {
public:
    // Virtual function to calculate area
    virtual double calculateArea() = 0;
    // Virtual destructor for proper cleanup of derived objects
    virtual ~Shape() = default;
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor for Circle - accepts any double, including negative
    Circle(double r) : radius(r) {}

    // Override calculateArea for Circle
    // Note: This implementation computes area based on the given radius,
    // even if negative, by squaring it. This is a robustness issue as
    // it doesn't validate input or interpret negative dimensions as invalid.
    double calculateArea() override {
        return M_PI * radius * radius;
    }
};

// Derived class Square
class Square : public Shape {
private:
    double side;

public:
    // Constructor for Square - accepts any double, including negative
    Square(double s) : side(s) {}

    // Override calculateArea for Square
    // Note: Similar to Circle, this computes area based on the given side,
    // even if negative, by squaring it.
    double calculateArea() override {
        return side * side;
    }
};

int main() {
    // Demonstrating the classes
    Circle circle1(5.0);
    Square square1(4.0);
    Circle circle2(0.0);
    Square square2(0.0);
    Circle circle3(-3.0); // Negative radius - robustness issue
    Square square3(-2.0); // Negative side - robustness issue

    std::cout << "Area of circle with radius 5.0: " << circle1.calculateArea() << std::endl;
    std::cout << "Area of square with side 4.0: " << square1.calculateArea() << std::endl;
    std::cout << "Area of circle with radius 0.0: " << circle2.calculateArea() << std::endl;
    std::cout << "Area of square with side 0.0: " << square2.calculateArea() << std::endl;
    std::cout << "Area of circle with radius -3.0: " << circle3.calculateArea() << std::endl; // Expects 28.27...
    std::cout << "Area of square with side -2.0: " << square3.calculateArea() << std::endl;   // Expects 4.0

    return 0;
}