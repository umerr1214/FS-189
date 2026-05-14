#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision
#include <limits>  // Required for std::numeric_limits

int main() {
    double monetaryValue; // Descriptive variable name
    
    std::cout << "Enter monetary value: ";
    std::cin >> monetaryValue;

    // Correct version: Robust input handling
    if (std::cin.fail()) {
        std::cerr << "Invalid input. Please enter a numeric monetary value." << std::endl;
        // Clear error flags and ignore remaining bad input for potential further use,
        // though for this simple program, exiting is appropriate.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1; // Indicate an error
    }

    // Print the value formatted to two decimal places, prefixed with a dollar sign
    // Using C++ iostream manipulators for clear and type-safe formatting
    std::cout << std::fixed << std::setprecision(2) << "$" << monetaryValue << std::endl;

    return 0; // Indicate success
}