#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int number;
    std::cout << "Enter a positive integer: ";

    // Robust input validation loop to ensure a positive integer
    // Handles non-numeric input and negative numbers by re-prompting.
    while (!(std::cin >> number) || number < 0) {
        if (std::cin.eof()) { // Handle end-of-file condition
            std::cerr << "Error: End of input stream." << std::endl;
            return 1;
        }
        std::cout << "Invalid input. Please enter a positive integer: ";
        std::cin.clear(); // Clear error flags (e.g., failbit)
        // Discard invalid input from the buffer up to the newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Special case for 0, as the sum of digits for 0 is 0.
    // The input validation above ensures 'number' is non-negative.
    if (number == 0) {
        std::cout << "The sum of the digits is: 0" << std::endl;
        return 0;
    }

    int sumOfDigits = 0;
    int tempNumber = number; // Use a temporary variable to perform calculations

    // Calculate the sum of digits using a while loop
    while (tempNumber > 0) {
        int digit = tempNumber % 10; // Get the last digit
        sumOfDigits += digit;       // Add it to the sum
        tempNumber /= 10;           // Remove the last digit
    }

    std::cout << "The sum of the digits is: " << sumOfDigits << std::endl;

    return 0;
}