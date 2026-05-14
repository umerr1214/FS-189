#include <iostream>
#include <cmath> // For M_PI

// Base Shape class
class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual ~Shape() {}
};

// Circle class from Q7
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        return M_PI * radius * radius;
    }
};

// Rectangle class derived from Shape
class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double calculateArea() const override {
        return length * width;
    }
}; // SYNTAX ERROR: Missing semicolon here

// Function demonstrating runtime polymorphism
void demonstratePolymorphism(Shape* shapePtr) {
    std::cout << "Calling calculateArea() via Shape pointer." << std::endl;
    std::cout << "Calculated Area: " << shapePtr->calculateArea() << std::endl;
}

int main() {
    Circle myCircle(5.0);
    Rectangle myRectangle(4.0, 6.0);

    std::cout << "Demonstrating with Circle (radius=5.0):" << std::endl;
    demonstratePolymorphism(&myCircle);

    std::cout << "\nDemonstrating with Rectangle (length=4.0, width=6.0):" << std::endl;
    demonstratePolymorphism(&myRectangle);

    return 0;
}