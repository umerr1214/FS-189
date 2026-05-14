#include <iostream>

// This function calculates base raised to the power of exp using a loop.
// It exhibits robustness issues:
// 1. It incorrectly handles negative exponents: for exp < 0, it returns 1 instead of a fractional value.
//    (e.g., 2^-1 is 0.5, but this function returns 1).
// 2. It does not handle potential integer overflow for large results, leading to incorrect values.
//    (e.g., 2^31 will overflow a 32-bit signed int).
int power(int base, int exp) {
    int result = 1; // Initialize result to 1. This correctly handles base^0 = 1.

    // The loop iterates 'exp' times.
    // If exp is 0 or negative, the loop will not execute, and 'result' (which is 1) will be returned.
    // This correctly handles exp = 0 (base^0 = 1).
    // However, it incorrectly handles negative exponents by returning 1.
    for (int i = 0; i < exp; ++i) {
        result *= base;
        // No overflow check is performed, which is a robustness flaw.
    }

    return result;
}

int main() {
    int base, exp;

    std::cout << "Enter base: ";
    std::cin >> base;

    std::cout << "Enter exponent: ";
    std::cin >> exp;

    int result = power(base, exp);
    std::cout << "Result: " << result << std::endl;

    return 0;
}