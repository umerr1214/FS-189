#include <iostream>

// Recursive fibonacci function with a significant efficiency issue.
// This implementation re-calculates Fibonacci numbers multiple times,
// leading to exponential time complexity (O(2^N)).
int fibonacci(int n) {
    if (n < 0) {
        // Basic handling for negative input to prevent infinite recursion,
        // but the main issue for this category is efficiency for positive N.
        return 0; // Returning 0 for negative n; main performs explicit validation.
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // This is the inefficient part: redundant calculations for fibonacci(n-1) and fibonacci(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int N;
    std::cout << "Enter an integer N: ";
    std::cin >> N;

    // Basic input validation in main to ensure N is non-negative
    // so that the efficiency issue is the primary focus for valid inputs.
    if (N < 0) {
        std::cerr << "Error: N must be a non-negative integer for this calculation." << std::endl;
        return 1; // Indicate an error
    }

    int result = fibonacci(N);
    std::cout << "The " << N << "th Fibonacci number is: " << result << std::endl;

    return 0;
}