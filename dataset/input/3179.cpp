#include <iostream>
#include <cmath> // Required for M_PI

// M_PI is a GNU extension, define if not available
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Shape {
public:
    virtual double calculateArea() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() override {
        return M_PI * radius * radius; // Correct implementation
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double calculateArea() override {
        return 2 * (length + width); // Logical Error: Calculates perimeter instead of area
    }
};

int main() {
    Circle c(5.0);
    Rectangle r(4.0, 6.0);

    std::cout << "Circle Area: " << c.calculateArea() << std::endl;
    std::cout << "Rectangle Area: " << r.calculateArea() << std::endl;

    return 0;
}