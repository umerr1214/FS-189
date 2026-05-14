#include <iostream>
#include <string> // Required for driver, not for problem logic

// Function containing the core logic
void solve() {
    int base, exponent;
    std::cout << "Enter base (positive integer): ";
    std::cin >> base;
    std::cout << "Enter exponent (positive integer): ";
    std::cin >> exponent;

    if (base <= 0 || exponent <= 0) {
        std::cerr << "Error: Both base and exponent must be positive integers." << std::endl;
        // In a real program, might exit or throw an exception.
        // For this dataset, we print an error and return to allow test case capture.
        return;
    }

    // Robustness issue: 'int' can overflow for large results.
    // For example, 2^31 or 7^12 will exceed the maximum value of a 32-bit signed int.
    int result = 1; 
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }

    std::cout << "Result: " << result << std::endl;
}

int main() {
    solve();
    return 0;
}