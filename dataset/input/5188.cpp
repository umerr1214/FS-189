#include <iostream>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed and std::setprecision

// Helper function to set output precision for consistency
void set_output_precision() {
    std::cout << std::fixed << std::setprecision(10);
}

// Overloaded function to calculate and print the area of a circle
void printArea(double radius) {
    set_output_precision();
    double area = M_PI * radius * radius;
    std::cout << "Area of circle with radius " << radius << ": " << area << std::endl // SYNTAX ERROR: Missing semicolon here
} // This closing brace will cause a compilation error due to the incomplete statement above

// Overloaded function to calculate and print the area of a rectangle
void printArea(double length, double width) {
    set_output_precision();
    double area = length * width;
    std::cout << "Area of rectangle with length " << length << " and width " << width << ": " << area << std::endl;
}

int main() {
    // Test the circle area function
    printArea(10.0);

    // Test the rectangle area function
    printArea(5.0, 10.0);

    return 0;
}