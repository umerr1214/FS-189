#include <iostream>
#include <limits> // Required for std::numeric_limits

/**
 * @brief Doubles the value of an integer by reference.
 *
 * This function takes an integer by reference and modifies its value
 * by multiplying it by 2. It does not include explicit checks for
 * integer overflow, which can lead to undefined behavior for very large inputs.
 *
 * @param num A reference to an integer whose value is to be doubled.
 */
void doubleValue(int& num) {
    num *= 2; // Simple multiplication to double the value.
              // This operation can cause integer overflow if num is too large.
}

int main() {
    // --- Test Case 1: Normal operation ---
    int val1 = 10;
    std::cout << "Original: " << val1 << std::endl;
    doubleValue(val1);
    std::cout << "Doubled: " << val1 << std::endl; // Expected: 20

    std::cout << std::endl;

    // --- Test Case 2: Demonstrating Robustness Issue (Integer Overflow) ---
    // Choose a value that, when doubled, will exceed INT_MAX.
    // For a 32-bit signed int, INT_MAX is 2,147,483,647.
    // INT_MAX / 2 + 1 is a common value that causes overflow when doubled.
    int val2 = std::numeric_limits<int>::max() / 2 + 1;
    std::cout << "Original: " << val2 << std::endl;
    doubleValue(val2);
    // On most systems, this will result in a negative number due to two's complement overflow.
    std::cout << "Doubled: " << val2 << std::endl; // Actual output will be incorrect due to overflow

    return 0;
}