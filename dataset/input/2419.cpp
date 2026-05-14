#include <iostream>
#include <string>
#include <vector>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed, std::setprecision

// Base class
class Shape {
public:
    virtual double calculateArea() const {
        return 0;
    }
    virtual ~Shape() = default;
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // Constructor allows negative dimensions, which is a robustness issue
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculateArea() const override {
        // Area calculation doesn't validate dimensions,
        // resulting in negative area if width or height is negative.
        return width * height;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        // M_PI might not be defined on all compilers without _USE_MATH_DEFINES
        // or a custom definition. This is a minor robustness issue if not handled,
        // though commonly available. Even if radius is negative, radius*radius will be positive.
        return M_PI * radius * radius;
    }
};