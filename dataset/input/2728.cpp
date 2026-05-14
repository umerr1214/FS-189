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
        return side * side;
    }
}; // Missing semicolon here, causing a syntax error

// Derived class Circle
class Circle : public Shape {
public:
    double radius;

    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
};

int main() {
    // Attempt to create objects and calculate areas
    Square s(5.0);
    Circle c(3.0);

    Shape* shape1 = &s;
    Shape* shape2 = &c;

    std::cout << "Area of Square: " << shape1->calculateArea() << std::endl;
    std::cout << "Area of Circle: " << shape2->calculateArea() << std::endl;

    return 0;
}