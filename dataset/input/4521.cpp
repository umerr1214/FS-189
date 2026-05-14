#include <iostream>

// This program is a Correct Version of the Fibonacci sequence generator.
// It uses an efficient iterative approach with long long to prevent overflow
// for a wide range of N, and handles invalid input (N <= 0) gracefully.
long long fibonacci(int n) {
    // This function assumes n >= 1. Input validation for N <= 0 is handled in main.
    if (n == 1 || n == 2) {
        return 1;
    }

    long long a = 1;
    long long b = 1;
    long long next_term;

    for (int i = 3; i <= n; ++i) {
        next_term = a + b;
        a = b;
        b = next_term;
    }
    return b;
}

int main() {
    int N;
    std::cin >> N;

    if (N <= 0) {
        // Robust error handling for invalid input according to problem context.
        std::cout << "Error: N must be a positive integer." << std::endl;
    } else {
        long long result = fibonacci(N);
        std::cout << result << std::endl;
    }

    return 0;
}