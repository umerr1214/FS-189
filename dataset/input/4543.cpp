#include <iostream>
#include <cmath> // Included for consistency, though std::abs is not used on inputs in this version.

// Function to calculate the Greatest Common Divisor (GCD) of two integers
// using the Euclidean algorithm.
//
// ROBUSTNESS ISSUE: This version does not explicitly handle negative inputs
// by taking their absolute values. While C++'s modulo operator behavior
// (result has same sign as dividend) means GCD(a, b) will correctly return
// GCD(|a|, |b|) for many negative input combinations (e.g., GCD(-6, 9) returns 3),
// it will return a negative GCD if both inputs are negative
// (e.g., GCD(-15, -25) returns -5 instead of the mathematically expected 5).
int calculateGCD(int a, int b) {
    // The Euclidean algorithm naturally handles a=0 or b=0 correctly for non-zero inputs.
    // For (0,0), it will return 0.
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    std::cout << "Testing calculateGCD function (Robustness Issue Version):" << std::endl;
    std::cout << "GCD(48, 18) = " << calculateGCD(48, 18) << " (Expected: 6)" << std::endl;
    std::cout << "GCD(101, 103) = " << calculateGCD(101, 103) << " (Expected: 1)" << std::endl;
    std::cout << "GCD(7, 0) = " << calculateGCD(7, 0) << " (Expected: 7)" << std::endl;
    std::cout << "GCD(0, 15) = " << calculateGCD(0, 15) << " (Expected: 15)" << std::endl;
    std::cout << "GCD(0, 0) = " << calculateGCD(0, 0) << " (Expected: 0)" << std::endl;
    std::cout << "GCD(-6, 9) = " << calculateGCD(-6, 9) << " (Expected: 3)" << std::endl;
    std::cout << "GCD(12, -8) = " << calculateGCD(12, -8) << " (Expected: 4)" << std::endl;
    std::cout << "GCD(-15, -25) = " << calculateGCD(-15, -25) << " (Expected: 5, Actual: -5 - Robustness Issue)" << std::endl;
    std::cout << "GCD(7, 7) = " << calculateGCD(7, 7) << " (Expected: 7)" << std::endl;
    return 0;
}