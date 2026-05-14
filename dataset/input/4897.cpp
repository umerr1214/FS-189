#include <iostream>
#include <cmath> // For M_PI, though we'll use a literal for robustness issue
#include <limits> // Required for numeric_limits
#include <string>

// Overloaded function for circle area
double calculateArea(double radius) {
    // No validation for negative radius - robustness issue
    return 3.14159 * radius * radius; // Using a literal directly
}

// Overloaded function for rectangle area
double calculateArea(double length, double width) {
    // No validation for negative length/width - robustness issue
    return length * width;
}

int main() {
    int choice;
    double val1, val2;

    std::cout << "Choose an area to calculate:\n";
    std::cout << "1. Circle (radius)\n";
    std::cout << "2. Rectangle (length, width)\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice; // Robustness issue: No input validation for non-numeric input

    // If non-numeric input, cin fails, choice is garbage, and subsequent cin might fail
    // or enter infinite loop if not cleared.
    // Also, if choice is invalid, it proceeds with uninitialized val1/val2 or incorrect logic.

    if (choice == 1) {
        std::cout << "Enter the radius of the circle: ";
        std::cin >> val1; // Robustness issue: No input validation for non-numeric input
        // No check for negative radius
        std::cout << "Area of the circle: " << calculateArea(val1) << std::endl;
    } else if (choice == 2) {
        std::cout << "Enter the length of the rectangle: ";
        std::cin >> val1; // Robustness issue: No input validation for non-numeric input
        std::cout << "Enter the width of the rectangle: ";
        std::cin >> val2; // Robustness issue: No input validation for non-numeric input
        // No check for negative length/width
        std::cout << "Area of the rectangle: " << calculateArea(val1, val2) << std::endl;
    } else {
        std::cout << "Invalid choice. Please enter 1 or 2.\n";
    }

    // If input fails, std::cin is in a bad state, and subsequent operations might fail.
    // No clearing of error state or ignoring remaining input.

    return 0;
}