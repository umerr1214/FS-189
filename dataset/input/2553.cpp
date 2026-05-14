#include <iostream>
#include <vector>
#include <string>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed, std::setprecision
#include <memory>  // For std::unique_ptr, std::make_unique
#include <sstream> // For output to string stream
#include <numbers> // For std::numbers::pi (C++20 standard library constant)

// Fallback for M_PI if <numbers> is not available or C++20 is not used
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Base class: Shape
class Shape {
public:
    // Pure virtual function for calculating area, declared const as it doesn't modify object state
    virtual double calculateArea() const = 0;

    // Virtual destructor to ensure proper cleanup of derived objects through a base pointer
    virtual ~Shape() = default; // Using default for a simple destructor
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius_; // Clear naming convention
public:
    Circle(double r) : radius_(r) {}

    // Override calculateArea, declared const
    double calculateArea() const override {
        // Using std::numbers::pi for high precision if C++20 is available, otherwise M_PI
        #if __cplusplus >= 202002L
        return std::numbers::pi * radius_ * radius_;
        #else
        return M_PI * radius_ * radius_;
        #endif
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width_;  // Clear naming convention
    double height_; // Clear naming convention
public:
    Rectangle(double w, double h) : width_(w), height_(h) {}

    // Override calculateArea, declared const
    double calculateArea() const override {
        return width_ * height_;
    }
};

// Test cases driver function
std::string run_test_cases() {
    // Use std::vector of std::unique_ptr for robust, automatic memory management
    std::vector<std::unique_ptr<Shape>> shapes;

    // Populate with Circle and Rectangle objects using std::make_unique for safe creation
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(std::make_unique<Circle>(2.5));
    shapes.push_back(std::make_unique<Rectangle>(10.0, 2.0));

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2); // Format output for consistent precision

    // Iterate through the vector using a range-based for loop and call calculateArea()
    // Runtime polymorphism ensures the correct calculateArea() for each object is called.
    for (const auto& shape_ptr : shapes) {
        oss << "Area: " << shape_ptr->calculateArea() << "\n";
    }

    // Memory is automatically managed by std::unique_ptr when 'shapes' vector goes out of scope.
    // No manual `delete` calls are needed, making the code safer and cleaner.
    return oss.str();
}

int main() {
    std::cout << run_test_cases();
    return 0;
}