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

    double calculateArea() override {
        return length * width;
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
} // Missing semicolon here

int main() {
    // Demonstrate creating objects and calling calculateArea()
    Rectangle rect(10.0, 5.0);
    Circle circ(3.0);

    Shape* s1 = &rect;
    Shape* s2 = &circ;

    std::cout << "Rectangle area: " << s1->calculateArea() << std::endl;
    std::cout << "Circle area: " << s2->calculateArea() << std::endl;

    return 0;
}