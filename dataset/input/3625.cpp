#include <iostream>
#include <vector>

// Recursive function to calculate Nth Fibonacci number
// Robustness issue: Does not handle negative n, leading to infinite recursion and stack overflow.
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // For n < 0, this will recursively call fibonacci(n-1), fibonacci(n-2)
    // leading to an infinite descent and stack overflow.
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    std::vector<int> test_inputs = {0, 1, 2, 3, 5, 10, -1, -5}; // Include negative inputs to demonstrate the issue
    for (int n : test_inputs) {
        // For n < 0, this call will cause a stack overflow.
        // For n >= 0, it will compute correctly.
        std::cout << "fibonacci(" << n << ") = " << fibonacci(n) << std::endl;
    }
    return 0;
}