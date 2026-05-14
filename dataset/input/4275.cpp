#include <iostream>
#include <vector>
#include <map> // Could also use std::map for memoization if n can be sparse or negative indices were needed differently

// Helper recursive function with memoization
long long fibonacci_memo_helper(int n, std::vector<long long>& memo) {
    // Base cases
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    // Check if the value is already computed
    if (memo[n] != -1) { // -1 indicates not computed yet
        return memo[n];
    }

    // Compute and store the result
    memo[n] = fibonacci_memo_helper(n - 1, memo) + fibonacci_memo_helper(n - 2, memo);
    return memo[n];
}

// Main recursive fibonacci function with memoization (dynamic programming)
// This version is efficient (O(n) time complexity) and handles base cases and invalid inputs correctly.
long long fibonacci(int n) {
    if (n < 0) {
        // Robustly handle invalid input by returning an error value.
        // A more C++ idiomatic way might be to throw an exception.
        return -1; 
    }

    // Initialize memoization table with -1 (or some other indicator for 'not computed')
    // Size n+1 to store F(0) up to F(n)
    std::vector<long long> memo(n + 1, -1); 

    return fibonacci_memo_helper(n, memo);
}

int main() {
    std::cout << "Demonstrating the correct and efficient fibonacci function (with memoization):" << std::endl;

    // Test cases
    std::cout << "F(0) = " << fibonacci(0) << std::endl;     // Expected: 0
    std::cout << "F(1) = " << fibonacci(1) << std::endl;     // Expected: 1
    std::cout << "F(5) = " << fibonacci(5) << std::endl;     // Expected: 5
    std::cout << "F(10) = " << fibonacci(10) << std::endl;   // Expected: 55
    std::cout << "F(20) = " << fibonacci(20) << std::endl;   // Expected: 6765
    std::cout << "F(45) = " << fibonacci(45) << std::endl;   // Expected: 1134903170 (fits in long long)

    // Invalid input handled robustly
    std::cout << "F(-1) = " << fibonacci(-1) << std::endl;   // Expected: -1 (error indicator)

    return 0;
}