#include <iostream>
#include <vector>
#include <memory>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed and std::setprecision

// Base class
class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual ~Shape() = default; // Virtual destructor is crucial for polymorphism
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
    const int num_shapes = 3;
    Shape* shapes[num_shapes]; // Array of raw Shape pointers

    // Populate the array with dynamically allocated objects
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);
    shapes[2] = new Circle(3.0);

    std::cout << "Calculating areas:" << std::endl;
    for (int i = 0; i < num_shapes; ++i) {
        std::cout << "Shape " << i + 1 << " Area: " << std::fixed << std::setprecision(4) << shapes[i]->calculateArea() << std::endl;
    }

    // MEMORY LEAK: Forgetting to delete the dynamically allocated objects.
    // The objects created with 'new' are never deleted, leading to a memory leak.
    // This code intentionally omits 'delete' calls to demonstrate the robustness issue.
    // Correct cleanup would involve iterating and calling 'delete shapes[i];' for each.

    return 0;
}