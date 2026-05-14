#include <iostream>
#include <vector>
#include <string>

int main() {
    // Optimize C++ standard streams for faster input/output
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; // Variable to store the number of terms requested by the user
    std::cin >> n;

    // Input validation: Ensure 'n' is a non-negative integer.
    // Provides a clear error message to the user for invalid input.
    if (n < 0) {
        std::cout << "Input `n` must be a non-negative integer.\n";
        return 0; // Exit after printing error message
    }

    // Handle edge case: If n is 0, print nothing (an empty line)
    if (n == 0) {
        std::cout << std::endl;
        return 0;
    }

    // Initialize the first two Fibonacci numbers.
    // Using 'long long' to prevent integer overflow for large 'n' values,
    // ensuring robustness for a wider range of inputs.
    long long first_term = 0;
    long long second_term = 1;

    // Handle edge case: If n is 1, print only the first term (0)
    if (n == 1) {
        std::cout << first_term << std::endl;
        return 0;
    }

    // Print the first two terms of the sequence
    std::cout << first_term << " " << second_term;

    // Generate and print the remaining terms iteratively.
    // This approach is efficient (O(n) time complexity) and avoids redundant calculations.
    for (int i = 2; i < n; ++i) {
        long long next_term = first_term + second_term;
        std::cout << " " << next_term;
        first_term = second_term;
        second_term = next_term;
    }
    std::cout << std::endl; // Print a newline at the end of the sequence

    return 0; // Indicate successful execution
}