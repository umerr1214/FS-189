#include <iostream>

// Recursive C++ function to calculate the Nth Fibonacci number
// F(0)=0, F(1)=1
int fibonacci(int n) {
    if (n < 0) {
        // Handle negative input as per question's non-negative requirement
        // Although this version handles it, it's not the primary efficiency issue.
        return -1; // Or throw an error, but for simplicity, return -1
    }
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        // Readability / Efficiency Issue:
        // This is a naive recursive implementation that recomputes Fibonacci numbers
        // multiple times. Its time complexity is O(2^N), which is very inefficient
        // for larger values of N (e.g., N > 30).
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    std::cout << "Enter a non-negative integer N: ";
    std::cin >> n;

    if (n < 0) {
        std::cerr << "Error: N must be a non-negative integer." << std::endl;
    } else {
        std::cout << "The " << n << "th Fibonacci number is: " << fibonacci(n) << std::endl;
    }

    return 0;
}