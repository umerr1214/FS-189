#include <iostream>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed and std::setprecision
#include <vector> // For std::vector to manage shapes polymorphically

// Base class Shape
class Shape {
public:
    // Public method calculateArea, virtual and const
    virtual double calculateArea() const {
        return 0.0;
    }
    // Virtual destructor for proper cleanup of derived objects through base pointers
    virtual ~Shape() {}
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor using member initializer list for efficient initialization
    Circle(double r) : radius(r) {}

    // Overrides calculateArea, marked const to indicate it doesn't modify the object's state
    double calculateArea() const override {
        return M_PI * radius * radius;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // Constructor using member initializer list
    Rectangle(double w, double h) : width(w), height(h) {}

    // Overrides calculateArea, marked const
    double calculateArea() const override {
        return width * height;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(4);

    // Create a vector of Shape pointers to demonstrate polymorphism
    // Using smart pointers (e.g., std::unique_ptr) would be even better for memory management,
    // but raw pointers are used here to keep it simple and directly address the question's core.
    std::vector<Shape*> shapes;

    // Create instances of Circle and Rectangle (on stack)
    Circle circle1(5.0);
    Rectangle rectangle1(4.0, 6.0);
    Circle circle2(3.0);
    Rectangle rectangle2(7.0, 2.0);

    // Add references to the objects to the vector
    shapes.push_back(&circle1);
    shapes.push_back(&rectangle1);
    shapes.push_back(&circle2);
    shapes.push_back(&rectangle2);

    std::cout << "Calculating areas using polymorphism (via Shape pointers):" << std::endl;
    for (const Shape* s : shapes) {
        // Dynamically calls the correct calculateArea method based on the actual object type
        std::cout << "Area: " << s->calculateArea() << std::endl;
    }

    // Direct instantiation and call for clarity
    std::cout << "\nDirect object calls:" << std::endl;
    Circle c_direct(10.0);
    Rectangle r_direct(8.0, 5.0);
    std::cout << "Area of Circle (radius 10.0): " << c_direct.calculateArea() << std::endl; // Expected: 314.1593
    std::cout << "Area of Rectangle (width 8.0, height 5.0): " << r_direct.calculateArea() << std::endl; // Expected: 40.0000

    // No dynamic memory allocation using 'new', so no 'delete' needed for 'shapes' vector elements.

    return 0;
}