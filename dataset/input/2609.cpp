#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip> // For std::fixed and std::setprecision

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Abstract Base Class
class Shape {
public:
    virtual double calculateArea() = 0; // Pure virtual function
    virtual ~Shape() {} // Virtual destructor
};

// Derived Concrete Class: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() override {
        // LOGICAL ERROR: This calculates circumference (2 * pi * r) instead of area (pi * r * r)
        return 2 * M_PI * radius;
    }
};

// Derived Concrete Class: Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() override {
        return width * height; // Correct implementation
    }
};

int main() {
    // Instantiate derived concrete classes
    Circle circle(5.0); // Radius 5.0
    Rectangle rectangle(4.0, 6.0); // Width 4.0, Height 6.0

    // Use polymorphism
    std::vector<Shape*> shapes;
    shapes.push_back(&circle);
    shapes.push_back(&rectangle);

    std::cout << std::fixed << std::setprecision(4); // For consistent output formatting
    std::cout << "--- Shape Areas ---" << std::endl;
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->calculateArea() << std::endl;
    }

    return 0;
}