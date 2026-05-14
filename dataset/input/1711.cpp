#include <iostream>
#include <vector>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed, std::setprecision

// Define M_PI if not available (e.g., on some compilers or specific flags)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Base class Shape
class Shape {
public:
    virtual double calculateArea() = 0;
    // ROBUSTNESS ISSUE: Destructor is NOT virtual.
    // This will lead to undefined behavior or memory leaks when deleting derived objects
    // through a base class pointer if derived classes have their own resources or complex destructors.
    ~Shape() {
        // std::cout << "Shape destructor called.\n"; // For demonstration, if needed
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() override {
        return M_PI * radius * radius;
    }
    ~Circle() {
        // std::cout << "Circle destructor called.\n"; // This will NOT be called through Shape* if Shape's dtor is non-virtual
    }
};

// Derived class Square
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double calculateArea() override {
        return side * side;
    }
    ~Square() {
        // std::cout << "Square destructor called.\n"; // This will NOT be called through Shape* if Shape's dtor is non-virtual
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(4);

    std::vector<Shape*> shapes;

    // Populate the vector with Circle and Square objects
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Square(4.0));
    shapes.push_back(new Circle(2.5));

    std::cout << "Calculating areas:\n";
    // Iterate through the vector and call calculateArea() for each object
    for (Shape* s : shapes) {
        if (dynamic_cast<Circle*>(s)) {
            std::cout << "Circle area: " << s->calculateArea() << "\n";
        } else if (dynamic_cast<Square*>(s)) {
            std::cout << "Square area: " << s->calculateArea() << "\n";
        } else {
            std::cout << "Unknown shape area: " << s->calculateArea() << "\n";
        }
    }

    // Clean up dynamically allocated objects
    // This is where the robustness issue manifests due to non-virtual destructor in Shape
    for (Shape* s : shapes) {
        delete s;
    }

    return 0;
}