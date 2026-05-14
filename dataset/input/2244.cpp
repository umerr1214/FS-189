#include <iostream>
#include <cmath>
#include <iomanip>

class Shape {
public:
    // Semantic Error: 'calculateArea' is not virtual in the base class.
    // This prevents polymorphic dispatch when called through a base class pointer.
    double calculateArea() const { // Missing 'virtual' keyword
        return 0.0;
    }
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    // This function hides Shape::calculateArea() instead of overriding it,
    // because Shape::calculateArea() is not virtual.
    double calculateArea() const { // 'override' keyword removed to avoid compiler warning/error on non-virtual override
        return 3.14159 * radius * radius;
    }
};

int main() {
    Circle myCircle(5.0);
    Shape* sPtr = &myCircle; // Shape pointer points to a Circle object

    // Semantic Error will manifest here:
    // Because Shape::calculateArea is not virtual, this call will invoke
    // Shape's implementation (which returns 0.0), not Circle's.
    std::cout << "Area of circle (through Shape pointer): "
              << std::fixed << std::setprecision(2)
              << sPtr->calculateArea() << std::endl;

    return 0;
}