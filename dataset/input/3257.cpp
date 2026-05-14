#include <iostream>
#include <vector>
#include <cmath> // For M_PI

// Base class
class Shape {
public:
    virtual double calculateArea() const = 0; // Pure virtual function
    virtual ~Shape() {} // Virtual destructor
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        return M_PI * radius * radius;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    // Intentionally introduce a logical error: incorrect area calculation
    double calculateArea() const override {
        return width + height; // Should be width * height
    }
};

int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));      // Expected Area: PI * 25 = 78.5398...
    shapes.push_back(new Rectangle(4.0, 6.0)); // Expected Area: 24.0, Actual (logical error): 10.0
    shapes.push_back(new Circle(2.5));      // Expected Area: PI * 6.25 = 19.6349...
    shapes.push_back(new Rectangle(3.0, 7.0)); // Expected Area: 21.0, Actual (logical error): 10.0

    std::cout << "Calculating areas:" << std::endl;
    for (const auto& shape : shapes) {
        std::cout << "Shape area: " << shape->calculateArea() << std::endl;
    }

    // Clean up memory
    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}