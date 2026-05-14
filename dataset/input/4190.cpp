#include <iostream>
#include <cmath> // Not strictly needed for this version, but often included for prime checks.

// Function to check if a number is prime
// Readability / Efficiency Issue: The loop checks divisibility up to num / 2,
// which is less efficient than checking up to sqrt(num).
// The code is functionally correct for positive integers but could be optimized.
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    if (num % 2 == 0) {
        return false;
    }
    // Inefficient loop: checks divisibility up to num / 2.
    // A more efficient approach would be to check up to sqrt(num).
    for (int i = 3; i <= num / 2; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Prime numbers between 1 and 100:" << std::endl;
    for (int i = 1; i <= 100; ++i) {
        if (is_prime(i)) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}