#include <iostream>
#include <vector>
#include <map>

// Using a map for memoization to store already calculated Fibonacci numbers.
// This makes the recursive function efficient (O(N) time complexity).
std::map<int, int> memo;

// Recursive C++ function to calculate the Nth Fibonacci number with memoization
// F(0)=0, F(1)=1
int fibonacci(int n) {
    if (n < 0) {
        // Robustness: Handle invalid input as per question's non-negative requirement
        // This case should ideally be caught by main, but for a complete function,
        // it's good to have.
        throw std::invalid_argument("Input N must be a non-negative integer.");
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    
    // Check if the result is already in the memoization table
    if (memo.count(n)) {
        return memo[n];
    }
    
    // Calculate and store the result in the memoization table
    int result = fibonacci(n - 1) + fibonacci(n - 2);
    memo[n] = result;
    return result;
}

int main() {
    int n;
    std::cout << "Enter a non-negative integer N: ";
    std::cin >> n;

    // Robustness: Input validation in main for non-negative N
    if (n < 0) {
        std::cerr << "Error: N must be a non-negative integer." << std::endl;
        return 1; // Indicate an error
    }

    try {
        std::cout << "The " << n << "th Fibonacci number is: " << fibonacci(n) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}