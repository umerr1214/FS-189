#include <iostream>
#include <vector> // Not used, demonstrates potential for efficiency improvement

// Recursive C++ function `fibonacci(n)`
// This version is correct for non-negative 'n' within 'int' limits,
// but suffers from a significant efficiency issue.
// It is also slightly less readable due to lack of comments explaining the inefficiency.
int fibonacci(int n) {
    // Basic input validation: Although the question states 'non-negative',
    // a program should ideally handle invalid input gracefully.
    // For this 'efficiency issue' category, we prioritize correctness for valid inputs.
    if (n < 0) {
        std::cerr << "Error: Input 'n' must be non-negative." << std::endl;
        return -1; // Indicate an error for invalid input
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // Efficiency Issue: This naive recursive implementation re-calculates
    // Fibonacci numbers for the same 'n' multiple times.
    // For example, fibonacci(5) calls fibonacci(4) and fibonacci(3).
    // fibonacci(4) then calls fibonacci(3) and fibonacci(2).
    // fibonacci(3) is computed twice, and smaller numbers even more times.
    // This leads to an exponential time complexity (O(2^n)), making it
    // very slow for moderately large values of 'n' (e.g., n > 30-35).
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    std::cout << "Enter a non-negative integer 'n': ";
    int n;
    std::cin >> n;

    // Basic input validation for non-negative 'n'
    if (std::cin.fail() || n < 0) {
        std::cerr << "Error: 'n' must be a non-negative integer." << std::endl;
        return 1; // Indicate error
    }

    // Calling the inefficient fibonacci function.
    // This will take a noticeable amount of time for n=30, and much longer for n=40.
    int result = fibonacci(n);
    if (result != -1) { // Only print if fibonacci function did not return an error
        std::cout << "The " << n << "-th Fibonacci number is: " << result << std::endl;
    }

    return 0;
}