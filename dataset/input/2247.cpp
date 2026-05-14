#include <iostream>
#include <cmath> // Required for M_PI

// Base class Shape
class Shape {
public:
    // Virtual method for calculating area, returns 0 by default
    virtual double calculateArea() {
        return 0.0;
    }

    // Virtual destructor is crucial for polymorphic base classes
    // to ensure proper cleanup of derived objects when deleted via a base pointer.
    virtual ~Shape() {
        std::cout << "Shape destructor called." << std::endl;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
    // Define PI as a static const member for efficiency and consistency
    static const double PI;

public:
    Circle(double r) : radius(r) {
        // Robustness: Basic validation for radius
        if (radius < 0) {
            std::cerr << "Warning: Circle radius cannot be negative. Setting to 0." << std::endl;
            this->radius = 0;
        }
    }

    // Override calculateArea for Circle
    double calculateArea() override {
        return PI * radius * radius; // Efficient and readable squaring
    }

    ~Circle() {
        std::cout << "Circle destructor called." << std::endl;
    }
};

// Initialize static const member
const double Circle::PI = M_PI;

int main() {
    // Demonstrate calling calculateArea through a Shape pointer pointing to a Circle object
    Shape* myShape = new Circle(5.0); // Create a Circle object

    std::cout << "Area of circle with radius 5.0: " << myShape->calculateArea() << std::endl;

    // Proper polymorphic deletion: Circle's destructor will be called, then Shape's.
    delete myShape;

    std::cout << "---------------------------------" << std::endl;

    Shape* anotherShape = new Circle(10.0);
    std::cout << "Area of circle with radius 10.0: " << anotherShape->calculateArea() << std::endl;
    delete anotherShape;

    std::cout << "---------------------------------" << std::endl;

    // Demonstrate with a negative radius to show robustness
    Shape* invalidCircle = new Circle(-3.0);
    std::cout << "Area of circle with radius -3.0 (handled): " << invalidCircle->calculateArea() << std::endl;
    delete invalidCircle;

    return 0;
}