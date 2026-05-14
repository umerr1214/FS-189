#include <iostream>
#include <cmath> // For M_PI

// Base class
class Shape {
public:
    // Virtual method
    virtual double calculateArea() {
        return 0.0;
    }
} // SYNTAX ERROR: Missing semicolon here

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    // Override calculateArea
    double calculateArea() override {
        return width * height;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    // Override calculateArea
    double calculateArea() override {
        return M_PI * radius * radius;
    }
};

int main() {
    Rectangle rect(4, 5);
    Circle circle(3);

    std::cout << "Rectangle Area: " << rect.calculateArea() << std::endl;
    std::cout << "Circle Area: " << circle.calculateArea() << std::endl;

    Shape* s1 = &rect;
    Shape* s2 = &circle;
    std::cout << "Shape* to Rectangle Area: " << s1->calculateArea() << std::endl;
    std::cout << "Shape* to Circle Area: " << s2->calculateArea() << std::endl;

    return 0;
}