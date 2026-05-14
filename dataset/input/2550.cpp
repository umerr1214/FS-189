#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Base class
class Shape {
public:
    virtual double calculateArea() const {
        std::cout << "Shape::calculateArea() called. "; // Added for demonstration of slicing
        return 0.0; // Default implementation
    }
    virtual ~Shape() {} // Virtual destructor for proper cleanup
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double calculateArea() const override {
        return length * width;
    }
};

int main() {
    // SEMANTIC ERROR: Object slicing occurs here.
    // The vector stores `Shape` objects by value, not pointers or references.
    // When derived class objects (Circle, Rectangle) are added, only the `Shape` base-class portion
    // is copied into the vector element. The derived-class specific data and the override
    // for `calculateArea()` are 'sliced off'.
    std::vector<Shape> shapes; // Incorrect: should be std::vector<Shape*> or std::vector<std::unique_ptr<Shape>>

    shapes.push_back(Circle(5.0));       // Circle object is sliced, only Shape part is copied
    shapes.push_back(Rectangle(4.0, 6.0)); // Rectangle object is sliced
    shapes.push_back(Circle(2.5));      // Circle object is sliced

    for (const auto& shape : shapes) {
        // Due to slicing, `shape` is a `Shape` object, not a `Circle` or `Rectangle`.
        // Therefore, `Shape::calculateArea()` is always invoked, preventing runtime polymorphism.
        std::cout << "Area: " << std::fixed << std::setprecision(2) << shape.calculateArea() << std::endl;
    }

    // No dynamic memory to clean up as objects are stored by value.
    // However, the intent of polymorphism is violated.

    return 0;
}