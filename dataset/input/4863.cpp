#include <iostream>
#include <vector>   // For memoization
#include <stdexcept> // For exception handling

// Global vector for memoization, initialized with -1 to indicate uncomputed values.
// Max 'n' for `long long` before overflow is F(93). `memo` size covers up to F(94).
std::vector<long long> memo(95, -1);

// Recursive C++ function `fibonacci(n)` with memoization (dynamic programming)
// This version is efficient, correct, and robust.
long long fibonacci(int n) {
    // Robust input validation for 'n' as per question ("non-negative integer").
    if (n < 0) {
        throw std::invalid_argument("Input 'n' must be a non-negative integer.");
    }
    // Check if 'n' is within the bounds of our memoization table and `long long` limits.
    if (n >= memo.size()) {
        throw std::out_of_range("Input 'n' is too large for calculation with current data type (long long) or memoization table size.");
    }

    // Base cases
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    // Check if the value has already been computed (memoization)
    if (memo[n] != -1) {
        return memo[n];
    }

    // Compute and store the result for future use
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    std::cout << "Enter a non-negative integer 'n': ";
    int n;
    std::cin >> n;

    try {
        // Robust input validation for non-integer input
        if (std::cin.fail()) {
            throw std::runtime_error("Invalid input: Please enter an integer.");
        }

        long long result = fibonacci(n);
        std::cout << "The " << n << "-th Fibonacci number is: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // Indicate error
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // Indicate error
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // Indicate error
    }

    return 0;
}