#include <iostream>

// Recursive C++ function to calculate the Nth Fibonacci number
// F(0)=0, F(1)=1
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        // This implementation does not handle negative n.
        // For negative n, it will lead to infinite recursion / stack overflow.
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    std::cout << "Enter a non-negative integer N: ";
    std::cin >> n;

    // Robustness Issue: No input validation for negative N.
    // If a negative number is entered, the program will crash due to stack overflow.
    // The question implies non-negative, but a robust program would validate.
    
    std::cout << "The " << n << "th Fibonacci number is: " << fibonacci(n) << std::endl;

    return 0;
}