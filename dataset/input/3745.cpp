#include <iostream>

int main() {
    int num;
    
    std::cout << "Enter a non-negative integer: ";
    
    // Robustness Issue: Basic input type validation, but subsequent reads
    // in a loop would fail without clearing cin state.
    // Also, the primary robustness issue here is using 'int' for the factorial result,
    // which overflows for inputs greater than 12.
    if (!(std::cin >> num)) {
        std::cout << "Invalid input. Please enter a non-negative integer.\n";
        return 1; // Indicate an error
    }

    if (num < 0) {
        std::cout << "Error: Factorial is not defined for negative numbers.\n";
    } else {
        // Robustness Issue: 'factorial_result' is an 'int', which will overflow
        // for inputs like 13! or higher, leading to incorrect results.
        int factorial_result = 1; 
        for (int i = 1; i <= num; ++i) {
            factorial_result *= i;
        }
        std::cout << "The factorial of " << num << " is " << factorial_result << ".\n";
    }

    return 0;
}