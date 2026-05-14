#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr

// Base class
class Shape {
public:
    // Semantic Error: calculateArea is NOT virtual.
    // This prevents runtime polymorphism, leading to Shape's calculateArea being called.
    double calculateArea() const {
        std::cout << "Calling Shape's calculateArea (default/base behavior).\n";
        return 0.0; // Default implementation, will be called instead of derived versions
    }
    virtual ~Shape() = default; // Destructor is still virtual for proper cleanup
};

// Derived class: Square
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    // This 'calculateArea' will hide Shape's, but won't be called polymorphically
    double calculateArea() const { // Note: 'override' keyword would cause a compile error here
        return side * side;
    }
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    // This 'calculateArea' will hide Shape's, but won't be called polymorphically
    double calculateArea() const { // Note: 'override' keyword would cause a compile error here
        return 3.14159 * radius * radius;
    }
};

int main() {
    // Create a vector of unique_ptr to Shape for automatic memory management
    std::vector<std::unique_ptr<Shape>> shapes;

    // Store instances of Square and Circle
    shapes.push_back(std::make_unique<Square>(5.0));
    shapes.push_back(std::make_unique<Circle>(3.0));
    shapes.push_back(std::make_unique<Square>(7.5));
    shapes.push_back(std::make_unique<Circle>(2.5));

    std::cout << "Demonstrating semantic error (no virtual function):\n";

    // Iterate through the array and call calculateArea() for each object
    // Due to calculateArea not being virtual in Shape, Shape::calculateArea() will always be called.
    for (const auto& shape : shapes) {
        std::cout << "Actual Area (expected by question): " << (dynamic_cast<Square*>(shape.get()) ? dynamic_cast<Square*>(shape.get())->calculateArea() : (dynamic_cast<Circle*>(shape.get()) ? dynamic_cast<Circle*>(shape.get())->calculateArea() : 0.0)) << " (This is NOT what the loop calls)\n";
        std::cout << "Polymorphic Call Result: " << shape->calculateArea() << std::endl;
    }

    return 0;
}