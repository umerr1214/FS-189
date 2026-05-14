#include <iostream>

// Correct and efficient function to calculate factorial
long long calculateFactorial(int n) {
    if (n < 0) {
        // Handle negative input appropriately by returning an error indicator
        return -1; 
    }
    if (n == 0) {
        return 1;
    }
    // Use long long to prevent overflow for larger factorials (up to 20!)
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int number;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> number;

    long long factorial = calculateFactorial(number);

    if (factorial == -1) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        std::cout << "The factorial of " << number << " is: " << factorial << std::endl;
    }

    return 0;
}