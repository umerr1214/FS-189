#include <iostream>
#include <cmath> // For M_PI

// Define M_PI if not available (e.g., on some Windows compilers without _USE_MATH_DEFINES)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Base class Shape
class Shape {
public:
    // Pure virtual function to calculate area, marked const as it doesn't modify object state
    virtual double calculateArea() const = 0;
    // Virtual destructor for proper cleanup of derived objects (polymorphic base class)
    virtual ~Shape() = default;
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor for Circle with const parameter
    Circle(double r) : radius(r) {}

    // Override calculateArea for Circle, marked const
    double calculateArea() const override {
        return M_PI * radius * radius;
    }
};

// Derived class Square
class Square : public Shape {
private:
    double side;

public:
    // Constructor for Square with const parameter
    Square(double s) : side(s) {}

    // Override calculateArea for Square, marked const
    double calculateArea() const override {
        return side * side;
    }
};

int main() {
    // Demonstrating the classes with appropriate object names
    Circle circle(5.0);
    Square square(4.0);
    Circle zero_circle(0.0);
    Square zero_square(0.0);
    Circle unit_circle(1.0);
    Square large_square(10.0);

    std::cout << "Area of circle with radius 5.0: " << circle.calculateArea() << std::endl;
    std::cout << "Area of square with side 4.0: " << square.calculateArea() << std::endl;
    std::cout << "Area of circle with radius 0.0: " << zero_circle.calculateArea() << std::endl;
    std::cout << "Area of square with side 0.0: " << zero_square.calculateArea() << std::endl;
    std::cout << "Area of circle with radius 1.0: " << unit_circle.calculateArea() << std::endl;
    std::cout << "Area of square with side 10.0: " << large_square.calculateArea() << std::endl;

    return 0;
}