#include <iostream>
#include <cmath> // For M_PI
#include <vector>
#include <iomanip> // For std::fixed, std::setprecision

// Base class Shape
class Shape {
public:
    virtual double calculateArea() const {
        return 0.0;
    }
    virtual ~Shape() = default; // Virtual destructor for proper cleanup
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Robustness Issue: Does not handle negative dimensions;
    // will return a negative area if one dimension is negative,
    // which is physically incorrect.
    double calculateArea() const override {
        return width * height;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    // Robustness Issue: Does not handle negative radius gracefully;
    // M_PI * r * r will result in a positive area even for negative r,
    // which is physically nonsensical for a real-world radius.
    double calculateArea() const override {
        return M_PI * radius * radius;
    }
};

// Driver code for test cases
int main() {
    std::cout << std::fixed << std::setprecision(2);

    // Test Case 1: Valid Rectangle
    Rectangle rect1(5.0, 4.0);
    std::cout << "Rectangle (5x4) area: " << rect1.calculateArea() << std::endl;

    // Test Case 2: Rectangle with one negative dimension (Robustness Issue)
    Rectangle rect2(-5.0, 4.0);
    std::cout << "Rectangle (-5x4) area: " << rect2.calculateArea() << std::endl;

    // Test Case 3: Valid Circle
    Circle circ1(3.0);
    std::cout << "Circle (radius 3) area: " << circ1.calculateArea() << std::endl;

    // Test Case 4: Circle with negative radius (Robustness Issue)
    Circle circ2(-3.0);
    std::cout << "Circle (radius -3) area: " << circ2.calculateArea() << std::endl;

    // Test Case 5: Polymorphic call with valid dimensions
    std::vector<Shape*> shapes;
    shapes.push_back(new Rectangle(10.0, 2.0));
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(-2.0, 3.0)); // Robustness issue here too
    shapes.push_back(new Circle(-4.0)); // Robustness issue here too

    for (const auto& shape : shapes) {
        std::cout << "Polymorphic Shape Area: " << shape->calculateArea() << std::endl;
    }

    // Clean up
    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}