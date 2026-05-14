#include <iostream>
#include <cmath>   // For M_PI and std::abs
#include <vector>  // To store shapes in a collection
#include <memory>  // For std::unique_ptr for better memory management

// Abstract base class
class Shape {
public:
    virtual ~Shape() = default; // Use default destructor for proper cleanup
    virtual double calculateArea() const = 0; // Mark as const as it doesn't modify object state
};

// Concrete class Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        if (radius < 0) { // Input validation for robustness
            std::cerr << "Warning: Circle radius cannot be negative. Setting to 0." << std::endl;
            radius = 0;
        }
    }

    double calculateArea() const override { // Mark as const
        return M_PI * radius * radius; // Efficient multiplication
    }
};

// Concrete class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (width < 0 || height < 0) { // Input validation for robustness
            std::cerr << "Warning: Rectangle dimensions cannot be negative. Setting to absolute values." << std::endl;
            width = std::abs(width);
            height = std::abs(height);
        }
    }

    double calculateArea() const override { // Mark as const
        return width * height;
    }
};

int main() {
    std::cout.precision(2);
    std::cout << std::fixed;

    // Create instances and demonstrate polymorphism using smart pointers for memory safety
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 5.0));
    shapes.push_back(std::make_unique<Circle>(10.0));
    shapes.push_back(std::make_unique<Rectangle>(7.0, 3.0));
    shapes.push_back(std::make_unique<Circle>(-2.0)); // Test validation
    shapes.push_back(std::make_unique<Rectangle>(-3.0, 8.0)); // Test validation

    for (const auto& shape_ptr : shapes) {
        // Use dynamic_cast for specific info if needed for output, or just call virtual method
        if (const Circle* circle = dynamic_cast<const Circle*>(shape_ptr.get())) {
            std::cout << "Area of Circle: " << circle->calculateArea() << std::endl;
        } else if (const Rectangle* rect = dynamic_cast<const Rectangle*>(shape_ptr.get())) {
            std::cout << "Area of Rectangle: " << rect->calculateArea() << std::endl;
        }
    }

    // Smart pointers handle memory cleanup automatically, no manual delete needed.

    return 0;
}