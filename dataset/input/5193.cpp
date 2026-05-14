#include <iostream>
#include <cmath> // Required for M_PI constant

// Overloaded function to calculate and print the area of a circle.
// Takes radius as input.
void printArea(double radius) {
    // Ensure radius is non-negative for a meaningful area.
    if (radius < 0) {
        std::cout << "Error: Radius cannot be negative." << std::endl;
        return;
    }
    double area = M_PI * radius * radius;
    std::cout << "Area of a circle with radius " << radius << ": " << area << std::endl;
}

// Overloaded function to calculate and print the area of a rectangle.
// Takes length and width as input.
void printArea(double length, double width) {
    // Ensure dimensions are non-negative for a meaningful area.
    if (length < 0 || width < 0) {
        std::cout << "Error: Length and width cannot be negative." << std::endl;
        return;
    }
    double area = length * width;
    std::cout << "Area of a rectangle with length " << length << " and width " << width << ": " << area << std::endl;
}

int main() {
    std::cout << "Testing overloaded printArea functions (Correct Version):" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    // Test cases for circle area
    printArea(5.0);   // Valid radius
    printArea(10.0);  // Valid radius
    printArea(0.0);   // Zero radius
    printArea(-3.0);  // Invalid radius, handled gracefully

    std::cout << std::endl;

    // Test cases for rectangle area
    printArea(4.0, 6.0);   // Valid dimensions
    printArea(7.5, 2.0);   // Valid dimensions
    printArea(0.0, 5.0);   // Zero length
    printArea(5.0, 0.0);   // Zero width
    printArea(-5.0, 4.0);  // Invalid length, handled gracefully
    printArea(3.0, -2.0);  // Invalid width, handled gracefully

    return 0;
}