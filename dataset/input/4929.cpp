#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits

// This is the correct and robust version of the program.
// It handles valid integer input correctly and provides an error message
// for invalid (non-integer) input.
void solve() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    if (std::cin.fail()) {
        // Clear the error flags
        std::cin.clear();
        // Ignore the rest of the invalid line
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer." << std::endl;
    } else {
        if (num > 0) {
            std::cout << "Positive" << std::endl;
        } else if (num < 0) {
            std::cout << "Negative" << std::endl;
        } else { // num must be 0
            std::cout << "Zero" << std::endl;
        }
    }
}