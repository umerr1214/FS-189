#include <iostream>
#include <cmath> // For M_PI

// Overloaded function to calculate and print the area of a circle
// Lacks robustness: does not handle negative radius gracefully.
void printArea(double radius) {
    // Calculates area even if radius is negative, resulting in a positive area.
    // A robust solution would validate input (e.g., if (radius < 0) { ... }).
    double area = M_PI * radius * radius;
    std::cout << "Circle area with radius " << radius << ": " << area << std::endl;
}

// Overloaded function to calculate and print the area of a rectangle
// Lacks robustness: does not handle negative length or width gracefully.
void printArea(double length, double width) {
    // Calculates area even if length or width is negative, resulting in potentially
    // negative or unexpected area. A robust solution would validate inputs.
    double area = length * width;
    std::cout << "Rectangle area with length " << length << " and width " << width << ": " << area << std::endl;
}

int main() {
    std::cout << "Testing overloaded printArea functions (Robustness Issue version):" << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;

    // Test cases for circle
    printArea(5.0);   // Valid radius
    printArea(10.0);  // Valid radius
    printArea(-3.0);  // Robustness issue: negative radius treated as positive for calculation

    std::cout << std::endl;

    // Test cases for rectangle
    printArea(4.0, 6.0);   // Valid dimensions
    printArea(7.5, 2.0);   // Valid dimensions
    printArea(-5.0, 4.0);  // Robustness issue: negative length
    printArea(3.0, -2.0);  // Robustness issue: negative width

    return 0;
}