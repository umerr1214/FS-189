#define _USE_MATH_DEFINES // Required for M_PI on some compilers (e.g., MSVC)
#include <iostream>
#include <cmath> // For M_PI, std::max
#include <vector>
#include <iomanip> // For std::fixed, std::setprecision
#include <memory> // For std::unique_ptr
#include <algorithm> // For std::max

// Base class definition
class Shape {
public:
    virtual double calculateArea() = 0;
    virtual ~Shape() {}
};

// Derived class definition
class Circle : public Shape {
private:
    double radius;
public:
    // Constructor validates radius to ensure it's non-negative
    Circle(double r) {
        this->radius = std::max(0.0, r); // Ensure radius is not negative
    }

    double calculateArea() override {
        // Efficient and correct calculation using M_PI and direct multiplication
        return M_PI * radius * radius;
    }
};

int main() {
    std::vector<double> test_radii = {5.0, 0.0, 10.0, -2.0}; // -2.0 will be handled robustly
    std::cout << std::fixed << std::setprecision(4);

    for (double r : test_radii) {
        // Using unique_ptr for better memory management
        std::unique_ptr<Shape> circle = std::make_unique<Circle>(r);
        std::cout << "Circle with radius " << r << " has area: " << circle->calculateArea() << std::endl;
    }
    return 0;
}