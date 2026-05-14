#include <iostream>
#include <cmath>    // For acos and pow
#include <iomanip>  // For std::fixed, std::setprecision

class Circle {
private:
    double radius;

public:
    // Constructor
    Circle(double r) {
        // Unnecessarily verbose initialization
        this->radius = r;
    }

    // Method to calculate area with readability/efficiency issues
    double calculateArea() {
        // Redundant PI calculation in each call
        const double PI_VAL = std::acos(-1.0);
        // Less efficient than radius * radius
        return PI_VAL * std::pow(radius, 2);
    }

    // Method to calculate circumference with readability/efficiency issues
    double calculateCircumference() {
        // Redundant PI calculation in each call
        const double PI_VALUE = std::acos(-1.0);
        return 2 * PI_VALUE * radius;
    }
};

int main() {
    Circle myCircle(10.0); // Using a different radius for variety
    std::cout << "Circle (radius 10.0):" << std::endl;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "  Area: " << myCircle.calculateArea() << std::endl;
    std::cout << "  Circumference: " << myCircle.calculateCircumference() << std::endl;

    return 0;
}