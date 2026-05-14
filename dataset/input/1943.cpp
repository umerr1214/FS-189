#include <iostream>
#include <cmath> // For M_PI

class Shape {
public:
    virtual double calculateArea() = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() override {
        return radius * radius; // Logical Error: Missing M_PI for area calculation
    }
};

int main() {
    std::cout.precision(4);
    std::cout << std::fixed;

    // Test Case 1: Circle with radius 5.0
    Circle c1(5.0);
    std::cout << "Area of circle with radius 5.0: " << c1.calculateArea() << std::endl;

    // Test Case 2: Circle with radius 10.0
    Circle c2(10.0);
    std::cout << "Area of circle with radius 10.0: " << c2.calculateArea() << std::endl;

    // Test Case 3: Circle with radius 0.0
    Circle c3(0.0);
    std::cout << "Area of circle with radius 0.0: " << c3.calculateArea() << std::endl;

    return 0;
}