#include <iostream>
#include <limits> // Required for numeric_limits

int main() {
    int number;
    long long factorial = 1;
    int i = 1;

    // Input validation loop
    while (true) {
        std::cout << "Please enter a non-negative integer: ";
        if (!(std::cin >> number)) {
            std::cout << "Invalid input. ";
            std::cin.clear(); // Clear error flags
            // Ignore rest of the line, up to newline or max stream size
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (number < 0) {
            std::cout << "Invalid input. ";
            // No need to clear/ignore for negative numbers, just re-prompt
        } else {
            break; // Valid input received
        }
    }

    if (number == 0) {
        factorial = 1; // Factorial of 0 is 1
    } else {
        while (i <= number) {
            // This program does not explicitly check for long long overflow.
            // For numbers greater than 20, factorial will overflow.
            factorial *= i;
            i++;
        }
    }

    std::cout << "The factorial of " << number << " is " << factorial << ".\n";

    return 0;
}