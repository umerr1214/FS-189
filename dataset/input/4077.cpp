#include <iostream>

// Renamed main to user_main for testing purposes
int user_main() {
    int height;
    // Input is provided by the test driver, no prompt needed.
    std::cin >> height;

    // Robust input validation: Check for stream failure (e.g., non-integer input)
    if (std::cin.fail()) {
        // For automated testing, if input stream fails, just return an error code.
        // In a real user application, one would clear the error, ignore input, or prompt again.
        return 1;
    }

    // Robust input validation and handling: For non-positive height, print nothing as per problem interpretation and test cases.
    if (height <= 0) {
        return 0;
    }

    // Clear and efficient nested loops for pattern generation
    for (int i = 1; i <= height; ++i) { // Outer loop for each row
        for (int j = 1; j <= i; ++j) { // Inner loop for asterisks in the current row
            std::cout << "*";
        }
        std::cout << '\n'; // Efficient newline character (does not force buffer flush)
    }

    return 0;
}