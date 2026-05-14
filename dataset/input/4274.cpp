#include <iostream>
#include <vector>
#include <chrono> // For measuring execution time

// Function with an efficiency issue: standard recursive Fibonacci without memoization.
// This implementation has exponential time complexity (O(2^n)).
long long fibonacci(int n) {
    if (n < 0) {
        // For simplicity in this efficiency example, assume valid non-negative input.
        // A robust solution would handle this, but here we focus on efficiency for positive n.
        return 0; 
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // This part causes redundant calculations, leading to inefficiency.
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    std::cout << "Demonstrating fibonacci function with efficiency issue (unoptimized recursion):" << std::endl;

    // Test cases for various inputs
    std::cout << "F(0) = " << fibonacci(0) << std::endl;
    std::cout << "F(1) = " << fibonacci(1) << std::endl;
    std::cout << "F(5) = " << fibonacci(5) << std::endl;
    std::cout << "F(10) = " << fibonacci(10) << std::endl;

    // A larger input that will highlight the inefficiency
    // For n=35, it will take a noticeable amount of time.
    // For n > ~40, it becomes extremely slow.
    int large_n = 35;
    auto start = std::chrono::high_resolution_clock::now();
    long long result_large_n = fibonacci(large_n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "F(" << large_n << ") = " << result_large_n << std::endl;
    std::cout << "Time taken for F(" << large_n << "): " << duration.count() << " seconds" << std::endl;

    return 0;
}