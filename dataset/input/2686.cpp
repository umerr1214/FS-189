#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Rectangle {
private:
    double width;
    double height;

public:
    // Parameterized constructor
    Rectangle(double w, double h) {
        if (w > 0) {
            width = w;
        } else {
            width = 1.0;
        }
        if (h > 0) {
            height = h;
        } else {
            height = 1.0;
        }
    }

    // Calculate area
    double calculateArea() {
        return width * height;
    }

    // Calculate perimeter - SYNTAX ERROR: Missing opening brace '{'
    double calculatePerimeter()
        return 2 * (width + height);
    }
};

int main() {
    // Set precision for output
    std::cout << std::fixed << std::setprecision(1);

    Rectangle r1(5.0, 4.0);
    std::cout << "Rectangle(5.0, 4.0) - Area: " << r1.calculateArea() << ", Perimeter: " << r1.calculatePerimeter() << std::endl;

    Rectangle r2(-2.0, 10.0); // Invalid width, should default to 1.0
    std::cout << "Rectangle(-2.0, 10.0) - Area: " << r2.calculateArea() << ", Perimeter: " << r2.calculatePerimeter() << std::endl;

    Rectangle r3(3.0, -5.0); // Invalid height, should default to 1.0
    std::cout << "Rectangle(3.0, -5.0) - Area: " << r3.calculateArea() << ", Perimeter: " << r3.calculatePerimeter() << std::endl;

    Rectangle r4(-1.0, -1.0); // Both invalid, should default to 1.0, 1.0
    std::cout << "Rectangle(-1.0, -1.0) - Area: " << r4.calculateArea() << ", Perimeter: " << r4.calculatePerimeter() << std::endl;

    return 0;
}