#include <iostream>
#include <vector>

// Function with a robustness issue: does not handle negative inputs gracefully.
// For negative n, it will incorrectly return 0.
long long fibonacci(int n) {
    if (n < 0) {
        // This is a robustness issue: instead of handling the invalid input
        // (e.g., throwing an exception or returning a specific error code like -1),
        // it returns 0, which is technically a valid Fibonacci number for F(0)
        // but completely wrong for a negative index.
        return 0; 
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
    std::cout << "Demonstrating fibonacci function with robustness issue:" << std::endl;

    // Valid inputs
    std::cout << "F(0) = " << fibonacci(0) << std::endl;   // Expected: 0
    std::cout << "F(1) = " << fibonacci(1) << std::endl;   // Expected: 1
    std::cout << "F(5) = " << fibonacci(5) << std::endl;   // Expected: 5
    std::cout << "F(10) = " << fibonacci(10) << std::endl; // Expected: 55

    // Input demonstrating robustness issue
    std::cout << "F(-3) = " << fibonacci(-3) << std::endl; // Expected: 0 (incorrectly handled)

    return 0;
}