#include <iostream>
#include <vector>
#include <memory>
#include <cmath> // For M_PI

// Base class Shape
class Shape {
public:
    // SEMANTIC ERROR: calculateArea is not virtual.
    // This means dynamic dispatch will not work correctly when using base pointers.
    double calculateArea() const {
        return 0.0; // Default or placeholder implementation
    }
    virtual ~Shape() = default;
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    // This function hides Shape::calculateArea() because Shape::calculateArea() is not virtual.
    // If 'override' keyword were used, it would be a compile error.
    double calculateArea() const {
        return M_PI * radius * radius;
    }
};

// Derived class Square
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    // This function hides Shape::calculateArea() because Shape::calculateArea() is not virtual.
    double calculateArea() const {
        return side * side;
    }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Square>(4.0));
    shapes.push_back(std::make_unique<Circle>(10.0));
    shapes.push_back(std::make_unique<Square>(7.0));

    for (const auto& shape : shapes) {
        // SEMANTIC ERROR: This will always call Shape::calculateArea() (which returns 0.0)
        // because the base function is not virtual, preventing dynamic dispatch.
        std::cout << shape->calculateArea() << std::endl;
    }

    return 0;
}