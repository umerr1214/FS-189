#include <iostream>
#include <vector>
#include <cmath> // For M_PI

// Base class
class Shape {
public:
    virtual double calculateArea() = 0;
    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() override {
        return M_PI * radius * radius;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() override {
        // LOGICAL ERROR: Should be multiplication (width * height), but is addition
        return width + height;
    }
};

int main() {
    std::vector<Shape*> shapes;

    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Circle(2.5));

    std::cout << "Calculating areas using dynamic polymorphism:\n";
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->calculateArea() << std::endl;
    }

    // Clean up memory
    for (const auto& shape : shapes) {
        delete shape;
    }
    shapes.clear();

    return 0;
}