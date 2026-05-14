#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

void solution_main() {
    // SEMANTIC ERROR: Using int for real-world measurements, leading to truncation
    int length, width; 

    // Prompt for input
    std::cout << "Enter length: ";
    std::cin >> length;

    std::cout << "Enter width: ";
    std::cin >> width;

    // Calculate area and perimeter using integer types
    int area = length * width;
    int perimeter = 2 * (length + width);

    // Set output format for two decimal places (will apply to integer values if printed as doubles)
    std::cout << std::fixed << std::setprecision(2);

    // Print results
    std::cout << "Area: " << static_cast<double>(area) << std::endl; // Cast to double for formatted output
    std::cout << "Perimeter: " << static_cast<double>(perimeter) << std::endl; // Cast to double for formatted output
}