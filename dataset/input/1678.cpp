#include <iostream>
#include <vector>
#include <memory>
#include <cmath> // For M_PI

// Base class Shape
class Shape {
public:
    virtual double calculateArea() const = 0; // Pure virtual function
    virtual ~Shape() = default;
} // SYNTAX ERROR: Missing semicolon here

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    // override calculateArea()
    double calculateArea() const override {
        // SYNTAX ERROR: Missing 'return' keyword
        M_PI * radius * radius;
    }
};

// Derived class Square
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    // override calculateArea()
    double calculateArea() const override {
        return side * side;
    }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Square>(4.0));

    for (const auto& shape : shapes) {
        std::cout << shape->calculateArea() << std::endl;
    }

    return 0;
}