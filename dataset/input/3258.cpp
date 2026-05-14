#include <iostream>
#include <vector>
#include <cmath> // For M_PI

// Base class
class Shape {
public:
    virtual double calculateArea() const = 0; // Pure virtual function
    // Intentionally introduce a semantic error: missing virtual destructor
    // This will lead to undefined behavior when deleting derived objects via base pointers
    ~Shape() { // Non-virtual destructor
        std::cout << "Shape destructor called." << std::endl;
    }
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
    ~Circle() {
        std::cout << "Circle destructor called." << std::endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() const override {
        return width * height;
    }
    ~Rectangle() {
        std::cout << "Rectangle destructor called." << std::endl;
    }
};

int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Circle(2.5));

    std::cout << "Calculating areas:" << std::endl;
    for (const auto& shape : shapes) {
        std::cout << "Shape area: " << shape->calculateArea() << std::endl;
    }

    std::cout << "\nCleaning up memory (will demonstrate semantic error if not virtual):" << std::endl;
    // When deleting, only Shape destructor will be called for Circle/Rectangle objects
    // leading to resource leaks or undefined behavior.
    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}