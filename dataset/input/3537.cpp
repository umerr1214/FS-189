#include <iostream>
#include <vector>
#include <map> // Using map for memoization as it handles arbitrary N more flexibly.

// Using a map for memoization to store already computed Fibonacci numbers.
// This makes the recursive solution efficient (O(N) time complexity).
std::map<int, int> memo;

int fibonacci(int n) {
    // This function assumes n >= 0, as `main` handles validation.
    // If somehow called with negative n, it indicates an internal issue.
    if (n < 0) {
        return -1; // Should not be reached with proper main validation
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    // Check if the value is already computed (memoized)
    if (memo.count(n)) {
        return memo[n];
    }

    // Compute the value and store it in the memoization table
    int result = fibonacci(n - 1) + fibonacci(n - 2);
    memo[n] = result; // Store the result before returning
    return result;
}

int main() {
    int N;
    std::cout << "Enter an integer N: ";
    std::cin >> N;

    // Input validation for N
    if (N < 0) {
        std::cerr << "Error: N must be a non-negative integer." << std::endl;
        return 1; // Indicate an error
    }

    int result = fibonacci(N);
    std::cout << "The " << N << "th Fibonacci number is: " << result << std::endl;

    return 0;
}