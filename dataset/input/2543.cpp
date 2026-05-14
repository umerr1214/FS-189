#include <iostream>
#include <cmath> // For std::acos
#include <iomanip> // For std::fixed, std::setprecision

// Define PI for consistent calculations
const double PI = 3.14159265358979323846;

class Shape {
public:
    virtual double calculateArea() const {
        return 0;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        // Logical Error: Calculating circumference instead of area
        return 2 * PI * radius; // Should be PI * radius * radius;
    }
};

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
    std::cout << std::fixed << std::setprecision(2); // Set precision for output

    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    Shape* s1 = &circle;
    Shape* s2 = &rectangle;

    std::cout << "Circle Area: " << s1->calculateArea() << std::endl;
    std::cout << "Rectangle Area: " << s2->calculateArea() << std::endl;

    Shape baseShape;
    std::cout << "Base Shape Area: " << baseShape.calculateArea() << std::endl;

    return 0;
}