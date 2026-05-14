#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr
#include <cmath>  // Not strictly needed for this version, but common for math operations

// Abstract base class Shape
class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual ~Shape() = default;
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius_;
public:
    // Constructor allows negative radius without validation.
    // This is the core robustness issue: it accepts semantically invalid input.
    Circle(double r) : radius_(r) {}

    // calculateArea uses the provided radius, even if negative.
    // Mathematically, (-r)*(-r) results in r*r, so the area will be positive.
    // However, a physical circle cannot have a negative radius.
    // This leads to a semantically incorrect result for a real-world shape.
    double calculateArea() const override {
        // Using a magic number for PI, which is a minor readability/maintainability issue,
        // but the main issue here is the lack of input validation.
        return 3.14159 * radius_ * radius_;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width_;
    double height_;
public:
    // Constructor allows negative dimensions without validation.
    // This is the core robustness issue: it accepts semantically invalid input.
    Rectangle(double w, double h) : width_(w), height_(h) {}

    // calculateArea uses the provided dimensions, even if negative.
    // Mathematically, (-w)*(-h) results in w*h, so the area will be positive.
    // However, a physical rectangle cannot have negative width or height.
    // This leads to a semantically incorrect result for a real-world shape.
    double calculateArea() const override {
        return width_ * height_;
    }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;

    // Test cases demonstrating the robustness issue with negative inputs
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(std::make_unique<Circle>(-3.0)); // Semantically invalid radius, but calculates positive area
    shapes.push_back(std::make_unique<Rectangle>(-2.0, -7.0)); // Semantically invalid dimensions, but calculates positive area
    shapes.push_back(std::make_unique<Rectangle>(0.0, 5.0)); // Valid edge case

    for (const auto& shape : shapes) {
        std::cout << "Calculated Area: " << shape->calculateArea() << std::endl;
    }

    return 0;
}