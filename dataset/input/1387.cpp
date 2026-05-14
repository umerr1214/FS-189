#define _USE_MATH_DEFINES // Required for M_PI on some systems
#include <iostream>
#include <cmath> // For M_PI

// Abstract base class Shape
class Shape {
public:
    virtual double getArea() = 0;
    virtual ~Shape() = default; // Virtual destructor for proper cleanup
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() override {
        // Robustness issue: Allows negative dimensions and calculates negative area.
        // A robust solution would validate input (e.g., width = std::max(0.0, w);)
        return width * height;
    }

    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() override {
        // Robustness issue: Allows negative radius.
        // While radius*radius makes it positive, a negative radius is physically meaningless
        // and a robust solution would validate input (e.g., radius = std::abs(r);)
        return M_PI * radius * radius;
    }

    double getRadius() const { return radius; }
};

int main() {
    // Demonstrate robustness issues with negative inputs
    Rectangle rect1(5.0, 10.0);
    Rectangle rect2(-2.0, 5.0); // Negative width
    Rectangle rect3(10.0, -3.0); // Negative height
    Rectangle rect4(-4.0, -6.0); // Both negative

    Circle circ1(4.0);
    Circle circ2(-3.0); // Negative radius

    std::cout << "Rectangle 1 (5x10) Area: " << rect1.getArea() << std::endl;
    std::cout << "Rectangle 2 (-2x5) Area: " << rect2.getArea() << std::endl; // Expected -10.0
    std::cout << "Rectangle 3 (10x-3) Area: " << rect3.getArea() << std::endl; // Expected -30.0
    std::cout << "Rectangle 4 (-4x-6) Area: " << rect4.getArea() << std::endl; // Expected 24.0 (but inputs are non-physical)

    std::cout << "Circle 1 (radius 4) Area: " << circ1.getArea() << std::endl;
    std::cout << "Circle 2 (radius -3) Area: " << circ2.getArea() << std::endl; // Expected M_PI * 9.0 (radius squared becomes positive, but input is non-physical)

    return 0;
}