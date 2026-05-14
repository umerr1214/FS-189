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

    double calculateArea() override {
        return length * width;
    }
}; // Missing semicolon here intentionally for syntax error

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

    return 0;
}