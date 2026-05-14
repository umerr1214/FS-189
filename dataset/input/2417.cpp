#include <iostream>
#include <cmath> // For M_PI

class Shape {
public:
    virtual double calculateArea() {
        return 0.0;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Logical error: calculates perimeter instead of area
    double calculateArea() override {
        return 2 * (length + width); // Should be length * width
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double calculateArea() override {
        return M_PI * radius * radius;
    }
};

int main() {
    Rectangle rect(5.0, 4.0);
    Circle circ(3.0);

    std::cout << "Rectangle Area: " << rect.calculateArea() << std::endl;
    std::cout << "Circle Area: " << circ.calculateArea() << std::endl;

    Rectangle rect2(10.0, 2.5);
    Circle circ2(5.0);
    std::cout << "Rectangle Area: " << rect2.calculateArea() << std::endl;
    std::cout << "Circle Area: " << circ2.calculateArea() << std::endl;

    return 0;
}