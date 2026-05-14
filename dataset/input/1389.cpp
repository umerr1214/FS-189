#define _USE_MATH_DEFINES // Required for M_PI on some systems
#include <iostream>
#include <cmath> // For M_PI
#include <algorithm> // For std::max

// Abstract base class Shape
class Shape {
public:
    virtual double getArea() const = 0; // Const-correctness
    virtual ~Shape() = default; // Virtual destructor for proper cleanup
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // Constructor with input validation for robustness
    Rectangle(double w, double h)
        : width(std::max(0.0, w)), height(std::max(0.0, h)) {}

    // getArea implementation with const-correctness and override keyword
    double getArea() const override {
        return width * height;
    }

    // Getter functions with const-correctness
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor with input validation for robustness
    Circle(double r) : radius(std::max(0.0, r)) {}

    // getArea implementation with const-correctness and override keyword
    double getArea() const override {
        return M_PI * radius * radius;
    }

    // Getter function with const-correctness
    double getRadius() const { return radius; }
};

int main() {
    // Create instances of Rectangle and Circle
    Rectangle rect1(5.0, 10.0);
    Rectangle rect2(0.0, 7.0);   // Zero width
    Rectangle rect3(-2.0, 5.0);  // Negative width, handled robustly to 0
    Rectangle rect4(4.0, -6.0);  // Negative height, handled robustly to 0

    Circle circ1(4.0);
    Circle circ2(0.0);   // Zero radius
    Circle circ3(-3.0);  // Negative radius, handled robustly to 0

    // Print areas
    std::cout << "Rectangle 1 (5x10) Area: " << rect1.getArea() << std::endl;
    std::cout << "Rectangle 2 (0x7) Area: " << rect2.getArea() << std::endl;
    std::cout << "Rectangle 3 (-2x5 -> 0x5) Area: " << rect3.getArea() << std::endl;
    std::cout << "Rectangle 4 (4x-6 -> 4x0) Area: " << rect4.getArea() << std::endl;

    std::cout << "Circle 1 (radius 4) Area: " << circ1.getArea() << std::endl;
    std::cout << "Circle 2 (radius 0) Area: " << circ2.getArea() << std::endl;
    std::cout << "Circle 3 (radius -3 -> 0) Area: " << circ3.getArea() << std::endl;

    // Polymorphic usage
    Shape* shapes[] = {&rect1, &circ1, &rect3, &circ3};
    std::cout << "\nPolymorphic Area Calculations:" << std::endl;
    for (const auto& shape : shapes) {
        std::cout << "Shape Area: " << shape->getArea() << std::endl;
    }

    return 0;
}