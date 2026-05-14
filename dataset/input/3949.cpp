#include <iostream>

// Robustness Issue: This function incorrectly identifies 0, 1, and negative numbers as prime.
// A prime number is defined as a natural number greater than 1 that has no positive divisors other than 1 and itself.
// Thus, 0, 1, and negative numbers should all return false.
bool isPrime(int n) {
    if (n == 1) return true; // INCORRECT: 1 is not prime
    if (n <= 0) return true; // INCORRECT: 0 and negative numbers are not prime

    // For n >= 2, the core loop logic is correct, but the initial checks are flawed,
    // leading to incorrect behavior for edge cases like 0, 1, and negative inputs.
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
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