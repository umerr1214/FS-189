#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int number;

    do {
        std::cout << "Enter a positive integer: ";
        std::cin >> number; // This operation will fail if non-integer input is provided

        // Robustness Issue:
        // If non-integer input is given (e.g., "abc"), std::cin.fail() will be true.
        // However, this code does NOT clear the error state of std::cin
        // nor does it discard the invalid input from the buffer.
        // As a result, if a non-integer is entered, the loop will become infinite,
        // continuously re-evaluating std::cin >> number, which will immediately fail
        // again without waiting for new user input.
        if (number <= 0) {
            std::cout << "Invalid input. Please enter a positive integer.\n";
        }
        // Missing: std::cin.clear() and std::cin.ignore() for handling non-integer input.
    } while (number <= 0); // This condition alone is insufficient for robust validation against non-integers

    std::cout << "You entered a valid positive integer: " << number << std::endl;

    return 0;
}