#include <iostream>
#include <cmath> // Included for potential use, but the bug avoids std::sqrt
#include <limits> // For std::numeric_limits<int>::max()

// Function with a robustness issue: potential integer overflow in loop condition.
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
    
    // Robustness issue: The condition `i * i <= n` can lead to integer overflow
    // if `n` is a large number and `i` approaches `sqrt(INT_MAX)`.
    // For example, if `n` is `INT_MAX` (2147483647), and `i` reaches `46341`,
    // then `i * i` (46341 * 46341 = 2147488281) will overflow a 32-bit signed integer.
    // This results in undefined behavior, potentially causing an incorrect loop termination
    // (e.g., the condition becoming true or false unexpectedly) or a crash.
    for (int i = 5; i * i <= n; i = i + 6) {
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

    // Test for potential overflow (INT_MAX is a prime number)
    // The i*i <= n condition is problematic here.
    std::cout << (isPrime(std::numeric_limits<int>::max()) ? "true" : "false") << std::endl;

    return 0;
}