#include <iostream>
#include <vector>
#include <string>
#include <memory> // For std::unique_ptr

// Define a precise PI constant for clarity and accuracy
const double PI = 3.14159265358979323846;

// Base class
class Shape {
public:
    virtual double calculateArea() const = 0; // Pure virtual function
    virtual ~Shape() {} // Virtual destructor is crucial for polymorphism and proper cleanup
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width_; // Clear variable name convention
    double height_; // Clear variable name convention
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}
    double calculateArea() const override {
        return width_ * height_;
    }
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius_; // Clear variable name convention
public:
    Circle(double radius) : radius_(radius) {}
    double calculateArea() const override {
        return PI * radius_ * radius_;
    }
};

int main() {
    // Use std::vector of std::unique_ptr for robust, automatic memory management.
    // This prevents memory leaks and simplifies resource handling.
    std::vector<std::unique_ptr<Shape>> shapes;

    // Store instances of Rectangle and Circle using std::make_unique.
    // std::make_unique is the preferred way to create unique_ptr objects.
    shapes.push_back(std::make_unique<Rectangle>(15.0, 10.0));
    shapes.push_back(std::make_unique<Circle>(9.0));
    shapes.push_back(std::make_unique<Rectangle>(6.0, 12.0));
    shapes.push_back(std::make_unique<Circle>(4.0));

    std::cout << "Calculating areas (Correct Version):\n";
    // Iterate through the vector using a range-based for loop for readability and conciseness.
    for (const auto& shape_ptr : shapes) {
        std::cout << "Area: " << shape_ptr->calculateArea() << std::endl;
    }

    // Memory is automatically managed by std::unique_ptr when the 'shapes' vector goes out of scope.
    // No manual 'delete' calls are needed, making the code more robust and less prone to leaks,
    // and improving overall readability and safety.

    return 0;
}