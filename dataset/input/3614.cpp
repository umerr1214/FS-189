#include <iostream>

// Function to check if a number is prime
// Readability/Efficiency Issue: This function is highly inefficient
// as it checks divisibility up to 'n-1' instead of 'sqrt(n)'.
// It also lacks comments and uses a less descriptive parameter name 'n'.
bool isPrime(int n) { // Poor parameter name 'n'
    if (n <= 1) {
        return false;
    }
    // Highly inefficient: checks divisibility for all numbers up to n-1.
    // Optimal would be up to sqrt(n) and skipping even numbers after 2.
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
} // No comments explaining logic or optimizations

int main() {
    int limit; // Variable name is okay but could be more descriptive
    std::cout << "Enter a limit: ";
    std::cin >> limit; // No input validation for `std::cin.fail()`

    if (limit < 2) {
        std::cout << "No prime numbers to display up to " << limit << "." << std::endl;
        return 0;
    }

    std::cout << "Prime numbers up to " << limit << ":" << std::endl;
    for (int i = 2; i <= limit; ++i) { // Loop variable 'i' is standard
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}