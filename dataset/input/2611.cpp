#include <iostream>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed, std::setprecision
#include <vector> // For std::vector

// Abstract Base Class Shape
class Shape {
public:
    // Pure virtual function for calculating area
    virtual double calculateArea() = 0;

    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~Shape() {
        // In a real application, this might print a message, but for this
        // robustness example, we keep it simple.
    }
};

// Concrete Derived Class Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor - allows negative radius, demonstrating robustness issue
    Circle(double r) : radius(r) {}

    // Implementation of the pure virtual function
    double calculateArea() override {
        // Robustness issue: If radius is negative, radius*radius will be positive,
        // leading to a positive area for a geometrically invalid input.
        // A robust solution would validate radius (e.g., radius = std::abs(radius);)
        // or throw an exception for negative values.
        return M_PI * radius * radius;
    }

    // Getter for radius
    double getRadius() const { return radius; }
};

// Concrete Derived Class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // Constructor - allows negative dimensions, demonstrating robustness issue
    Rectangle(double w, double h) : width(w), height(h) {}

    // Implementation of the pure virtual function
    double calculateArea() override {
        // Robustness issue: If width or height is negative, width*height will be positive
        // if both are negative, or negative if one is negative.
        // Geometrically, dimensions should be non-negative.
        // A robust solution would validate dimensions (e.g., width = std::abs(width);)
        // or return 0 for invalid inputs.
        return width * height;
    }

    // Getters for width and height
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

int main() {
    std::cout << std::fixed << std::setprecision(4); // Set precision for consistent output

    std::cout << "Demonstrating Shape hierarchy with robustness issue (negative dimensions)." << std::endl;

    // Attempt to instantiate Shape (will cause a compile-time error if uncommented)
    // Shape myShape; // Error: cannot instantiate abstract class

    // Demonstrating Circle with negative radius - robustness issue
    Circle c1(-5.0); // Geometrically invalid radius
    std::cout << "Circle with radius " << c1.getRadius() << ": Area = " << c1.calculateArea() << std::endl;

    // Demonstrating Rectangle with negative dimensions - robustness issue
    Rectangle r1(-4.0, 6.0); // Geometrically invalid width, leads to negative area
    std::cout << "Rectangle with width " << r1.getWidth() << ", height " << r1.getHeight() << ": Area = " << r1.calculateArea() << std::endl;

    Rectangle r2(-3.0, -7.0); // Both dimensions negative, area becomes positive (still geometrically invalid)
    std::cout << "Rectangle with width " << r2.getWidth() << ", height " << r2.getHeight() << ": Area = " << r2.calculateArea() << std::endl;

    std::cout << "\nDemonstrating with valid dimensions:" << std::endl;
    Circle c2(10.0);
    std::cout << "Circle with radius " << c2.getRadius() << ": Area = " << c2.calculateArea() << std::endl;

    Rectangle r3(5.0, 8.0);
    std::cout << "Rectangle with width " << r3.getWidth() << ", height " << r3.getHeight() << ": Area = " << r3.calculateArea() << std::endl;

    // Using polymorphism with a collection of Shape pointers, including another robustness example
    std::cout << "\nDemonstrating polymorphism:" << std::endl;
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(7.0));
    shapes.push_back(new Rectangle(10.0, 5.0));
    shapes.push_back(new Circle(-2.0)); // Another robustness issue example

    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << "Shape " << i + 1 << " area: " << shapes[i]->calculateArea() << std::endl;
        delete shapes[i]; // Clean up dynamically allocated memory
    }
    shapes.clear();

    return 0;
}