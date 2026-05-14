#include <iostream>
#include <vector>

// Recursive function to calculate Nth Fibonacci number
// Efficiency issue: Highly inefficient due to redundant calculations (exponential time complexity)
int fibonacci(int n) {
    if (n < 0) {
        return -1; // Basic handling for negative input, but not the focus of this error type
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // This is the inefficient part: recalculates fibonacci(n-2) multiple times
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    std::vector<int> test_inputs = {0, 1, 2, 3, 5, 10, 20, 30}; // Include larger inputs to highlight inefficiency
    for (int n : test_inputs) {
        std::cout << "fibonacci(" << n << ") = " << fibonacci(n) << std::endl;
    }
    return 0;
}