#include <iostream>
#include <cmath> // For M_PI

// Abstract base class
class Shape {
public:
    virtual ~Shape() = default;
    virtual double calculateArea() = 0;
};

// Concrete class Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Allows negative radius, which is not robust for physical interpretation
    Circle(double r) : radius(r) {}

    double calculateArea() override {
        // If radius is negative, it will still result in a positive area due to squaring,
        // but this hides the invalid input, making the system less robust as it
        // doesn't validate or correct physically impossible dimensions.
        return M_PI * radius * radius;
    }
};

// Concrete class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // Allows negative width/height, leading to negative area which is nonsensical
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculateArea() override {
        // If width or height is negative, the area will be negative,
        // which is physically impossible and indicates a lack of robustness
        // in input handling.
        return width * height;
    }
};

int main() {
    // Test cases with some valid and some invalid (negative) dimensions
    Circle c1(5.0);
    Circle c2(-3.0); // Robustness issue: negative radius
    Rectangle r1(4.0, 5.0);
    Rectangle r2(-2.0, 6.0); // Robustness issue: negative width
    Rectangle r3(1.0, -7.0); // Robustness issue: negative height

    std::cout.precision(2);
    std::cout << std::fixed;

    std::cout << "Area of Circle (radius 5.0): " << c1.calculateArea() << std::endl;
    std::cout << "Area of Circle (radius -3.0): " << c2.calculateArea() << std::endl; // Area will be positive, but from invalid input
    std::cout << "Area of Rectangle (4.0x5.0): " << r1.calculateArea() << std::endl;
    std::cout << "Area of Rectangle (-2.0x6.0): " << r2.calculateArea() << std::endl; // Area will be negative
    std::cout << "Area of Rectangle (1.0x-7.0): " << r3.calculateArea() << std::endl; // Area will be negative

    return 0;
}