#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    double length = 0.0, width = 0.0; // Initialize to 0.0 for predictable behavior on input failure

    // Prompt for length
    std::cout << "Enter the length of the rectangle: ";
    std::cin >> length;

    // This program does not handle non-numeric input for width.
    // If a non-numeric value is entered, std::cin will enter a fail state,
    // and 'width' will retain its initialized value (0.0).
    // The program will proceed with calculation without warning the user.
    std::cout << "Enter the width of the rectangle: ";
    std::cin >> width;

    // Calculate area and perimeter
    double area = length * width;
    double perimeter = 2 * (length + width);

    // Display results formatted to two decimal places
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;

    return 0;
}