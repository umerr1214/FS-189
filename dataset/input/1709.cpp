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
    virtual double calculateArea() const = 0;
    virtual ~Shape() {}
};

// Derived class Circle
class Circle : public Shape {
private:
    double _radius;
public:
    Circle(double radius) : _radius(radius) {}
    double calculateArea() const override {
        return M_PI * _radius * _radius; // Correct calculation
    }
};

// Derived class Square
class Square : public Shape {
private:
    double _side;
public:
    Square(double side) : _side(side) {}
    double calculateArea() const override {
        return _side * 2; // LOGICAL ERROR: Should be _side * _side for area, but calculates _side * 2
    }
};

int main() {
    std::vector<Shape*> shapes;

    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Square(4.0));
    shapes.push_back(new Circle(2.5));

    for (const auto& shapePtr : shapes) {
        std::cout << "Area: " << shapePtr->calculateArea() << std::endl;
    }

    // Clean up dynamically allocated memory
    for (const auto& shapePtr : shapes) {
        delete shapePtr;
    }
    shapes.clear();

    return 0;
}