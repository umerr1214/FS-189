#include <iostream>
#include <cmath> // Required for std::abs
#include <limits> // For std::numeric_limits

// Robustness Issue:
// This implementation fails to correctly handle the input `0`,
// returning `0` digits instead of the expected `1`.
// It correctly handles positive and negative numbers (by taking absolute value).
int countDigits(int num) {
    if (num == 0) {
        return 0; // Robustness Issue: Incorrectly returns 0 for input 0. Expected: 1.
    }
    int count = 0;
    // Take absolute value to handle negative numbers,
    // assuming std::abs for int handles INT_MIN or it's not tested.
    // If num is INT_MIN, std::abs(INT_MIN) is undefined behavior for int.
    // For this robustness issue, the primary focus is the '0' case.
    num = std::abs(num);

    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
}

int main() {
    std::cout << "Testing countDigits(12345): " << countDigits(12345) << std::endl;
    std::cout << "Testing countDigits(0): " << countDigits(0) << std::endl;
    std::cout << "Testing countDigits(-9876): " << countDigits(-9876) << std::endl;
    std::cout << "Testing countDigits(7): " << countDigits(7) << std::endl;
    std::cout << "Testing countDigits(-1): " << countDigits(-1) << std::endl;
    std::cout << "Testing countDigits(" << std::numeric_limits<int>::max() << "): " << countDigits(std::numeric_limits<int>::max()) << std::endl;
    std::cout << "Testing countDigits(" << std::numeric_limits<int>::min() << "): " << countDigits(std::numeric_limits<int>::min()) << std::endl;
    return 0;
}