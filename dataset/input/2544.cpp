#include <iostream>
#include <cmath> // For std::acos
#include <iomanip> // For std::fixed, std::setprecision

// Define PI for consistent calculations
const double PI = 3.14159265358979323846;

class Shape {
public:
    // Semantic Error: Missing 'virtual' keyword.
    // This prevents polymorphic behavior when using base class pointers/references.
    double calculateArea() const { // Should be virtual double calculateArea() const {
        return 0;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    // This method 'hides' Shape::calculateArea, but does not virtually override it.
    // If base class method was virtual, this would implicitly override.
    double calculateArea() const { // Should ideally have 'override' if base was virtual
        return PI * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    // This method 'hides' Shape::calculateArea, but does not virtually override it.
    // If base class method was virtual, this would implicitly override.
    double calculateArea() const { // Should ideally have 'override' if base was virtual
        return width * height;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2); // Set precision for output

    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    // Using base class pointers to demonstrate the semantic error
    Shape* s1 = &circle;
    Shape* s2 = &rectangle;

    // These calls will incorrectly invoke Shape::calculateArea() (returning 0.00)
    // because calculateArea() in Shape is not virtual.
    std::cout << "Circle Area (via Shape*): " << s1->calculateArea() << std::endl;
    std::cout << "Rectangle Area (via Shape*): " << s2->calculateArea() << std::endl;

    // Direct calls to demonstrate correct calculation if not using polymorphism
    std::cout << "Circle Area (direct): " << circle.calculateArea() << std::endl;
    std::cout << "Rectangle Area (direct): " << rectangle.calculateArea() << std::endl;

    Shape baseShape;
    std::cout << "Base Shape Area: " << baseShape.calculateArea() << std::endl;

    return 0;
}