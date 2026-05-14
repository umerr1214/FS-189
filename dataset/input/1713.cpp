#include <iostream>
#include <vector>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed, std::setprecision

// Define M_PI if not available (e.g., on some compilers or specific flags)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Base class Shape
class Shape {
public:
    // CORRECT VERSION: calculateArea() is a pure virtual const method.
    // 'const' indicates it does not modify the object's state.
    virtual double calculateArea() const = 0;
    // CORRECT VERSION: Destructor is virtual, ensuring proper cleanup of derived objects.
    virtual ~Shape() = default; // Use default for simple destructors
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    // CORRECT VERSION: Overrides the const virtual method.
    double calculateArea() const override {
        return M_PI * radius * radius;
    }
    // No specific destructor needed as Circle manages no special resources.
};

// Derived class Square
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    // CORRECT VERSION: Overrides the const virtual method.
    double calculateArea() const override {
        return side * side;
    }
    // No specific destructor needed as Square manages no special resources.
};

int main() {
    // Set output precision for consistent results
    std::cout << std::fixed << std::setprecision(4);

    // Create a std::vector of Shape* pointers
    std::vector<Shape*> shapes;

    // Populate the vector with dynamically allocated Circle and Square objects
    shapes.push_back(new Circle(5.0)); // Circle with radius 5.0
    shapes.push_back(new Square(4.0)); // Square with side 4.0
    shapes.push_back(new Circle(2.5)); // Circle with radius 2.5

    std::cout << "Demonstrating runtime polymorphism by calculating areas:\n";
    // Iterate through the vector using a range-based for loop
    // Call calculateArea() for each object, demonstrating runtime polymorphism
    for (const Shape* s : shapes) { // Use const Shape* as calculateArea is const
        // Dynamically cast to check type for printing descriptive names (optional, but good for output)
        if (dynamic_cast<const Circle*>(s)) {
            std::cout << "Circle area: " << s->calculateArea() << "\n";
        } else if (dynamic_cast<const Square*>(s)) {
            std::cout << "Square area: " << s->calculateArea() << "\n";
        } else {
            std::cout << "Unknown shape area: " << s->calculateArea() << "\n";
        }
    }

    // Clean up dynamically allocated objects to prevent memory leaks
    // This correctly calls the appropriate derived class destructor due to virtual ~Shape()
    for (Shape* s : shapes) {
        delete s;
    }
    shapes.clear(); // Clear the vector after deleting pointers

    return 0;
}