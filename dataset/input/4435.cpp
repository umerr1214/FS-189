#include <iostream>

// Implements a recursive function calculatePower with a robustness issue:
// It incorrectly returns 0 for base 0 and exponent 0.
// It also does not handle potential integer overflow for large results.
int calculatePower(int base, int exponent) {
    if (base == 0) {
        // Robustness issue: For 0^0, this returns 0. Mathematically, 0^0 is often treated as 1.
        // For 0^positive_exponent, this correctly returns 0.
        return 0;
    }
    if (exponent == 0) {
        // This handles x^0 = 1 for x != 0.
        return 1;
    }
    // No explicit overflow check. For very large base or exponent,
    // the intermediate or final result might exceed INT_MAX without warning.
    return base * calculatePower(base, exponent - 1);
}

int main() {
    // This main function is for local compilation and testing.
    // The actual testing environment will use the driver code provided in the JSON.
    std::cout << "Running local tests for 4435.cpp" << std::endl;
    std::cout << "calculatePower(2, 3) = " << calculatePower(2, 3) << " (Expected: 8)" << std::endl;
    std::cout << "calculatePower(5, 0) = " << calculatePower(5, 0) << " (Expected: 1)" << std::endl;
    std::cout << "calculatePower(0, 0) = " << calculatePower(0, 0) << " (Expected: 1, Actual: 0 - Robustness issue)" << std::endl;
    std::cout << "calculatePower(0, 5) = " << calculatePower(0, 5) << " (Expected: 0)" << std::endl;
    std::cout << "calculatePower(10, 2) = " << calculatePower(10, 2) << " (Expected: 100)" << std::endl;
    std::cout << "calculatePower(-2, 3) = " << calculatePower(-2, 3) << " (Expected: -8)" << std::endl;
    std::cout << "calculatePower(-2, 4) = " << calculatePower(-2, 4) << " (Expected: 16)" << std::endl;
    // For large numbers, potential overflow is not checked, but 2^30 fits int.
    std::cout << "calculatePower(2, 30) = " << calculatePower(2, 30) << " (Expected: 1073741824)" << std::endl;
    return 0;
}