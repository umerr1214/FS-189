#include <iostream>
#include <limits> // Required for numeric_limits

// Function containing the core logic, called by main for testing purposes.
// This version is functionally correct and handles various inputs,
// but suffers from readability and minor efficiency issues.
int solve() {
    int val_input; // Poor variable name
    bool is_ok;    // Redundant boolean flag

    do {
        std::cout << "Enter a number between 1 and 10 (inclusive): ";
        std::cin >> val_input;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear the error flags
            // Ignore remaining characters in the input buffer up to the newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            is_ok = false; // Input type is not okay
        } else {
            // Input was an integer, now check its range
            if (val_input >= 1 && val_input <= 10) {
                is_ok = true; // Input is valid
            } else {
                std::cout << "Invalid input. Please enter a number between 1 and 10.\n";
                is_ok = false; // Input is out of range
            }
        }
        // The condition combining type and range check could be more concise.
        // The use of a separate boolean flag `is_ok` adds verbosity.

    } while (!is_ok); // Loop continues until a valid number is received

    // std::cout << "Successfully received: " << val_input << std::endl;
    return val_input;
}

int main() {
    solve();
    return 0;
}