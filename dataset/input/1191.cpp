#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr
#include <cmath>  // For M_PI or other math functions if needed (e.g., std::sqrt)
#include <stdexcept> // For std::invalid_argument

// Define PI as a constant for accuracy and readability
const double PI = 3.14159265358979323846;

// Abstract base class for geometric shapes
class Shape {
public:
    // Pure virtual method to calculate the area of the shape
    virtual double calculateArea() const = 0;
    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~Shape() = default;
};

// Derived class representing a Circle
class Circle : public Shape {
private:
    double radius_; // The radius of the circle
public:
    // Constructor for Circle. Validates that radius is non-negative.
    Circle(double radius) : radius_(radius) {
        if (radius_ < 0) {
            throw std::invalid_argument("Circle radius cannot be negative.");
        }
    }

    // Implements calculateArea for a Circle
    double calculateArea() const override {
        return PI * radius_ * radius_;
    }
};

// Derived class representing a Rectangle
class Rectangle : public Shape {
private:
    double width_;  // The width of the rectangle
    double height_; // The height of the rectangle
public:
    // Constructor for Rectangle. Validates that width and height are non-negative.
    Rectangle(double width, double height) : width_(width), height_(height) {
        if (width_ < 0 || height_ < 0) {
            throw std::invalid_argument("Rectangle dimensions (width/height) cannot be negative.");
        }
    }

    // Implements calculateArea for a Rectangle
    double calculateArea() const override {
        return width_ * height_;
    }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;

    // Create and add valid shapes using a try-catch block for robust construction
    try {
        shapes.push_back(std::make_unique<Circle>(5.0));
        shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
        shapes.push_back(std::make_unique<Circle>(0.0)); // Zero radius is a valid edge case
        shapes.push_back(std::make_unique<Rectangle>(10.0, 0.0)); // Zero dimension is a valid edge case
        // Attempting to create an invalid shape here would throw an exception,
        // which would be caught by the outer try-catch.
        // E.g., shapes.push_back(std::make_unique<Circle>(-3.0));
    } catch (const std::invalid_argument& e) {
        // This demonstrates robust handling of invalid construction arguments
        std::cerr << "Error creating shape: " << e.what() << std::endl;
    }

    // Iterate and print areas for the successfully created shapes
    for (const auto& shape : shapes) {
        std::cout << "Calculated Area: " << shape->calculateArea() << std::endl;
    }

    // Further demonstration of error handling for invalid input (outside the main loop)
    std::cout << "\nDemonstrating error handling for invalid input:\n";
    try {
        Circle invalidCircle(-3.0); // This will throw an exception
        std::cout << "This line should not be reached if an exception is thrown.\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    return 0;
}