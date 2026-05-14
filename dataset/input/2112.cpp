#include <iostream>
#include <vector>
#include <iomanip> // For std::fixed and std::setprecision

// Base class
class Shape {
public:
    // SEMANTIC ERROR: 'virtual' keyword is missing for calculateArea.
    // This will lead to static dispatch instead of runtime polymorphism.
    double calculateArea() const {
        // This default implementation will be called for all objects
        // when accessed via Shape* pointers, defeating polymorphism.
        std::cout << "DEBUG: Calling Shape::calculateArea() (non-polymorphic default)." << std::endl;
        return 0.0; // Placeholder value
    }
    virtual ~Shape() {} // Destructor should still be virtual for proper memory cleanup
};

// Derived class 1
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    // No 'override' here, as the base function is not virtual.
    // This is a new function that 'hides' Shape::calculateArea.
    double calculateArea() const {
        return width * height;
    }
};

// Derived class 2
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    // No 'override' here, as the base function is not virtual.
    // This is a new function that 'hides' Shape::calculateArea.
    double calculateArea() const {
        return 3.14159 * radius * radius;
    }
};

int main() {
    std::vector<Shape*> shapes;

    shapes.push_back(new Rectangle(5, 4)); // Intended area: 20
    shapes.push_back(new Circle(3));       // Intended area: 28.27431
    shapes.push_back(new Rectangle(2, 10)); // Intended area: 20

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Demonstrating non-polymorphic behavior:" << std::endl;
    for (size_t i = 0; i < shapes.size(); ++i) {
        // Because Shape::calculateArea() is not virtual, this will always call
        // the base class's calculateArea() function (static dispatch).
        std::cout << "Shape " << i + 1 << " area: " << shapes[i]->calculateArea() << std::endl;
    }

    // Clean up memory to prevent leaks
    for (Shape* s : shapes) {
        delete s;
    }
    shapes.clear();

    return 0;
}