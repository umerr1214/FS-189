#include <iostream>
#include <limits> // Required for numeric_limits

// Function containing the core logic, called by main for testing purposes.
// This version is a correct, robust, and readable implementation.
int solve() {
    int user_number;
    bool is_input_valid;

    do {
        std::cout << "Enter a number between 1 and 10 (inclusive): ";
        std::cin >> user_number;

        is_input_valid = true; // Assume valid initially for this iteration

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear the error flags
            // Ignore remaining characters in the input buffer up to the newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            is_input_valid = false; // Mark as invalid due to type error
        } else if (user_number < 1 || user_number > 10) {
            std::cout << "Invalid input. Please enter a number between 1 and 10.\n";
            is_input_valid = false; // Mark as invalid due to range error
        }
        // No need for else here, if it passed fail() and range check, it's valid.

    } while (!is_input_valid); // Loop continues until valid input (both type and range) is received

    // std::cout << "You entered a valid number: " << user_number << std::endl;
    return user_number;
}

int main() {
    solve();
    return 0;
}