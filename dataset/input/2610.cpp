#include <iostream>
#include <vector>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Abstract Base Class
class Shape {
public:
    virtual double calculateArea() = 0; // Pure virtual function
    virtual ~Shape() {} // Virtual destructor
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    // SEMANTIC ERROR: Circle does NOT provide an implementation for calculateArea().
    // This makes the Circle class itself abstract.
    // To fix: add 'double calculateArea() override { return M_PI * radius * radius; }'
};

// Derived Concrete Class: Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() override {
        return width * height; // Correct implementation
    }
};

int main() {
    // Demonstrate that abstract classes cannot be instantiated directly.
    // The Circle class is abstract because it inherits a pure virtual function
    // (Shape::calculateArea) but does not provide an implementation for it.
    // Therefore, attempting to create an object of type Circle will result in a compile-time error.
    Circle circle(5.0); // SEMANTIC ERROR: Cannot instantiate abstract class 'Circle'

    // This part would be fine if the above line was commented out
    Rectangle rectangle(4.0, 6.0);
    std::cout << "Rectangle Area: " << rectangle.calculateArea() << std::endl;

    return 0;
}