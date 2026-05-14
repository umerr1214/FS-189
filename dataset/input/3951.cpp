#include <iostream>

// Correct, robust, and efficient implementation of the `isPrime` function.
// It handles edge cases (0, 1, negative numbers) correctly,
// includes optimizations for 2, 3, and multiples of 2 and 3,
// and efficiently checks for divisors up to the square root of n using the 6k +/- 1 optimization.
bool isPrime(int n) {
    if (n <= 1) return false; // Handles 0, 1, and negative numbers
    if (n == 2 || n == 3) return true; // Handles 2 and 3 as primes
    if (n % 2 == 0 || n % 3 == 0) return false; // Handles multiples of 2 and 3 (e.g., 4, 6, 9)

    // Check for primes of the form 6k +/- 1.
    // The loop iterates only up to sqrt(n) (represented by i*i <= n)
    // and checks only potential divisors that are not multiples of 2 or 3.
    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    std::cin >> num;
    if (isPrime(num)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    return 0;
}