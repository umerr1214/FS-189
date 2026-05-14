#include <iostream>
#include <cmath> // Required for M_PI
#include <iomanip> // Required for std::fixed and std::setprecision

// Define M_PI if not reliably available from <cmath> (e.g., on some older compilers or configurations)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Circle {
private:
    double radius;
public:
    // Constructor
    Circle(double r) {
        if (r > 0) {
            radius = r;
        } else {
            radius = 1.0; // Default to 1.0 if initial radius is non-positive
            std::cout << "Warning: Initial radius must be positive. Setting to 1.0.\n";
        }
    }

    // Public method to set radius, only accepts positive values
    void setRadius(double r) {
        if (r > 0) {
            radius = r;
        } else {
            std::cout << "Radius must be positive. Not setting radius. Current radius: " << radius << "\n";
        }
    }

    // Public method to get area
    double getArea() {
        return M_PI * radius * radius;
    }

    // Public method to get circumference (LOGICAL ERROR: returns area instead of circumference)
    double getCircumference() {
        return M_PI * radius * radius; // Incorrect formula: should be 2 * M_PI * radius;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(10);

    Circle c1(5.0);
    std::cout << "--- Circle with radius 5.0 ---\n";
    std::cout << "Actual Area: " << c1.getArea() << "\n";
    std::cout << "Expected Area: " << M_PI * 5.0 * 5.0 << "\n";
    std::cout << "Actual Circumference (Logical Error): " << c1.getCircumference() << "\n";
    std::cout << "Expected Circumference: " << 2 * M_PI * 5.0 << "\n\n";

    c1.setRadius(10.0);
    std::cout << "--- Circle with radius 10.0 ---\n";
    std::cout << "Actual Area: " << c1.getArea() << "\n";
    std::cout << "Expected Area: " << M_PI * 10.0 * 10.0 << "\n";
    std::cout << "Actual Circumference (Logical Error): " << c1.getCircumference() << "\n";
    std::cout << "Expected Circumference: " << 2 * M_PI * 10.0 << "\n\n";

    c1.setRadius(-2.0); // Should not change radius
    std::cout << "--- Attempt to set radius to -2.0 ---\n";
    std::cout << "Current Radius: " << c1.getArea() / M_PI / c1.getArea() * c1.getArea() << " (derived from area, should be 10.0)\n"; // A bit convoluted to get radius back
    std::cout << "Actual Area: " << c1.getArea() << "\n";
    std::cout << "Actual Circumference (Logical Error): " << c1.getCircumference() << "\n";

    return 0;
}