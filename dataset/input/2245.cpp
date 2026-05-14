#include <iostream>
#include <cmath> // For M_PI

// Base class Shape
class Shape {
public:
    virtual double calculateArea() {
        return 0.0; // Default implementation returns 0
    }

    // Non-virtual destructor - a common robustness issue for polymorphic classes
    ~Shape() {
        std::cout << "Shape destructor called." << std::endl;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        // Allows negative radius to be set without validation, which can be a robustness issue
        // The area calculation will still yield a positive value (r*r), but a negative radius
        // is physically meaningless and indicates a lack of input validation.
    }

    // Override calculateArea for Circle
    double calculateArea() override {
        // If radius is negative, r*r will still be positive.
        // This doesn't prevent a semantically incorrect state (negative radius).
        return M_PI * radius * radius;
    }

    ~Circle() {
        std::cout << "Circle destructor called." << std::endl;
    }
};

int main() {
    // Demonstrate calling calculateArea through a Shape pointer
    Shape* myShape = new Circle(-5.0); // Create a Circle with a negative radius

    std::cout << "Area calculated via Shape pointer: " << myShape->calculateArea() << std::endl;

    // Due to non-virtual destructor in Shape, only Shape's destructor will be called
    // when deleting via a Shape pointer, leading to undefined behavior or resource leaks
    // if Circle had specific resources to free.
    delete myShape;

    // Let's demonstrate with a positive radius for comparison
    Shape* anotherShape = new Circle(10.0);
    std::cout << "Area calculated via Shape pointer (positive radius): " << anotherShape->calculateArea() << std::endl;
    delete anotherShape;

    return 0;
}