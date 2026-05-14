#include <iostream>
#include <limits> // Required for std::numeric_limits

int user_main() {
    int positiveInteger;

    do {
        std::cout << "Please enter a positive integer: ";

        // Handle non-integer input robustly
        if (!(std::cin >> positiveInteger)) {
            std::cout << "Invalid input. Please enter a numerical value.\n";
            std::cin.clear(); // Clear the error flags (e.g., failbit)
            // Discard invalid input from the buffer to prevent infinite loops
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            positiveInteger = 0; // Set to 0 to ensure the loop continues, as 0 is not a positive integer.
        } else if (positiveInteger <= 0) { // Check if the integer is positive
            std::cout << "The integer must be greater than 0. Please try again.\n";
        }
        // The loop condition `positiveInteger <= 0` effectively covers both cases:
        // 1. `positiveInteger` was set to 0 due to invalid non-numeric input.
        // 2. A valid non-positive number (0 or negative) was entered.
    } while (positiveInteger <= 0); // Loop continues as long as input is not a valid positive integer

    std::cout << "You have entered a valid positive integer: " << positiveInteger << ".\n";
    return 0;
}