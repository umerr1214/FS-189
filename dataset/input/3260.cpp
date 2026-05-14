#include <iostream>
#include <vector>
#include <string>
#include <cmath> // For M_PI if needed, or define PI

// Base class
class Shape {
public:
    virtual double calculateArea() const = 0; // Pure virtual function
    virtual ~Shape() {
        // std::cout << "Shape destructor called." << std::endl;
    } // Virtual destructor for proper cleanup
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        return M_PI * radius * radius; // Using M_PI from cmath
    }
    ~Circle() override {
        // std::cout << "Circle destructor called." << std::endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() const override {
        return width * height;
    }
    ~Rectangle() override {
        // std::cout << "Rectangle destructor called." << std::endl;
    }
};

const int MAX_SHAPES = 10; // Fixed size for the raw array

int main() {
    Shape* shapes[MAX_SHAPES]; // Using a raw C-style array
    int shapeCount = 0;

    // Populate the collection with a mix of Circle and Rectangle objects
    if (shapeCount < MAX_SHAPES) {
        shapes[shapeCount++] = new Circle(5.0);
    }
    if (shapeCount < MAX_SHAPES) {
        shapes[shapeCount++] = new Rectangle(4.0, 6.0);
    }
    if (shapeCount < MAX_SHAPES) {
        shapes[shapeCount++] = new Circle(2.5);
    }
    if (shapeCount < MAX_SHAPES) {
        shapes[shapeCount++] = new Rectangle(7.0, 3.0);
    }
    if (shapeCount < MAX_SHAPES) {
        shapes[shapeCount++] = new Circle(10.0);
    }

    std::cout << "Calculating areas:" << std::endl;

    // Iterate and call calculateArea() on each using base class pointers
    for (int i = 0; i < shapeCount; ++i) {
        std::cout << "Area: " << shapes[i]->calculateArea() << std::endl;
    }

    // Manually deallocate memory
    for (int i = 0; i < shapeCount; ++i) {
        delete shapes[i];
        shapes[i] = nullptr; // Good practice to nullify after deletion
    }

    return 0;
}