#include <iostream>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed, std::setprecision

// Base class Shape
class Shape {
public:
    // Pure virtual method for calculating area
    virtual double calculateArea() const = 0;
    virtual ~Shape() = default; // Virtual destructor
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() const override {
        // Robustness Issue: No validation for negative length or width.
        // It will simply calculate a negative area if dimensions are negative.
        return length * width;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        // Robustness Issue: No validation for negative radius.
        // radius * radius will be positive, so the area will be positive,
        // but a negative radius is physically meaningless and leads to an incorrect interpretation.
        return M_PI * radius * radius;
    }
};

int main() {
    // Set output precision for demonstration
    std::cout << std::fixed << std::setprecision(2);

    // Demonstrate Robustness Issue with negative dimensions
    std::cout << "Demonstrating Robustness Issue (negative inputs):\n";

    // Rectangle with negative length
    Rectangle rect_neg_length(-5.0, 4.0);
    std::cout << "Rectangle (length=-5.0, width=4.0) Area: " << rect_neg_length.calculateArea() << std::endl;

    // Circle with negative radius
    Circle circle_neg_radius(-3.0);
    std::cout << "Circle (radius=-3.0) Area: " << circle_neg_radius.calculateArea() << std::endl;

    // A "normal" case for comparison
    Rectangle rect_pos(5.0, 4.0);
    std::cout << "Rectangle (length=5.0, width=4.0) Area: " << rect_pos.calculateArea() << std::endl;

    Circle circle_pos(3.0);
    std::cout << "Circle (radius=3.0) Area: " << circle_pos.calculateArea() << std::endl;

    return 0;
}