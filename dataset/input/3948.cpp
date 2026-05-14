#include <iostream>
#include <cmath> // For std::sqrt

// Function to check if a number is prime - SEMANTIC ERROR: returns void
void isPrime(int n) { // Should be 'bool isPrime(int n)'
    if (n <= 1) {
        return; // Cannot return a value for void function
    }
    // Check for divisibility from 2 up to the square root of n
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            return; // Not prime, but can't return false for void function
        }
    }
    return; // Prime, but can't return true for void function
}

int main() {
    int num;
    std::cout << "Enter a positive integer: ";
    std::cin >> num;

    // SEMANTIC ERROR: Attempting to use the result of a void function in a boolean context.
    // The 'isPrime' function is declared to return 'void', meaning it doesn't return a value.
    // This 'if' statement expects a boolean expression.
    if (isPrime(num)) { // This line will cause a compilation error (e.g., "cannot convert 'void' to 'bool'")
        std::cout << num << " is a prime number." << std::endl;
    } else {
        std::cout << num << " is not a prime number." << std::endl;
    }

    return 0;
}