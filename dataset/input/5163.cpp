#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int height;

    // Robust input validation loop to ensure a positive integer height
    while (true) {
        std::cout << "Enter the height of the triangle (a positive integer): ";
        std::cin >> height;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear(); // Clear the error flag
            // Discard invalid input from the buffer up to the newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (height <= 0) {
            std::cout << "Height must be a positive integer. Please try again.\n";
            // No need to clear/ignore here, as input was valid but value was out of range.
            // The next read will correctly get a new integer.
        } else {
            // Valid positive integer input received, exit loop
            break;
        }
    }

    // Nested for loops to print the right-angled triangle pattern
    // Descriptive variable names for clarity
    for (int row = 1; row <= height; ++row) {
        for (int col = 1; col <= row; ++col) {
            std::cout << "*";
        }
        std::cout << '\n'; // Efficient newline character (does not force buffer flush)
    }

    return 0;
}