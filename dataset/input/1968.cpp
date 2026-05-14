#define _USE_MATH_DEFINES // Required for M_PI on some compilers (e.g., MSVC)
#include <iostream>
#include <cmath>   // For M_PI
#include <iomanip> // For std::fixed and std::setprecision

// Define M_PI if not defined by cmath
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Base class
class Shape {
public:
    // Semantic Error: calculateArea is NOT virtual.
    // This prevents runtime polymorphism when called via a base pointer.
    // The question asks to demonstrate runtime polymorphism, but this design prevents it.
    double calculateArea() const { // Not virtual, not pure virtual
        return 0.0; // Default implementation for Shape (e.g., for non-abstract shapes)
    }
    virtual ~Shape() {} // Still good practice to have a virtual destructor
};

// Derived class
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    // This is an override, but because Shape::calculateArea is not virtual,
    // this will be a new function in Circle's vtable, not an override of the base class method for polymorphism.
    // When called via Shape*, the Shape's version will be invoked (static binding).
    double calculateArea() const { // No 'override' keyword needed/possible for non-virtual base function
        return M_PI * radius * radius;
    }
};

int main() {
    double test_radius = 6.0;
    Circle myCircle(test_radius);
    Shape* shapePtr = &myCircle; // Shape* points to a Circle object

    // Semantic error demonstration: This call will invoke Shape::calculateArea() (which returns 0.0),
    // NOT Circle::calculateArea(), because Shape::calculateArea() is not virtual.
    // This fails to demonstrate runtime polymorphism as requested by the question.
    std::cout << "Calculating area for a circle with radius " << test_radius << std::endl;
    std::cout << std::fixed << std::setprecision(12); // Format output for precision
    std::cout << "Area of the circle (via Shape*): " << shapePtr->calculateArea() << std::endl;

    return 0;
}