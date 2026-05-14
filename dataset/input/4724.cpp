#include <iostream>

// Function with readability and efficiency issues.
bool isPrime(int val) { // Poor variable name: 'val' instead of 'n' or 'number'
    if (val <= 1) {
        return false;
    }
    // Inefficient algorithm: checks divisibility up to val-1.
    // No early exit for even numbers (other than 2) and no optimization
    // to check only up to sqrt(val). This makes it very slow for larger numbers.
    for (int j = 2; j < val; ++j) { // Poor variable name 'j', inefficient loop condition
        if (val % j == 0) {
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

    // Large numbers to highlight inefficiency - these will be very slow to execute.
    std::cout << (isPrime(1000003) ? "true" : "false") << std::endl; // A prime number
    std::cout << (isPrime(999999) ? "true" : "false") << std::endl;   // A composite number

    return 0;
}