#include <iostream>

// Recursive fibonacci function with a robustness issue for negative N.
// It returns 0 for negative N, which is an arbitrary choice and not
// mathematically correct for negative Fibonacci numbers, nor does it signal an error.
int fibonacci(int n) {
    if (n < 0) {
        return 0; // Arbitrary handling for negative input, not an error or correct value.
                  // For reference, F(-1) = 1, F(-2) = -1, F(-3) = 2, etc.
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int N;
    std::cout << "Enter an integer N: ";
    std::cin >> N;

    // Robustness Issue: No input validation in main for negative N.
    // The program will proceed to call fibonacci(N) even if N is negative,
    // and print the arbitrary result from the fibonacci function.

    int result = fibonacci(N);
    std::cout << "The " << N << "th Fibonacci number is: " << result << std::endl;

    return 0;
}