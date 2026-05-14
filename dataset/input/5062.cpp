#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

void solution_main() {
    double length, width;

    // Prompt for input
    std::cout << "Enter length: ";
    std::cin >> length;

    std::cout << "Enter width: ";
    std::cin >> width;

    // Calculate area and perimeter
    double area = length * width;
    double perimeter = 2 * (length + width);

    // Set output format for two decimal places
    std::cout << std::fixed << std::setprecision(2);

    // Print results (SYNTAX ERROR: Missing semicolon)
    std::cout << "Area: " << area << std::endl
    std::cout << "Perimeter: " << perimeter << std::endl;
}