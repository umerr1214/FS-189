#include <iostream>

// Recursive function to calculate base^exponent
int calculatePower(int base, int exponent) {
    // Base case: exponent is 0, result is 1
    if (exponent == 0) {
        return 1;
    }
    // Base case: base is 0 (and exponent > 0), result is 0
    if (base == 0) {
        return 0;
    }
    // Recursive step
    return base * calculatePower(base, exponent - 1);
}

int main() {
    // Test cases
    std::cout << "2^3 = " << calculatePower(2, 3) << std::endl;      // Expected: 8
    std::cout << "5^0 = " << calculatePower(5, 0) << std::endl;      // Expected: 1
    std::cout << "0^5 = " << calculatePower(0, 5) << std::endl;      // Expected: 0
    std::cout << "3^1 = " << calculatePower(3, 1) << std::endl;      // Expected: 3
    std::cout << "-2^3 = " << calculatePower(-2, 3) << std::endl;    // Expected: -8
    std::cout << "-2^2 = " << calculatePower(-2, 2) << std::endl;    // Expected: 4
    std::cout << "1^10 = " << calculatePower(1, 10) << std::endl;    // Expected: 1
    std::cout << "-1^11 = " << calculatePower(-1, 11) << std::endl;  // Expected: -1

    return 0 // Syntax Error: Missing semicolon
}