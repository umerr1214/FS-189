#include <iostream>
#include <limits> // For std::numeric_limits

void increment_by_ten(int& value) {
    // This function increments by ten.
    // It does not explicitly check for integer overflow,
    // which can lead to undefined behavior for very large 'value'.
    value += 10;
}

int main() {
    // Test case 1: Normal operation
    int num1 = 5;
    std::cout << "--- Test Case 1: Normal Value ---" << std::endl;
    std::cout << "Value before: " << num1 << std::endl;
    increment_by_ten(num1);
    std::cout << "Value after: " << num1 << std::endl;
    std::cout << std::endl;

    // Test case 2: Value close to INT_MAX to demonstrate potential overflow
    // For a 32-bit signed int, INT_MAX is 2147483647.
    // Adding 10 to (INT_MAX - 5) will cause an overflow.
    int num3 = std::numeric_limits<int>::max() - 5; // 2147483642
    std::cout << "--- Test Case 2: Value near INT_MAX (potential overflow) ---" << std::endl;
    std::cout << "Value before: " << num3 << std::endl;
    increment_by_ten(num3);
    std::cout << "Value after: " << num3 << std::endl;
    std::cout << std::endl;

    return 0;
}