#include <iostream>
#include <vector>
#include <map> // For memoization

// Recursive function to calculate Nth Fibonacci number with memoization
// Correct version: handles negative n, and is efficient due to memoization
int fibonacci(int n) {
    static std::map<int, int> memo; // Memoization cache, initialized once

    if (n < 0) {
        // As per problem context (F(0)=0, F(1)=1), negative indices are usually undefined.
        // Returning -1 is a common way to signal an invalid input.
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // Check if the result is already computed
    if (memo.count(n)) {
        return memo[n];
    }
    // Compute and store the result
    int result = fibonacci(n - 1) + fibonacci(n - 2);
    memo[n] = result;
    return result;
}

int main() {
    std::vector<int> test_inputs = {0, 1, 2, 3, 5, 10, 20, 30, 40, -1, -5}; // Comprehensive test inputs
    for (int n : test_inputs) {
        std::cout << "fibonacci(" << n << ") = " << fibonacci(n) << std::endl;
    }
    return 0;
}