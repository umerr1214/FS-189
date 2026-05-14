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
    std::cout << "Area of circle with radius " << radius << ": " << area << std::endl;
}

// Overloaded function to calculate and print the area of a rectangle
void printArea(double length, double width) {
    set_output_precision();
    double area = length * width;
    std::cout << "Area of rectangle with length " << length << " and width " << width << ": " << area << std::endl;
}

int main() {
    // Test the circle area function
    // SEMANTIC ERROR: Attempting to assign the result of a void function to a double variable.
    // printArea returns void, so it cannot be assigned.
    double circle_area_result = printArea(10.0); 

    // Test the rectangle area function
    // SEMANTIC ERROR: Same error for the rectangle function call.
    double rect_area_result = printArea(5.0, 10.0); 

    // If the semantic errors above were fixed (by removing the assignments),
    // the program would print the areas as intended.

    return 0;
}