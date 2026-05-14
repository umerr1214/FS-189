#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int number;

    do {
        std::cout << "Enter a positive integer: ";
        std::cin >> number;

        if (std::cin.fail()) { // Check if the input operation failed (e.g., non-integer input)
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear(); // Clear the error flags on std::cin
            // Discard the rest of the current line from the input buffer to prevent
            // infinite loops on bad input.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (number <= 0) { // Check if the integer is positive
            std::cout << "Invalid input. Please enter a positive integer.\n";
        }
        // The loop continues if std::cin is in a failed state OR if the number is not positive.
    } while (std::cin.fail() || number <= 0);

    std::cout << "You have entered a valid positive integer: " << number << std::endl;

    return 0;
}