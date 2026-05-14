#include <iostream>
#include <cmath> // Not strictly needed for this version, but often included for prime checks.

// Function to check if a number is prime
// Robustness Issue: This function is not robust for negative inputs.
// If a negative number is passed, the loop condition (i <= num / 2)
// will immediately be false (since i starts at 3 and num/2 would be negative),
// causing the function to incorrectly return true for negative numbers.
// The main program only calls this for positive numbers (1-100),
// so the main program's output will appear correct.
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
    // For odd numbers, check divisibility from 3 up to num / 2, skipping even numbers.
    // This loop logic will cause issues for negative 'num' as explained above.
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