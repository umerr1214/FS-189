#include <iostream>
#include <cmath> // Required for std::abs

// Function to calculate the Greatest Common Divisor (GCD) of two integers
// using the Euclidean algorithm.
//
// This version is robust, readable, and efficient.
// - It handles negative inputs by taking their absolute values, ensuring the GCD is always non-negative.
// - Uses clear, descriptive variable names.
// - Employs an iterative approach, which is generally more efficient and safer (no stack overflow risk)
//   than recursion for this algorithm.
// - Includes comments to explain the logic and design choices.
int calculateGCD(int a, int b) {
    // Take absolute values of the inputs to ensure the GCD is always non-negative
    // as per mathematical convention. GCD(a, b) = GCD(|a|, |b|).
    a = std::abs(a);
    b = std::abs(b);

    // Euclidean algorithm: GCD(a, b) = GCD(b, a % b)
    // The loop continues until b becomes 0.
    // At that point, a holds the GCD.
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a; // When b is 0, a contains the GCD
}

int main() {
    std::cout << "Testing calculateGCD function (Correct Version):" << std::endl;
    std::cout << "GCD(48, 18) = " << calculateGCD(48, 18) << " (Expected: 6)" << std::endl;
    std::cout << "GCD(101, 103) = " << calculateGCD(101, 103) << " (Expected: 1)" << std::endl;
    std::cout << "GCD(7, 0) = " << calculateGCD(7, 0) << " (Expected: 7)" << std::endl;
    std::cout << "GCD(0, 15) = " << calculateGCD(0, 15) << " (Expected: 15)" << std::endl;
    std::cout << "GCD(0, 0) = " << calculateGCD(0, 0) << " (Expected: 0)" << std::endl; // GCD(0,0) is often defined as 0 in programming contexts
    std::cout << "GCD(-6, 9) = " << calculateGCD(-6, 9) << " (Expected: 3)" << std::endl;
    std::cout << "GCD(12, -8) = " << calculateGCD(12, -8) << " (Expected: 4)" << std::endl;
    std::cout << "GCD(-15, -25) = " << calculateGCD(-15, -25) << " (Expected: 5)" << std::endl;
    std::cout << "GCD(7, 7) = " << calculateGCD(7, 7) << " (Expected: 7)" << std::endl;
    return 0;
}