#include <iostream>
#include <cmath>   // For M_PI
#include <iomanip> // For std::fixed and std::setprecision

// Base class
class Shape {
public:
    // Pure virtual function for calculating area
    virtual double calculateArea() const = 0;
    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~Shape() {
        // In a correct program, derived destructors would be called via this virtual destructor.
        // However, if 'delete' is forgotten, this destructor won't be invoked for dynamically allocated objects.
    }
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    // The 'override' keyword is omitted here, which is a minor readability/safety issue,
    // but the primary error for this file is robustness (memory leak).
    double calculateArea() const { // This implicitly overrides Shape::calculateArea()
        return M_PI * radius * radius;
    }
    ~Circle() {
        // std::cout << "Circle destructor called." << std::endl; // For debugging memory leaks
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() const { // This implicitly overrides Shape::calculateArea()
        return width * height;
    }
    ~Rectangle() {
        // std::cout << "Rectangle destructor called." << std::endl; // For debugging memory leaks
    }
};

int main() {
    const int num_shapes = 3;
    // Using a raw array of Shape pointers
    Shape* shapes[num_shapes];

    // Dynamically allocate derived objects using 'new'
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);
    shapes[2] = new Circle(2.5);

    std::cout << "Calculating areas of various shapes (Robustness Issue - Memory Leak):" << std::endl;
    std::cout << std::fixed << std::setprecision(4); // Set precision for consistent output

    // Demonstrate dynamic polymorphism by calling calculateArea() on Shape pointers
    for (int i = 0; i < num_shapes; ++i) {
        std::cout << "Shape " << i + 1 << " area: " << shapes[i]->calculateArea() << std::endl;
    }

    // !!! ROBUSTNESS ISSUE: Memory leak - The objects allocated with 'new' are NOT deleted.
    // This means the memory they occupy is not released back to the system,
    // and their destructors (e.g., ~Circle(), ~Rectangle()) are never called.
    // In a long-running application or with frequent object creation, this would exhaust memory.

    return 0;
}