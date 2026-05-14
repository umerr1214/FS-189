#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr and std::make_unique
#include <cmath>  // For M_PI
#include <iomanip> // For std::fixed and std::setprecision

// Base class
class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual ~Shape() = default; // Virtual destructor is crucial for correct polymorphic cleanup
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        return M_PI * radius * radius;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() const override {
        return width * height;
    }
};

int main() {
    // Demonstrate polymorphism using std::vector of smart pointers (std::unique_ptr)
    // This provides automatic memory management (RAII), flexibility, and safety.
    std::vector<std::unique_ptr<Shape>> shapes;

    // Populate the vector with dynamically allocated objects of Circle and Rectangle
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(std::make_unique<Circle>(3.0));
    shapes.push_back(std::make_unique<Rectangle>(2.5, 7.0)); // Adding an extra shape

    std::cout << "Calculating areas:" << std::endl;
    // Iterate through the vector and call calculateArea() on each object polymorphically
    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << "Shape " << i + 1 << " Area: " << std::fixed << std::setprecision(4) << shapes[i]->calculateArea() << std::endl;
    }

    // std::unique_ptr automatically handles memory deallocation when the vector
    // goes out of scope, ensuring no memory leaks and robust resource management.

    return 0;
}