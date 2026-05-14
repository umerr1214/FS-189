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
    // Semantic Error: Circle does not implement the pure virtual calculateArea() method,
    // making Circle itself an abstract class.
    // An attempt to instantiate Circle will result in a compilation error.
};

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

int main() {
    // Attempting to instantiate an abstract class 'Circle'
    Circle c(5.0); // This line will cause a semantic error during compilation

    Rectangle r(4.0, 6.0);
    std::cout << "Rectangle Area: " << r.calculateArea() << std::endl;

    // This line would also fail if compilation proceeded, as c is an abstract class
    // std::cout << "Circle Area: " << c.calculateArea() << std::endl;

    return 0;
}