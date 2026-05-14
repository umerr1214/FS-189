#include <iostream>
#include <vector>
#include <cmath> // For M_PI

// Base class
class Shape {
public:
    // SEMANTIC ERROR: calculateArea is NOT virtual.
    // This prevents dynamic polymorphism; calls will be statically dispatched
    // to Shape::calculateArea() even when using a Shape* to derived objects.
    double calculateArea() {
        return 0.0; // Default or placeholder implementation
    }
    virtual ~Shape() {} // Destructor should still be virtual for proper cleanup
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    // This 'hides' Shape::calculateArea(), it does not 'override' it polymorphically
    double calculateArea() {
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
    // This 'hides' Shape::calculateArea(), it does not 'override' it polymorphically
    double calculateArea() {
        return width * height;
    }
};

int main() {
    std::vector<Shape*> shapes;

    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Circle(2.5));

    std::cout << "Calculating areas using dynamic polymorphism:\n";
    for (const auto& shape : shapes) {
        // Due to the semantic error (missing 'virtual' in base class),
        // this will always call Shape::calculateArea(), which returns 0.0.
        std::cout << "Area: " << shape->calculateArea() << std::endl;
    }

    // Clean up memory
    for (const auto& shape : shapes) {
        delete shape;
    }
    shapes.clear();

    return 0;
}