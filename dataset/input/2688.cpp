#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Rectangle {
private:
    double width;
    double height;

public:
    // Parameterized constructor - SEMANTIC ERROR: Does not ensure positive dimensions
    // and does not default to 1.0 for invalid inputs, violating problem constraints.
    Rectangle(double w, double h) {
        width = w;   // Should check w > 0, else default to 1.0
        height = h;  // Should check h > 0, else default to 1.0
    }

    // Calculate area
    double calculateArea() {
        return width * height;
    }

    // Calculate perimeter
    double calculatePerimeter() {
        return 2 * (width + height);
    }
};

int main() {
    // Set precision for output
    std::cout << std::fixed << std::setprecision(1);

    Rectangle r1(5.0, 4.0);
    // Expected Area: 20.0, Expected Perimeter: 18.0. Actual: Correct for given inputs.
    std::cout << "Rectangle(5.0, 4.0) - Area: " << r1.calculateArea() << ", Perimeter: " << r1.calculatePerimeter() << std::endl;

    Rectangle r2(-2.0, 10.0); // Invalid width, but accepted directly.
    // Expected (per question): Area: 10.0, Perimeter: 22.0. Actual: Area: -20.0, Perimeter: 16.0
    std::cout << "Rectangle(-2.0, 10.0) - Area: " << r2.calculateArea() << ", Perimeter: " << r2.calculatePerimeter() << std::endl;

    Rectangle r3(3.0, -5.0); // Invalid height, but accepted directly.
    // Expected (per question): Area: 3.0, Perimeter: 8.0. Actual: Area: -15.0, Perimeter: -4.0
    std::cout << "Rectangle(3.0, -5.0) - Area: " << r3.calculateArea() << ", Perimeter: " << r3.calculatePerimeter() << std::endl;

    Rectangle r4(-1.0, -1.0); // Both invalid, but accepted directly.
    // Expected (per question): Area: 1.0, Perimeter: 4.0. Actual: Area: 1.0, Perimeter: -4.0
    std::cout << "Rectangle(-1.0, -1.0) - Area: " << r4.calculateArea() << ", Perimeter: " << r4.calculatePerimeter() << std::endl;

    return 0;
}