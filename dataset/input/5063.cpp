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
    // LOGICAL ERROR: Perimeter calculated incorrectly (missing multiplication by 2)
    double perimeter = length + width; 

    // Set output format for two decimal places
    std::cout << std::fixed << std::setprecision(2);

    // Print results
    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;
}