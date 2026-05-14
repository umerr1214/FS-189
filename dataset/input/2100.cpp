#include <iostream>
#include <cmath> // For M_PI

// Base class
class Shape {
public:
    // SEMANTIC ERROR: Not marked virtual. This prevents dynamic dispatch.
    double calculateArea() { // Should be virtual double calculateArea()
        return 0.0;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    // This method *hides* Shape::calculateArea, it does not override it polymorphically
    double calculateArea() { // Removed 'override' as base is not virtual, otherwise it's a compile error
        return width * height;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    // This method *hides* Shape::calculateArea, it does not override it polymorphically
    double calculateArea() { // Removed 'override' as base is not virtual, otherwise it's a compile error
        return M_PI * radius * radius;
    }
};

int main() {
    Rectangle rect(4, 5);
    Circle circle(3);

    std::cout << "Rectangle Area (direct call): " << rect.calculateArea() << std::endl;
    std::cout << "Circle Area (direct call): " << circle.calculateArea() << std::endl;

    // When called via base class pointer, it will call Shape's calculateArea (0.0)
    // because Shape::calculateArea is not virtual.
    Shape* s1 = &rect;
    Shape* s2 = &circle;
    std::cout << "Shape* to Rectangle Area (polymorphic call fails): " << s1->calculateArea() << std::endl;
    std::cout << "Shape* to Circle Area (polymorphic call fails): " << s2->calculateArea() << std::endl;

    return 0;
}