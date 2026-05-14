#include <iostream>
#include <vector>   // For std::vector
#include <memory>   // For std::unique_ptr
#include <cmath>    // For M_PI
#include <iomanip>  // For std::fixed, std::setprecision

// Abstract Base Class Shape
class Shape {
public:
    // Pure virtual function for calculating area, marked as const-correct
    virtual double calculateArea() const = 0;

    // Virtual destructor to ensure proper cleanup of derived objects
    // Using `= default` for modern C++ style and efficiency
    virtual ~Shape() = default;
};

// Concrete Derived Class Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor
    Circle(double r) : radius(r) {
        // Basic validation: ensure radius is non-negative for valid geometry.
        // A robust solution might throw an exception or log an error.
        if (radius < 0) {
            radius = 0; // Clamp to 0
        }
    }

    // Implementation of the pure virtual function, marked with override and const
    double calculateArea() const override {
        return M_PI * radius * radius;
    }

    // Getter for radius, marked const
    double getRadius() const { return radius; }
};

// Concrete Derived Class Rectangle
class Rectangle : public public Shape {
private:
    double width;
    double height;

public:
    // Constructor
    Rectangle(double w, double h) : width(w), height(h) {
        // Basic validation: ensure dimensions are non-negative.
        if (width < 0) {
            width = 0; // Clamp to 0
        }
        if (height < 0) {
            height = 0; // Clamp to 0
        }
    }

    // Implementation of the pure virtual function, marked with override and const
    double calculateArea() const override {
        return width * height;
    }

    // Getters for width and height, marked const
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

int main() {
    std::cout << std::fixed << std::setprecision(4); // Set precision for consistent output

    std::cout << "Demonstrating Shape hierarchy (Correct Version)." << std::endl;

    // 1. Demonstrate that Shape objects cannot be instantiated directly.
    // Uncommenting the line below will cause a compile-time error because Shape is abstract:
    // Shape myAbstractShape; // Error: cannot instantiate abstract class

    std::cout << "\nAttempting to create a Shape object (will fail at compile time if uncommented):" << std::endl;
    std::cout << "// Shape myAbstractShape; // This line would cause a compile error." << std::endl;

    // 2. Demonstrate instantiation and area calculation for derived concrete classes.
    std::cout << "\nInstantiating concrete derived classes:" << std::endl;

    Circle circle(5.0);
    std::cout << "Circle with radius " << circle.getRadius() << ": Area = " << circle.calculateArea() << std::endl;

    Rectangle rectangle(4.0, 6.0);
    std::cout << "Rectangle with width " << rectangle.getWidth() << ", height " << rectangle.getHeight() << ": Area = " << rectangle.calculateArea() << std::endl;

    // 3. Demonstrate polymorphism using a collection of smart pointers to Shape objects.
    // std::unique_ptr is used for automatic memory management.
    std::cout << "\nDemonstrating polymorphism with std::unique_ptr<Shape>:" << std::endl;
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(7.0));
    shapes.push_back(std::make_unique<Rectangle>(10.0, 5.0));
    shapes.push_back(std::make_unique<Circle>(2.5)); // Another circle
    shapes.push_back(std::make_unique<Rectangle>(3.0, 9.0)); // Another rectangle
    shapes.push_back(std::make_unique<Circle>(-1.0)); // Demonstrate validation (clamped to 0 radius)

    for (const auto& shape_ptr : shapes) {
        std::cout << "Calculated area: " << shape_ptr->calculateArea() << std::endl;
    }
    // std::unique_ptr automatically handles memory deallocation when they go out of scope.

    return 0;
}