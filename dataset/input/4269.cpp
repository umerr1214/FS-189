#include <iostream>
#include <limits> // Required for numeric_limits

int main() {
    int number;
    long long factorial = 1; // Use long long to handle larger factorial results (up to 20!)
    int i = 1;

    // Input validation loop
    while (true) {
        std::cout << "Please enter a non-negative integer: ";
        if (!(std::cin >> number)) { // Check if extraction failed (non-numeric input)
            std::cout << "Invalid input. ";
            std::cin.clear(); // Clear error flags
            // Ignore the rest of the line to prevent infinite loop with bad input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (number < 0) { // Check for negative input
            std::cout << "Invalid input. ";
            // No need to clear/ignore for negative numbers, as input stream is fine
        } else {
            break; // Valid non-negative integer received, exit loop
        }
    }

    // Calculate factorial using a while loop
    if (number == 0) {
        factorial = 1; // Factorial of 0 is 1
    } else {
        while (i <= number) {
            factorial *= i;
            i++;
        }
    }

    std::cout << "The factorial of " << number << " is " << factorial << ".\n";

    return 0;
}