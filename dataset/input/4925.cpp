#include <iostream>

int main() {
    int number;
    std::cout << "Enter an integer: ";
    std::cin >> number;

    // Logical error: Any non-negative number will be classified as positive.
    // The 'else if (number < 0)' condition will correctly catch negative numbers,
    // but the 'else' block will never be reached for zero if it's caught by the first 'if'.
    // Corrected: The current logic will classify 0 as positive.
    if (number >= 0) { // Should be 'number > 0' for positive, then 'number < 0' for negative, then 'else' for zero.
        std::cout << "The number is positive." << std::endl;
    } else if (number < 0) {
        std::cout << "The number is negative." << std::endl;
    } else { // This block will never be reached with the current 'if (number >= 0)'
        std::cout << "The number is zero." << std::endl;
    }

    return 0;
}