#include <iostream>

int main() {
    double length, width;

    // Prompt for length
    std::cout << "Enter the length of the rectangle: ";
    std::cin >> length;

    // Prompt for width
    std::cout << "Enter the width of the rectangle: ";
    std::cin >> width;

    // Calculate area and perimeter
    // Robustness Issue: No input validation for negative or zero dimensions.
    // The program will calculate and display results even for non-physical dimensions.
    double area = length * width;
    double perimeter = 2 * (length + width);

    // Display results
    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;

    return 0;
}