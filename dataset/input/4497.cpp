#include <iostream>
#include <limits> // Required for std::numeric_limits
#include <string>   // Required for std::string

int main() {
    int number;
    std::cout << "Enter an integer: ";

    // Correct version: Includes input validation for robustness and clear logic.
    // Loops until valid integer input is received.
    while (!(std::cin >> number)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear(); // Clear the error flags (e.g., failbit)
        // Discard invalid input from the buffer up to the newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (number > 0) {
        std::cout << "The number is positive." << std::endl;
    } else if (number < 0) {
        std::cout << "The number is negative." << std::endl;
    } else { // number must be 0
        std::cout << "The number is zero." << std::endl;
    }

    return 0;
}