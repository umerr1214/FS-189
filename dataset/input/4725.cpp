#include <iostream>
#include <cmath> // For std::sqrt, though `i <= n / i` is used for robustness
#include <limits> // For std::numeric_limits<int>::max()

// Correct, efficient, and robust implementation of isPrime.
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    // Optimized loop: check only odd divisors from 5, in steps of 6 (6k +/- 1 optimization).
    // The condition `i <= n / i` is robust against integer overflow for large `n`,
    // as it avoids `i * i` which could overflow when `i` approaches `sqrt(INT_MAX)`.
    for (int i = 5; i <= n / i; i = i + 6) { 
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // Test cases
    std::cout << (isPrime(0) ? "true" : "false") << std::endl;
    std::cout << (isPrime(1) ? "true" : "false") << std::endl;
    std::cout << (isPrime(2) ? "true" : "false") << std::endl;
    std::cout << (isPrime(3) ? "true" : "false") << std::endl;
    std::cout << (isPrime(4) ? "true" : "false") << std::endl;
    std::cout << (isPrime(5) ? "true" : "false") << std::endl;
    std::cout << (isPrime(6) ? "true" : "false") << std::endl;
    std::cout << (isPrime(7) ? "true" : "false") << std::endl;
    std::cout << (isPrime(13) ? "true" : "false") << std::endl;
    std::cout << (isPrime(25) ? "true" : "false") << std::endl;
    std::cout << (isPrime(97) ? "true" : "false") << std::endl;
    std::cout << (isPrime(100) ? "true" : "false") << std::endl;
    std::cout << (isPrime(-5) ? "true" : "false") << std::endl;

    // Test with INT_MAX (a prime number) - handled correctly and robustly.
    std::cout << (isPrime(std::numeric_limits<int>::max()) ? "true" : "false") << std::endl;
    
    // Large numbers
    std::cout << (isPrime(1000003) ? "true" : "false") << std::endl; // A prime number
    std::cout << (isPrime(999999) ? "true" : "false") << std::endl;   // A composite number

    return 0;
}