#include <iostream>
#include <limits> // Required for std::numeric_limits

// Recursive function to calculate base^exponent
// This function correctly implements the logic, but uses 'int' as return type,
// which can lead to integer overflow (undefined behavior) for large results.
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
    // For large base and exponent, this multiplication can lead to integer overflow
    // if the result exceeds the maximum value an 'int' can hold (e.g., 2,147,483,647 for 32-bit int).
    return base * calculatePower(base, exponent - 1);
}

int main() {
    // Test cases
    std::cout << "INT_MAX: " << std::numeric_limits<int>::max() << std::endl; // For context

    std::cout << "2^3 = " << calculatePower(2, 3) << std::endl;      // Expected: 8
    std::cout << "5^0 = " << calculatePower(5, 0) << std::endl;      // Expected: 1
    std::cout << "0^5 = " << calculatePower(0, 5) << std::endl;      // Expected: 0
    std::cout << "3^1 = " << calculatePower(3, 1) << std::endl;      // Expected: 3
    std::cout << "-2^3 = " << calculatePower(-2, 3) << std::endl;    // Expected: -8
    std::cout << "-2^2 = " << calculatePower(-2, 2) << std::endl;    // Expected: 4
    std::cout << "7^10 = " << calculatePower(7, 10) << std::endl;    // Expected: 282475249 (fits in int)
    // Test cases designed to cause integer overflow for typical 32-bit int
    // 7^12 = 13841287201, which exceeds INT_MAX (2,147,483,647)
    std::cout << "7^12 = " << calculatePower(7, 12) << std::endl;    // Expected: 13841287201, Actual: Overflow/Undefined Behavior
    // 2^31 = 2147483648, which exceeds INT_MAX (2,147,483,647)
    std::cout << "2^31 = " << calculatePower(2, 31) << std::endl;    // Expected: 2147483648, Actual: Overflow/Undefined Behavior

    return 0;
}