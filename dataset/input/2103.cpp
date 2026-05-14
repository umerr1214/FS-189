#include <iostream>
#include <cmath> // For M_PI
#include <vector>
#include <iomanip> // For std::fixed, std::setprecision

// Base class Shape
class Shape {
public:
    // Virtual method as required, returns 0 by default
    virtual double calculateArea() const {
        return 0.0;
    }
    // Virtual destructor for proper polymorphic cleanup and to prevent memory leaks
    virtual ~Shape() = default;
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    // Constructor initializes width and height
    Rectangle(double w, double h) : width(w), height(h) {}

    // Overrides calculateArea to return specific area, using 'override' for clarity and safety
    double calculateArea() const override {
        return width * height;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    // Constructor initializes radius
    Circle(double r) : radius(r) {}

    // Overrides calculateArea to return specific area, using 'override' for clarity and safety
    double calculateArea() const override {
        return M_PI * radius * radius;
    }
};

// Driver code for test cases
int main() {
    std::cout << std::fixed << std::setprecision(2);

    // Test Case 1: Valid Rectangle
    Rectangle rect1(5.0, 4.0);
    std::cout << "Rectangle (5x4) area: " << rect1.calculateArea() << std::endl;

    // Test Case 2: Rectangle with zero dimensions
    Rectangle rect2(0.0, 10.0);
    std::cout << "Rectangle (0x10) area: " << rect2.calculateArea() << std::endl;

    // Test Case 3: Valid Circle
    Circle circ1(3.0);
    std::cout << "Circle (radius 3) area: " << circ1.calculateArea() << std::endl;

    // Test Case 4: Circle with zero radius
    Circle circ2(0.0);
    std::cout << "Circle (radius 0) area: " << circ2.calculateArea() << std::endl;

    // Test Case 5: Polymorphic calls demonstrating correct behavior
    std::vector<Shape*> shapes;
    shapes.push_back(new Rectangle(10.5, 2.0));
    shapes.push_back(new Circle(5.5));
    shapes.push_back(new Rectangle(7.0, 0.0)); // Edge case: zero dimension
    shapes.push_back(new Circle(1.0)); // Another valid case

    for (const auto& shape : shapes) {
        std::cout << "Polymorphic Shape Area: " << shape->calculateArea() << std::endl;
    }

    // Clean up dynamically allocated objects
    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}