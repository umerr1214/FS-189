#include <iostream>
#include <cmath> // For std::pow
#include <vector>
#include <iomanip>
#include <memory>

// Base class definition
class Shape {
public:
    virtual double calculateArea() = 0;
    virtual ~Shape() {}
};

// Define a magic number for PI, which is less precise and less readable
const double MY_PI_VALUE = 3.14159;

// Derived class definition
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double calculateArea() override {
        // Inefficient: std::pow for squaring is generally slower than direct multiplication
        return MY_PI_VALUE * std::pow(radius, 2.0);
    }
};

int main() {
    std::vector<double> test_radii = {5.0, 0.0, 10.0, -2.0};
    std::cout << std::fixed << std::setprecision(5); // Increased precision to show difference with M_PI

    for (double r : test_radii) {
        std::unique_ptr<Shape> circle = std::make_unique<Circle>(r);
        std::cout << "Circle with radius " << r << " has area: " << circle->calculateArea() << std::endl;
    }
    return 0;
}