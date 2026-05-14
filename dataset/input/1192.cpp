#include <iostream>
#include <vector>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed, std::setprecision

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Base class
class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        return M_PI * radius * radius;
    }
    ~Circle() override {}
} // SYNTAX ERROR: Missing semicolon here

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() const override {
        return width * height;
    }
    ~Rectangle() override {}
};

int main() {
    std::vector<Shape*> shapes;

    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Circle(2.5));

    std::cout << std::fixed << std::setprecision(5);

    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->calculateArea() << std::endl;
    }

    // Clean up
    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}