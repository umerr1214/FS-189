#include <iostream>
#include <cmath> // Required for M_PI

class Circle {
private:
    double radius; // Missing semicolon intentionally for syntax error
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

    // Public method to get circumference
    double getCircumference() {
        return 2 * M_PI * radius;
    }
};

int main() {
    // This code block is intended to cause a compilation error
    // due to the syntax error in the Circle class definition.
    // It will not be executed.
    Circle c1(5.0);
    std::cout << "Circle 1 Area: " << c1.getArea() << "\n";
    c1.setRadius(10.0);
    std::cout << "Circle 1 Circumference: " << c1.getCircumference() << "\n";

    return 0;
}