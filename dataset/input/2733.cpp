#include <iostream>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed, std::setprecision

// Base class
class Shape {
public:
    virtual double calculateArea() const {
        return 0.0;
    }
    virtual ~Shape() = default; // Good practice for base classes with virtual methods
};

// Derived class Square
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {
        if (s < 0) { // Input validation for robustness
            side = 0; // Set to a non-negative default
        }
    }

    double calculateArea() const override { // Using override and const correctly
        return side * side;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {
        if (r < 0) { // Input validation for robustness
            radius = 0; // Set to a non-negative default
        }
    }

    double calculateArea() const override { // Using override and const correctly
        return M_PI * radius * radius;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(10); // For consistent output precision

    Square s_pos(5.0);
    Circle c_pos(3.0);
    Square s_neg(-4.0); // Input validation handles negative side
    Circle c_neg(-2.5); // Input validation handles negative radius

    Shape* shapes[] = {&s_pos, &c_pos, &s_neg, &c_neg};

    for (int i = 0; i < 4; ++i) {
        std::cout << shapes[i]->calculateArea() << std::endl;
    }

    // Also include the base shape area
    Shape base_shape;
    std::cout << base_shape.calculateArea() << std::endl;

    return 0;
}