#include <iostream>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed, std::setprecision

// Base class
class Shape {
public:
    virtual double calculateArea() const {
        return 0.0;
    }
    virtual ~Shape() = default;
};

// Derived class Square
class Square : public Shape {
private:
    double side;
public:
    // Robustness issue: No input validation for 's'.
    // A negative 's' will result in a mathematically positive but conceptually incorrect area.
    Square(double s) : side(s) {}

    double calculateArea() const override {
        return side * side;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    // Robustness issue: No input validation for 'r'.
    // A negative 'r' will result in a mathematically positive but conceptually incorrect area.
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return M_PI * radius * radius;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(10);

    // Demonstrating the robustness issue with negative dimensions
    Square s1(5.0);
    Circle c1(3.0);
    Square s2(-4.0); // Invalid input, but program proceeds to calculate area
    Circle c2(-2.5); // Invalid input, but program proceeds to calculate area

    std::cout << s1.calculateArea() << std::endl;
    std::cout << c1.calculateArea() << std::endl;
    std::cout << s2.calculateArea() << std::endl; // Returns 16.0
    std::cout << c2.calculateArea() << std::endl; // Returns M_PI * 6.25

    Shape base_shape;
    std::cout << base_shape.calculateArea() << std::endl;

    return 0;
}