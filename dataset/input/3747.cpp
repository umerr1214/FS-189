#include <iostream>
#include <limits> // Required for numeric_limits

int main() {
    int number;
    long long factorial = 1; // Use long long to prevent overflow for larger factorials
    
    std::cout << "Enter a non-negative integer: ";
    
    // Robust input validation for non-integer input
    if (!(std::cin >> number)) {
        std::cout << "Invalid input. Please enter a non-negative integer.\n";
        // Clear error flags and ignore the rest of the line
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1; // Exit with an error code
    }

    if (number < 0) {
        std::cout << "Error: Factorial is not defined for negative numbers.\n";
    } else {
        // Factorial of 0 is 1, handled by initialization.
        // Loop correctly calculates factorial for positive numbers.
        for (int i = 1; i <= number; ++i) {
            factorial *= i;
        }
        std::cout << "The factorial of " << number << " is " << factorial << ".\n";
    }

    return 0;
}