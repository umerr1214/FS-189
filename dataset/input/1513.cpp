#include <iostream>
#include <cmath> // Required for M_PI

// Base class: Defines the interface for shapes
class Shape {
public:
    // Pure virtual function for calculating area. Not marked const, which is acceptable
    // but less robust for a function that doesn't modify state.
    virtual double calculateArea() = 0;
    // Virtual destructor to ensure proper cleanup of derived objects through base pointers
    virtual ~Shape() = default;
};

// Derived class: Represents a circle
class Circle : public Shape {
private:
    double radius; // Member to store the circle's radius
public:
    // Constructor: Initializes the circle with a given radius.
    // It allows negative radii, which is a source of robustness issue if not handled in calculateArea.
    Circle(double r) : radius(r) {}

    // Implementation of calculateArea for Circle
    // This function does not validate the radius. If 'radius' is negative,
    // it will return a negative area (M_PI * r * r), which is mathematically
    // consistent but physically incorrect for an area, demonstrating a robustness issue.
    double calculateArea() override {
        // M_PI from cmath provides a high-precision value for Pi
        return M_PI * radius * radius;
    }

    // Getter for radius for demonstration purposes
    double getRadius() const {
        return radius;
    }
};

int main() {
    // Create a Circle object with a positive radius for the demonstration.
    // Even though the input here is valid, the class design itself
    // has a robustness flaw for handling non-positive radii.
    const double testRadius = 5.0;
    Circle myCircle(testRadius);

    // Demonstrate calling calculateArea() through a Shape pointer
    Shape* shapePointer = &myCircle;

    std::cout << "Circle radius: " << myCircle.getRadius() << std::endl;
    double area = shapePointer->calculateArea();
    std::cout << "Area (via Shape pointer): " << area << std::endl;

    // To illustrate the robustness issue:
    // Circle problematicCircle(-3.0);
    // Shape* problematicShapePtr = &problematicCircle;
    // std::cout << "\nProblematic Circle radius: " << problematicCircle.getRadius() << std::endl;
    // std::cout << "Problematic Area (via Shape pointer): " << problematicShapePtr->calculateArea() << std::endl;
    // The above would output a negative area, which is not physically meaningful.
    // The current test case avoids this specific output but the vulnerability exists.

    return 0;
}