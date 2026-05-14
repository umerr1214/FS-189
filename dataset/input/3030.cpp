#include <iostream>
#include <cmath> // For M_PI

// Base class Shape
class Shape {
public:
    // Pure virtual method
    virtual double calculateArea() = 0;
    virtual ~Shape() {} // Virtual destructor
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Semantic Error: Does not correctly override Shape::calculateArea()
    // because the return type is 'int' instead of 'double'.
    // This makes Rectangle an abstract class.
    int calculateArea() { // Missing 'override' keyword and incorrect return type
        return static_cast<int>(length * width);
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double calculateArea() override {
        return M_PI * radius * radius;
    }
};

int main() {
    // Demonstrate creating objects and calling calculateArea()
    // Semantic Error: Attempting to instantiate an abstract class 'Rectangle'
    // because its 'calculateArea' method has an incorrect signature and does not
    // override the pure virtual method from 'Shape'.
    Rectangle rect(10.0, 5.0); // This line will cause a compile-time error.

    Circle circ(3.0);

    // If Rectangle instantiation was possible, these would work:
    // Shape* s1 = &rect;
    Shape* s2 = &circ;

    // std::cout << "Rectangle area: " << s1->calculateArea() << std::endl;
    std::cout << "Circle area: " << s2->calculateArea() << std::endl;

    return 0;
}