#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    long long number;
    std::cout << "Please enter a non-negative integer: ";

    // Robust input validation loop:
    // Ensures that input is a valid number and is non-negative.
    // If input fails (non-numeric) or is negative, it clears the error state,
    // discards invalid input, and prompts the user again.
    while (!(std::cin >> number) || number < 0) {
        std::cout << "Invalid input. Please enter a non-negative integer: ";
        std::cin.clear(); // Clear the error flag on std::cin
        // Ignore remaining characters in the input buffer up to the newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int digitCount = 0;

    // Special case for 0, which has 1 digit.
    // This is handled separately as the `while (number > 0)` loop would not execute for 0.
    if (number == 0) {
        digitCount = 1;
    } else {
        // Use a while loop to count digits for positive numbers.
        // The loop continues as long as the number is greater than 0.
        // Each iteration effectively "removes" one digit by integer division.
        while (number > 0) {
            number /= 10; // Integer division removes the last digit
            digitCount++; // Increment the count for each digit removed
        }
    }

    std::cout << "The number of digits is: " << digitCount << std::endl;

    return 0;
}