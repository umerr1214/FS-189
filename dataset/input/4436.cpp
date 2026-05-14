#include <iostream>

// Implements a recursive function calculatePower with readability/efficiency issues:
// It uses a naive O(exponent) approach instead of O(log exponent).
// It includes a redundant check for base == 1.
int calculatePower(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    if (base == 0) { // Handles 0^positive. 0^0 is handled by exponent == 0.
        return 0;
    }
    // Readability/Efficiency issue: This check is not strictly necessary as the general recursive case
    // (1 * calculatePower(1, exponent - 1)) would also correctly yield 1.
    // It adds a redundant condition without improving logic or performance.
    if (base == 1) {
        return 1;
    }
    // Efficiency issue: This is a linear O(exponent) recursive approach.
    // For large exponents, this will be significantly slower than a binary exponentiation (O(log exponent)) method.
    return base * calculatePower(base, exponent - 1);
}

int main() {
    // This main function is for local compilation and testing.
    // The actual testing environment will use the driver code provided in the JSON.
    std::cout << "Running local tests for 4436.cpp" << std::endl;
    std::cout << "calculatePower(2, 3) = " << calculatePower(2, 3) << " (Expected: 8)" << std::endl;
    std::cout << "calculatePower(5, 0) = " << calculatePower(5, 0) << " (Expected: 1)" << std::endl;
    std::cout << "calculatePower(0, 0) = " << calculatePower(0, 0) << " (Expected: 1)" << std::endl;
    std::cout << "calculatePower(0, 5) = " << calculatePower(0, 5) << " (Expected: 0)" << std::endl;
    std::cout << "calculatePower(1, 100) = " << calculatePower(1, 100) << " (Expected: 1 - shows redundant check)" << std::endl;
    std::cout << "calculatePower(3, 15) = " << calculatePower(3, 15) << " (Expected: 14348907 - highlights inefficiency)" << std::endl;
    std::cout << "calculatePower(-2, 3) = " << calculatePower(-2, 3) << " (Expected: -8)" << std::endl;
    std::cout << "calculatePower(-2, 4) = " << calculatePower(-2, 4) << " (Expected: 16)" << std::endl;
    std::cout << "calculatePower(2, 30) = " << calculatePower(2, 30) << " (Expected: 1073741824)" << std::endl;
    return 0;
}