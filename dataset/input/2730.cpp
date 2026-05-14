#include <iostream>

// Base class Shape
class Shape {
public:
    // Semantic error: calculateArea is NOT virtual.
    // This prevents polymorphic behavior when accessed via base class pointers.
    double calculateArea() const { 
        return 0.0;
    }
    virtual ~Shape() {} // Virtual destructor is still good practice for base classes
};

// Derived class Square
class Square : public Shape {
public:
    double side;

    Square(double s) : side(s) {}

    // This 'override' keyword is valid, but since the base method isn't virtual,
    // this function merely hides Shape::calculateArea() rather than overriding it polymorphically.
    double calculateArea() const override {
        return side * side;
    }
};

// Derived class Circle
class Circle : public Shape {
public:
    double radius;

    Circle(double r) : radius(r) {}

    // Same as Square, this hides the base method.
    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
};

int main() {
    // Create objects
    Square s(5.0);
    Circle c(3.0);

    // Use base class pointers to demonstrate the semantic error
    Shape* shape1 = &s;
    Shape* shape2 = &c;

    // Due to calculateArea not being virtual in Shape, these calls will invoke
    // Shape::calculateArea(), which returns 0.0, instead of the derived class's methods.
    std::cout << "Area of Square: " << shape1->calculateArea() << std::endl; // Expected: 25.0, Actual: 0.0
    std::cout << "Area of Circle: " << shape2->calculateArea() << std::endl; // Expected: 28.27431, Actual: 0.0

    // To show the derived methods themselves work if called directly:
    // std::cout << "Direct Square Area: " << s.calculateArea() << std::endl;
    // std::cout << "Direct Circle Area: " << c.calculateArea() << std::endl;

    return 0;
}