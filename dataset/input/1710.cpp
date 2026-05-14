#include <iostream>
#include <vector>
#include <string>
#include <cmath> // For M_PI

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Base class
class Shape {
public:
    // SEMANTIC ERROR: Missing 'virtual' keyword.
    // This prevents runtime polymorphism; the base class method will always be called.
    double calculateArea() const {
        return 0.0; // Default implementation, will always be called due to lack of 'virtual'
    }
    virtual ~Shape() {} // Virtual destructor is correctly implemented for proper cleanup
};

// Derived class Circle
class Circle : public Shape {
private:
    double _radius;
public:
    Circle(double radius) : _radius(radius) {}
    // This is a new function, not an override, due to the base class method not being virtual.
    double calculateArea() const {
        return M_PI * _radius * _radius;
    }
};

// Derived class Square
class Square : public Shape {
private:
    double _side;
public:
    Square(double side) : _side(side) {}
    // This is a new function, not an override, due to the base class method not being virtual.
    double calculateArea() const {
        return _side * _side;
    }
};

int main() {
    std::vector<Shape*> shapes;

    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Square(4.0));
    shapes.push_back(new Circle(2.5));

    for (const auto& shapePtr : shapes) {
        // This will always call Shape::calculateArea() (which returns 0.0)
        // because calculateArea in Shape is not virtual.
        std::cout << "Area: " << shapePtr->calculateArea() << std::endl;
    }

    // Clean up dynamically allocated memory
    for (const auto& shapePtr : shapes) {
        delete shapePtr;
    }
    shapes.clear();

    return 0;
}