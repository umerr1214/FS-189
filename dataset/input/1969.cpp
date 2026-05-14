#include <iostream>
#include <cmath> // For M_PI
#include <string>
#include <iomanip> // For std::fixed, std::setprecision

// Base class
class Shape {
public:
    virtual double calculateArea() const = 0; // Pure virtual function
    // Robustness Issue: Base class destructor is NOT virtual.
    // This can lead to memory leaks or undefined behavior when deleting
    // derived objects through a base class pointer.
    ~Shape() {
        std::cout << "Shape destructor called." << std::endl;
    }
};

// Derived class
class Circle : public Shape {
private:
    double radius;
    std::string identifier; // Added to demonstrate resource cleanup issue
public:
    Circle(double r, const std::string& id = "Unnamed Circle")
        : radius(r), identifier(id) {
        std::cout << "Circle constructor called for " << identifier << std::endl;
    }

    double calculateArea() const override {
        return M_PI * radius * radius;
    }

    // This destructor will not be called if deleted via a non-virtual base pointer.
    ~Circle() override {
        std::cout << "Circle destructor called for " << identifier << std::endl;
        // If 'identifier' was a dynamically allocated char* or other resource,
        // it would leak here because this destructor is skipped.
    }

    double getRadius() const { return radius; }
};

int main() {
    std::cout << "Demonstrating Robustness Issue: Non-virtual base destructor." << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;

    // Create a Circle object on the heap and point to it with a Shape* pointer.
    Shape* myShapePtr = new Circle(6.0, "MyPolymorphicCircle");

    // Call calculateArea() polymorphically.
    std::cout << "Calculated Area: "
              << std::fixed << std::setprecision(4)
              << myShapePtr->calculateArea() << std::endl;

    // When deleting via Shape* (base class pointer), only Shape's destructor will be called.
    // Circle's destructor will be skipped, potentially leading to resource leaks.
    std::cout << "\nAttempting to delete Shape* pointer..." << std::endl;
    delete myShapePtr;
    myShapePtr = nullptr; // Good practice to nullify dangling pointer

    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "Notice that 'Circle destructor called' was NOT printed, "
              << "indicating a potential resource leak for Circle's members." << std::endl;

    return 0;
}