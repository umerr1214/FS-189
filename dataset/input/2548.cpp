#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Base class
class Shape {
public:
    virtual double calculateArea() const {
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
}; // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    std::vector<Shape*> shapes;

    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Circle(2.5));

    for (const auto& shape : shapes) {
        std::cout << "Area: " << std::fixed << std::setprecision(2) << shape->calculateArea() << std::endl;
    }

    // Clean up dynamically allocated memory
    for (const auto& shape : shapes) {
        delete shape;
    }
    shapes.clear();

    return 0;
}