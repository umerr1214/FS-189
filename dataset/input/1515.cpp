#include <iostream>
#include <cmath> // Required for M_PI, a high-precision constant for Pi

// Base class: Defines the interface for shapes
class Shape {
public:
    // Pure virtual function for calculating area, marked const
    // because calculating an area should not modify the shape's state.
    virtual double calculateArea() const = 0;
    // Virtual destructor to ensure proper cleanup of derived objects when deleted
    // through a base class pointer. Using `= default` for clarity and efficiency.
    virtual ~Shape() = default;
};

// Derived class: Represents a circle, inheriting from Shape
class Circle : public Shape {
private:
    double radius; // Member to store the circle's radius
public:
    // Constructor: Initializes the circle with a given radius.
    // The parameter `r` is marked `const` as it's an input value that won't be modified.
    Circle(const double r) : radius(r) {
        // Basic validation: ensure radius is non-negative for physical meaning.
        // If an invalid radius is passed, it's set to 0 to prevent negative area.
        if (radius < 0) {
            radius = 0;
        }
    }

    // Implementation of calculateArea for Circle
    // Marked const, overriding the base class's pure virtual const function.
    // It returns 0.0 for non-positive radii, ensuring a physically meaningful result.
    double calculateArea() const override {
        // If radius is 0 or negative (due to constructor validation), area is 0.
        if (radius <= 0) {
            return 0.0;
        }
        // Use M_PI for high precision and readability.
        return M_PI * radius * radius;
    }

    // Getter for radius, marked const as it only provides access to the member
    // without modifying the object's state.
    double getRadius() const {
        return radius;
    }
};

int main() {
    // Create a Circle object with a specific, valid radius.
    const double testRadius = 10.0;
    Circle myCircle(testRadius);

    // Demonstrate calling calculateArea() through a Shape pointer.
    // A Shape pointer can point to any object derived from Shape,
    // allowing polymorphic behavior.
    Shape* shapePointer = &myCircle;

    // Output the radius for context.
    std::cout << "Circle radius: " << myCircle.getRadius() << std::endl;
    // Call the pure virtual function via the base class pointer.
    // The correct Circle::calculateArea() implementation will be invoked.
    double area = shapePointer->calculateArea();

    std::cout << "Area (via Shape pointer): " << area << std::endl;

    return 0;
}