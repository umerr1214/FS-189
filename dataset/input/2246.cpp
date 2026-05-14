#include <iostream>
#include <cmath> // Required for std::pow

// Base class Shape
class Shape {
public:
    virtual double calculateArea() {
        return 0.0; // Default implementation
    }

    virtual ~Shape() {
        std::cout << "Shape destructor called." << std::endl;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        // No input validation, but not the primary focus of this error type.
    }

    // Override calculateArea for Circle
    double calculateArea() override {
        // Readability/Efficiency Issue: Using std::pow(radius, 2) instead of radius * radius
        // For squaring, direct multiplication is generally more efficient and often more readable.
        return M_PI * std::pow(radius, 2);
    }

    ~Circle() {
        std::cout << "Circle destructor called." << std::endl;
    }
};

int main() {
    // Demonstrate calling calculateArea through a Shape pointer
    Shape* myShape = new Circle(5.0);

    std::cout << "Area calculated via Shape pointer: " << myShape->calculateArea() << std::endl;

    delete myShape; // Proper polymorphic deletion due to virtual destructor

    Shape* anotherShape = new Circle(10.0);
    std::cout << "Area calculated via Shape pointer: " << anotherShape->calculateArea() << std::endl;
    delete anotherShape;

    return 0;
}