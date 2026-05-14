#include <iostream>

int main() {
    long long number; // Declared but not initialized. Its value is indeterminate.
    std::cout << "Please enter a non-negative integer: ";
    std::cin >> number;

    // Robustness Issue:
    // 1. No input validation for `std::cin` failure (e.g., non-numeric input).
    //    If input is "abc", `std::cin` fails, `number` retains its indeterminate value,
    //    and the program proceeds with potentially undefined behavior or incorrect results.
    //    The error flag on `std::cin` is not cleared, which can affect subsequent I/O.
    // 2. No explicit check for negative input. The question specifies "non-negative integer".
    //    If a negative number is entered (e.g., -123), the `while (number > 0)` loop
    //    will not execute, incorrectly reporting 0 digits. A robust program would
    //    either prompt for re-entry or handle this case specifically.

    int digitCount = 0;

    if (number == 0) {
        digitCount = 1;
    } else {
        // If 'number' is negative (e.g., -123), this loop condition (number > 0)
        // will be false, and digitCount will remain 0.
        // If 'number' is an indeterminate value (e.g., from non-numeric input)
        // and happens to be non-positive, digitCount will also be 0 or 1 (if 0).
        while (number > 0) {
            number /= 10;
            digitCount++;
        }
    }

    std::cout << "The number of digits is: " << digitCount << std::endl;

    return 0;
}