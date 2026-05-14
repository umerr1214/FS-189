#include <iostream>
#include <string>
#include <vector>
#include <cmath> // For std::abs, though not strictly used for robustness issue here

// Abstract base class GeometricShape
class GeometricShape {
public:
    // Pure virtual function for calculating area
    virtual double getArea() const = 0;

    // Non-virtual function for getting shape name
    std::string getName() const {
        return shapeName;
    }

    // Virtual destructor for proper cleanup of derived objects
    virtual ~GeometricShape() = default;

protected:
    std::string shapeName;
};

// Derived class Rectangle
class Rectangle : public GeometricShape {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {
        shapeName = "Rectangle";
    }

    // Implementation of getArea for Rectangle
    double getArea() const override {
        // Robustness issue: Allows negative dimensions, resulting in negative area
        // A more robust solution would validate inputs or return 0 for invalid dimensions.
        return width_ * height_;
    }

private:
    double width_;
    double height_;
};

// Derived class Triangle
class Triangle : public GeometricShape {
public:
    Triangle(double base, double height) : base_(base), height_(height) {
        shapeName = "Triangle";
    }

    // Implementation of getArea for Triangle
    double getArea() const override {
        // Robustness issue: Allows negative dimensions, resulting in negative area
        return 0.5 * base_ * height_;
    }

private:
    double base_;
    double height_;
};

int main() {
    std::vector<GeometricShape*> shapes;

    // Valid shapes
    shapes.push_back(new Rectangle(5.0, 4.0));      // Expected: 20.0
    shapes.push_back(new Triangle(6.0, 3.0));       // Expected: 9.0

    // Shapes with "problematic" (negative/zero) dimensions - Robustness Issue
    // The program computes a value, but it's physically nonsensical for an area.
    shapes.push_back(new Rectangle(-5.0, 4.0));     // Expected: -20.0 (mathematically correct, physically nonsensical)
    shapes.push_back(new Triangle(0.0, 10.0));      // Expected: 0.0 (mathematically correct, physically nonsensical for a shape with positive height)
    shapes.push_back(new Rectangle(-2.0, -3.0));    // Expected: 6.0 (mathematically correct, but from invalid inputs)
    shapes.push_back(new Triangle(-4.0, -5.0));     // Expected: 10.0 (mathematically correct, but from invalid inputs)


    std::cout << "--- Shape Areas ---" << std::endl;
    for (const auto& shape : shapes) {
        std::cout << shape->getName() << " Area: " << shape->getArea() << std::endl;
    }

    // Clean up memory
    for (const auto& shape : shapes) {
        delete shape;
    }
    shapes.clear();

    return 0;
}