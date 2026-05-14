#include <iostream>
#include <algorithm> // For std::max

class Rectangle {
private:
    double width;
    double height;

public:
    // Parameterized constructor with input validation for robustness
    Rectangle(double w, double h) {
        width = std::max(0.0, w); // Ensure width is non-negative
        height = std::max(0.0, h); // Ensure height is non-negative
    }

    // Public method to get the area
    double getArea() const {
        return width * height;
    }
};

int main() {
    // Test cases for Correct Version
    Rectangle r1(15.0, 3.0);
    std::cout << "Area for (15.0, 3.0): " << r1.getArea() << std::endl;

    Rectangle r2(1.0, 1.0);
    std::cout << "Area for (1.0, 1.0): " << r2.getArea() << std::endl;

    Rectangle r3(0.0, 8.0); // Edge case: zero width
    std::cout << "Area for (0.0, 8.0): " << r3.getArea() << std::endl;

    Rectangle r4(-5.0, 2.0); // Input validation handles negative width
    std::cout << "Area for (-5.0, 2.0): " << r4.getArea() << std::endl; // Expected to be 0.0

    Rectangle r5(7.5, 2.5);
    std::cout << "Area for (7.5, 2.5): " << r5.getArea() << std::endl;

    return 0;
}