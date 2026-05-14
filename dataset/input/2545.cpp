#include <iostream>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed and std::setprecision

// Base class Shape
class Shape {
public:
    virtual double calculateArea() const {
        return 0.0;
    }
    virtual ~Shape() {} // Virtual destructor for proper cleanup
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor allows negative radius, demonstrating robustness issue
    Circle(double r) : radius(r) {}

    // Overrides calculateArea to compute circle's area
    // Does not validate radius, leading to unexpected results if radius is conceptually invalid (e.g., negative).
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
    // Constructor allows negative width/height, demonstrating robustness issue
    Rectangle(double w, double h) : width(w), height(h) {}

    // Overrides calculateArea to compute rectangle's area
    // Does not validate width or height, can return negative area which is physically impossible.
    double calculateArea() const override {
        return width * height;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(4);

    // Demonstrate correct usage with valid dimensions
    Circle c1(5.0);
    Rectangle r1(4.0, 6.0);

    std::cout << "Area of Circle (radius 5.0): " << c1.calculateArea() << std::endl;
    std::cout << "Area of Rectangle (width 4.0, height 6.0): " << r1.calculateArea() << std::endl;
    std::cout << std::endl;

    // Demonstrate robustness issue with negative dimensions
    // The program computes a value but it's physically nonsensical for an area
    Circle c2(-3.0); // A negative radius
    Rectangle r2(-2.0, 5.0); // A negative width, results in negative area
    Rectangle r3(-2.0, -4.0); // Both negative, results in positive area

    std::cout << "Robustness Issue Demonstration:" << std::endl;
    std::cout << "Area of Circle (radius -3.0): " << c2.calculateArea() << std::endl; // Area will be positive, but input was invalid
    std::cout << "Area of Rectangle (width -2.0, height 5.0): " << r2.calculateArea() << std::endl; // Area will be negative
    std::cout << "Area of Rectangle (width -2.0, height -4.0): " << r3.calculateArea() << std::endl; // Area will be positive, but inputs were invalid

    // Using Shape pointers to show polymorphic behavior with problematic inputs
    Shape* s1 = &c1;
    Shape* s2 = &r1;
    Shape* s3 = &c2;
    Shape* s4 = &r2;

    std::cout << "\nUsing Shape pointers (some with invalid dimensions):" << std::endl;
    std::cout << "Area (Shape* to Circle 5.0): " << s1->calculateArea() << std::endl;
    std::cout << "Area (Shape* to Rectangle 4.0x6.0): " << s2->calculateArea() << std::endl;
    std::cout << "Area (Shape* to Circle -3.0): " << s3->calculateArea() << std::endl;
    std::cout << "Area (Shape* to Rectangle -2.0x5.0): " << s4->calculateArea() << std::endl;

    return 0;
}