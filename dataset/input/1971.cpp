#include <iostream>
#include <cmath> // For M_PI (often defined here)
#include <iomanip> // For std::fixed, std::setprecision

// Base class: Shape
// Declared as abstract (due to pure virtual function) to enforce derived classes implement calculateArea().
class Shape {
public:
    // Pure virtual function for calculating area.
    // Marked `const` as it does not modify the object's state.
    virtual double calculateArea() const = 0;

    // Virtual destructor is crucial for proper cleanup of derived objects
    // when they are deleted via a base class pointer (demonstrating runtime polymorphism).
    virtual ~Shape() {}
};

// Derived class: Circle
// Inherits from Shape and provides a concrete implementation for calculateArea().
class Circle : public Shape {
private:
    double radius; // Member variable for circle's radius
public:
    // Constructor to initialize the circle with a given radius.
    Circle(double r) : radius(r) {}

    // Override the pure virtual calculateArea() method from Shape.
    // Calculates the area of the circle using M_PI * r^2.
    // Marked `const` and uses `override` keyword for clarity and compile-time checking.
    double calculateArea() const override {
        return M_PI * radius * radius; // Efficient and clear calculation.
    }

    // A getter method for radius, marked `const` as it does not modify the object.
    double getRadius() const { return radius; }
};

int main() {
    // 1. Create a Shape* pointer.
    Shape* myShapePtr;

    // Define a radius for our circle.
    double circleRadius = 7.5;

    // 2. Assign a Circle object to the Shape* pointer.
    // This demonstrates runtime polymorphism: a base class pointer pointing to a derived class object.
    myShapePtr = new Circle(circleRadius);

    // 3. Call calculateArea() through the Shape* pointer.
    // Due to the `virtual` keyword in the base class and `override` in the derived class,
    // the correct (Circle's) `calculateArea()` implementation is invoked at runtime.
    std::cout << "Demonstrating Runtime Polymorphism:" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Created a Circle object with radius: " << circleRadius << std::endl;
    std::cout << "Calling calculateArea() via Shape* pointer..." << std::endl;
    std::cout << "Calculated Area: "
              << std::fixed << std::setprecision(4) // Format output for readability
              << myShapePtr->calculateArea() << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    // Clean up dynamically allocated memory to prevent memory leaks.
    delete myShapePtr;
    myShapePtr = nullptr; // Set pointer to nullptr after deletion for safety.

    return 0;
}