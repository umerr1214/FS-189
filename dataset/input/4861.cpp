#include <iostream>
#include <limits> // Potentially useful for checking numeric limits, though not explicitly used for handling here

// Recursive C++ function `fibonacci(n)`
// This version has robustness issues:
// 1. It returns an arbitrary value (0) for negative 'n', which is outside the problem's
//    specified non-negative range, instead of handling it gracefully (e.g., error message, exception).
// 2. It uses 'int' as the return type, making it susceptible to integer overflow
//    for larger Fibonacci numbers (n > 46 for signed 32-bit int).
int fibonacci(int n) {
    if (n < 0) {
        // Robustness Issue 1: Arbitrary return for invalid input.
        // The question specifies "non-negative integer". Returning 0 is incorrect behavior.
        return 0;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // Robustness Issue 2: Integer overflow for n > 46 when using 'int'.
    // The sum can exceed `std::numeric_limits<int>::max()`.
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    std::cout << "Enter a non-negative integer 'n': ";
    int n;
    std::cin >> n;

    // Robustness Issue 3: No explicit input validation in main for `n < 0`
    // or for non-integer input. If `n` is negative, `fibonacci(n)` will return 0.
    // If `n` is large (e.g., 48), `fibonacci(n)` will return an incorrect
    // value due to integer overflow, without any warning.

    int result = fibonacci(n);
    std::cout << "The " << n << "-th Fibonacci number is: " << result << std::endl;

    return 0;
}