#include <iostream>

// Function to calculate factorial with robustness issue (int overflow)
int calculateFactorial(int n) {
    if (n < 0) {
        // Handle negative input appropriately
        return -1; // Indicates an error or undefined factorial
    }
    if (n == 0) {
        return 1;
    }
    // Using int, which will overflow for n > 12
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        // This check is a basic attempt to prevent overflow, but doesn't solve the core issue
        // for n=13, 12! * 13 will overflow int, but 12! itself fits.
        // A more robust check would be 'if (result > INT_MAX / i)'
        // For simplicity, the core issue is the return type 'int'
        result *= i; 
    }
    return result;
}

int main() {
    int number;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> number;

    int factorial = calculateFactorial(number);

    if (factorial == -1) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        std::cout << "The factorial of " << number << " is: " << factorial << std::endl;
    }

    return 0;
}