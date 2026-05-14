#include <iostream>
#include <vector>
#include <memory>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed and std::setprecision

// Base class
class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual ~Shape() = default;
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
    const int MAX_SHAPES = 5; // Hardcoded maximum size for the array
    Shape* shapes[MAX_SHAPES]; // C-style array of raw Shape pointers
    int current_shapes_count = 0; // Tracks the actual number of shapes added

    // Populate the array with dynamically allocated objects
    if (current_shapes_count < MAX_SHAPES) {
        shapes[current_shapes_count++] = new Circle(5.0);
    }
    if (current_shapes_count < MAX_SHAPES) {
        shapes[current_shapes_count++] = new Rectangle(4.0, 6.0);
    }
    if (current_shapes_count < MAX_SHAPES) {
        shapes[current_shapes_count++] = new Circle(3.0);
    }

    std::cout << "Calculating areas:" << std::endl;
    for (int i = 0; i < current_shapes_count; ++i) {
        std::cout << "Shape " << i + 1 << " Area: " << std::fixed << std::setprecision(4) << shapes[i]->calculateArea() << std::endl;
    }

    // Manual cleanup: iterate and delete each dynamically allocated object
    for (int i = 0; i < current_shapes_count; ++i) {
        delete shapes[i];
        shapes[i] = nullptr; // Good practice to nullify pointer after deletion
    }

    return 0;
}