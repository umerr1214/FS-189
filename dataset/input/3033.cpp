#include <iostream>
#include <cmath>    // For M_PI
#include <iomanip>  // For std::fixed, std::setprecision
#include <memory>   // For std::unique_ptr (modern C++ demonstration)

// Base class Shape
class Shape {
public:
    // Pure virtual method for calculating area
    virtual double calculateArea() const = 0;
    // Virtual destructor is essential for proper cleanup of derived objects through base pointers
    virtual ~Shape() = default;
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    // Constructor for proper initialization
    Rectangle(double l, double w) : length(l), width(w) {
        // Optional: Add input validation for robustness, e.g., if (l < 0 || w < 0) throw std::invalid_argument("Dimensions cannot be negative");
    }

    double calculateArea() const override {
        return length * width;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor for proper initialization
    Circle(double r) : radius(r) {
        // Optional: Add input validation for robustness, e.g., if (r < 0) throw std::invalid_argument("Radius cannot be negative");
    }

    double calculateArea() const override {
        // Use M_PI from <cmath> for an accurate PI value
        return M_PI * radius * radius;
    }
};

int main() {
    // Set output precision for demonstration
    std::cout << std::fixed << std::setprecision(2);

    // Demonstrate creating objects of derived classes and calling their calculateArea() method
    // Using std::unique_ptr for automatic memory management and polymorphism (modern C++ practice)
    std::unique_ptr<Shape> rect_ptr = std::make_unique<Rectangle>(5.0, 4.0);
    std::unique_ptr<Shape> circle_ptr = std::make_unique<Circle>(3.0);

    std::cout << "Rectangle Area: " << rect_ptr->calculateArea() << std::endl;
    std::cout << "Circle Area: " << circle_ptr->calculateArea() << std::endl;

    // Also demonstrate stack-allocated objects for simpler cases
    Rectangle stack_rect(6.0, 3.0);
    Circle stack_circle(2.5);

    std::cout << "Stack Rectangle Area: " << stack_rect.calculateArea() << std::endl;
    std::cout << "Stack Circle Area: " << stack_circle.calculateArea() << std::endl;

    return 0;
}