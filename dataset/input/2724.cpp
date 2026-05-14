#include <iostream>
#include <cmath> // Required for M_PI
#include <iomanip> // Required for std::fixed and std::setprecision

// Define M_PI if not reliably available from <cmath>
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

    // Public method to set radius (SEMANTIC ERROR: accepts 0, which is not strictly positive)
    void setRadius(double r) {
        if (r >= 0) { // Should be r > 0 for strictly positive
            radius = r;
        } else {
            std::cout << "Radius must be positive. Not setting radius. Current radius: " << radius << "\n";
        }
    }

    // Public method to get area
    double getArea() {
        return M_PI * radius * radius;
    }

    // Public method to get circumference
    double getCircumference() {
        return 2 * M_PI * radius;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(10);

    Circle c1(5.0);
    std::cout << "--- Circle with initial radius 5.0 ---\n";
    std::cout << "Area: " << c1.getArea() << "\n";
    std::cout << "Circumference: " << c1.getCircumference() << "\n\n";

    c1.setRadius(10.0);
    std::cout << "--- Circle after setting radius to 10.0 ---\n";
    std::cout << "Area: " << c1.getArea() << "\n";
    std::cout << "Circumference: " << c1.getCircumference() << "\n\n";

    c1.setRadius(0.0); // This should ideally be rejected as 0 is not positive
    std::cout << "--- Circle after setting radius to 0.0 (Semantic Error) ---\n";
    std::cout << "Area: " << c1.getArea() << "\n";
    std::cout << "Circumference: " << c1.getCircumference() << "\n\n";

    c1.setRadius(-5.0); // This should be rejected correctly
    std::cout << "--- Circle after attempting to set radius to -5.0 ---\n";
    std::cout << "Area: " << c1.getArea() << "\n";
    std::cout << "Circumference: " << c1.getCircumference() << "\n";

    return 0;
}