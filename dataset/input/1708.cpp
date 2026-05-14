#include <iostream>
#include <vector>
#include <string>
#include <cmath> // For M_PI

// Define PI if not available (e.g., on Windows with MSVC)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Base class
class Shape {
public:
    virtual double calculateArea() const = 0; // Pure virtual for abstract base class
    virtual ~Shape() {} // Virtual destructor for proper cleanup
};

// Derived class Circle
class Circle : public Shape {
private:
    double _radius;
public:
    Circle(double radius) : _radius(radius) {}
    double calculateArea() const override {
        return M_PI * _radius * _radius;
    }
};

// Derived class Square
class Square : public Shape {
private:
    double _side;
public:
    Square(double side) : _side(side) {}
    double calculateArea() const override {
        return _side * _side;
    }
};

int main() {
    std::vector<Shape*> shapes;

    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Square(4.0));
    shapes.push_back(new Circle(2.5));

    for (const auto& shapePtr : shapes) {
        std::cout << "Area: " << shapePtr->calculateArea() << std::endl // SYNTAX ERROR: Missing semicolon
    }

    // Clean up dynamically allocated memory
    for (const auto& shapePtr : shapes) {
        delete shapePtr;
    }
    shapes.clear();

    return 0;
}