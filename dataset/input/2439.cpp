#include <iostream>
#include <vector>    // For std::vector
#include <cmath>     // For M_PI
#include <memory>    // For std::unique_ptr and std::make_unique
#include <iomanip>   // For std::fixed and std::setprecision

// Base class
class Shape {
public:
    // Pure virtual function for calculating area, making Shape an abstract class
    virtual double calculateArea() const = 0;
    // Virtual destructor to ensure proper cleanup of derived objects when deleted via a base pointer
    virtual ~Shape() = default; // C++11 way to define default virtual destructor
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius_; // Clear naming convention for member variables
public:
    Circle(double r) : radius_(r) {}
    // Use 'override' keyword for clarity and compile-time checks
    double calculateArea() const override {
        return M_PI * radius_ * radius_; // Efficient squaring
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width_;
    double height_;
public:
    Rectangle(double w, double h) : width_(w), height_(h) {}
    // Use 'override' keyword
    double calculateArea() const override {
        return width_ * height_;
    }
};

// Derived class: Triangle
class Triangle : public Shape {
private:
    double base_;
    double height_;
public:
    Triangle(double b, double h) : base_(b), height_(h) {}
    // Use 'override' keyword
    double calculateArea() const override {
        return 0.5 * base_ * height_;
    }
};

int main() {
    // Use std::vector of std::unique_ptr for dynamic polymorphism and automatic memory management (RAII)
    std::vector<std::unique_ptr<Shape>> shapes;

    // Add derived class objects to the vector using std::make_unique for safe allocation
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(std::make_unique<Circle>(2.5));
    shapes.push_back(std::make_unique<Triangle>(3.0, 7.0)); // Added a Triangle for more diverse polymorphism

    std::cout << "Calculating areas of various shapes (Correct Version):" << std::endl;
    std::cout << std::fixed << std::setprecision(4); // Set precision for consistent output

    int shape_count = 1;
    // Demonstrate dynamic polymorphism using a readable range-based for loop
    for (const auto& shape_ptr : shapes) {
        std::cout << "Shape " << shape_count++ << " area: " << shape_ptr->calculateArea() << std::endl;
    }

    // Memory is automatically managed by std::unique_ptr when the 'shapes' vector goes out of scope.
    // No explicit 'delete' calls are needed, preventing memory leaks and simplifying code.

    return 0;
}