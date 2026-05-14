#include <iostream>

int main() {
    char number_char; // Semantic error: Using 'char' to read an integer, then comparing its ASCII value.
    std::cout << "Enter an integer: ";
    std::cin >> number_char; // Reads a character, e.g., '5' (ASCII 53)

    // The comparisons will be based on the ASCII value of the character entered,
    // not the numerical value of the integer itself.
    // For example, if '5' is entered, number_char will be 53, which is > 0.
    // If '0' is entered, number_char will be 48, which is > 0.
    // If '-' is entered, number_char will be 45, which is > 0.
    // This makes it difficult to correctly identify negative numbers or zero based on their numerical value.
    if (number_char > '0') { // Compares ASCII value to ASCII value of '0' (48)
        std::cout << "The number is positive." << std::endl;
    } else if (number_char < '0') { // This would only be true for characters with ASCII < 48, like control characters
        std::cout << "The number is negative." << std::endl;
    } else { // This would only be true if number_char is exactly '0' (ASCII 48)
        std::cout << "The number is zero." << std::endl;
    }

    return 0;
}