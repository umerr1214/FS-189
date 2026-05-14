#include <iostream>

// Base class Shape
class Shape {
public:
    virtual double calculateArea() const {
        return 0.0;
    }
    virtual ~Shape() {} // Virtual destructor for proper cleanup
};

// Derived class Square
class Square : public Shape {
public:
    double side;

    Square(double s) : side(s) {}

    double calculateArea() const override {
        return side * side; // Correct implementation
    }
};

// Derived class Circle
class Circle : public Shape {
public:
    double radius;

    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        // Logical error: Calculates circumference (2*PI*r) instead of area (PI*r*r)
        return 2 * 3.14159 * radius;
    }
};

int main() {
    // Create objects and calculate areas
    Square s(5.0);
    Circle c(3.0);

    Shape* shape1 = &s;
    Shape* shape2 = &c;

    std::cout << "Area of Square: " << shape1->calculateArea() << std::endl; // Expected: 25.0, Actual: 25.0
    std::cout << "Area of Circle: " << shape2->calculateArea() << std::endl; // Expected: 28.27431, Actual: 18.84954

    return 0;
}