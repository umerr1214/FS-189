#include <iostream>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed and std::setprecision

// Abstract base class - SEMANTIC ERROR: Not truly abstract as requested
class Shape {
public:
    // SEMANTIC ERROR: calculateArea is virtual, but not pure virtual (= 0).
    // This makes Shape a concrete class, violating the "abstract base class" requirement.
    virtual double calculateArea() {
        return 0.0; // Default implementation, making Shape concrete
    }
    virtual ~Shape() {} // Virtual destructor
};

// Derived Circle class
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    // This correctly overrides the virtual method, but the base class itself is not abstract.
    double calculateArea() override {
        return M_PI * radius * radius;
    }
};

// Derived Rectangle class
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    // This correctly overrides the virtual method.
    double calculateArea() override {
        return width * height;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(15);

    // Driver code for test cases
    // This code will compile and run, but the design of Shape violates the question's requirement.
    Circle c(5.0);
    std::cout << "Circle (radius 5.0) Area: " << c.calculateArea() << std::endl;

    Rectangle r(4.0, 6.0);
    std::cout << "Rectangle (4.0x6.0) Area: " << r.calculateArea() << std::endl;
    
    // Additional test cases
    Circle c2(1.0);
    std::cout << "Circle (radius 1.0) Area: " << c2.calculateArea() << std::endl;

    Rectangle r2(10.0, 2.5);
    std::cout << "Rectangle (10.0x2.5) Area: " << r2.calculateArea() << std::endl;

    return 0;
}