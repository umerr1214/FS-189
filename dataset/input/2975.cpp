#include <iostream>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed and std::setprecision

// Define PI if M_PI is not available (e.g., some compilers without strict C++ standard)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() {
        // Logical Error: Swapped the formula for area with circumference
        return 2 * M_PI * radius; // Should be M_PI * radius * radius
    }

    double calculateCircumference() {
        // Logical Error: Swapped the formula for circumference with area
        return M_PI * radius * radius; // Should be 2 * M_PI * radius
    }
};

int main() {
    Circle myCircle(5.0);
    std::cout << std::fixed << std::setprecision(15);
    std::cout << "Area: " << myCircle.calculateArea() << std::endl;
    std::cout << "Circumference: " << myCircle.calculateCircumference() << std::endl;
    return 0;
}