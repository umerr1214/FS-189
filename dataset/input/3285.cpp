#include <iostream>
#include <cctype> // For isupper, islower, isdigit
#include <string>
#include <limits> // For std::numeric_limits

// Helper function to encapsulate the classification logic for testing
std::string classify_char_category(char c) {
    // Correct Version: Uses standard library ctype functions for robust, readable, and efficient classification.
    // `static_cast<unsigned char>(c)` is used as ctype functions expect an `int` argument
    // that is either `EOF` or representable as an `unsigned char`. This avoids undefined
    // behavior for negative `char` values (e.g., extended ASCII on systems where `char` is signed).
    if (std::isupper(static_cast<unsigned char>(c))) {
        return "Category: Uppercase Letter";
    } else if (std::islower(static_cast<unsigned char>(c))) {
        return "Category: Lowercase Letter";
    } else if (std::isdigit(static_cast<unsigned char>(c))) {
        return "Category: Digit";
    } else {
        return "Category: Special Character";
    }
}

int main() {
    char c;
    std::cout << "Enter a character: ";

    // Correct Version: Robust input handling. Checks for input failure.
    // If input fails, it prints an error message, clears the stream's error flags,
    // ignores any remaining invalid input in the buffer, and exits with an error code.
    if (!(std::cin >> c)) {
        std::cerr << "Error: Invalid input or failed to read character." << std::endl;
        std::cin.clear(); // Clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
        return 1; // Indicate an error
    }

    std::cout << classify_char_category(c) << std::endl;

    return 0;
}