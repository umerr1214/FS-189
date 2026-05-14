#include <iostream>
#include <limits> // Required for numeric_limits

// Function containing the core logic, called by main for testing purposes.
// This version has a robustness issue: it does not handle non-numeric input
// by clearing the error state and ignoring the invalid characters in the buffer.
// This will lead to an infinite loop if non-integer input is provided.
int solve() {
    int user_number;
    bool is_valid_input;

    do {
        std::cout << "Enter a number between 1 and 10 (inclusive): ";
        std::cin >> user_number;

        // Check if the input operation failed (e.g., non-numeric input)
        // This version intentionally omits clearing std::cin.fail() and ignoring buffer.
        // If std::cin fails, user_number might not be updated,
        // and the stream will remain in a failed state, causing an infinite loop.

        is_valid_input = (user_number >= 1 && user_number <= 10);

        if (!is_valid_input) {
            std::cout << "Invalid input. Please enter a number between 1 and 10.\n";
        }

    } while (!is_valid_input); // Loop continues until a number in range is received

    // std::cout << "You entered a valid number: " << user_number << std::endl;
    return user_number;
}

int main() {
    solve();
    return 0;
}