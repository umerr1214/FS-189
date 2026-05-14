#include <iostream>
#include <cmath>  // Required for std::abs
#include <limits> // Required for std::numeric_limits

// Correct Version:
// This implementation is robust, efficient, and readable.
// It correctly handles the edge case of 0, negative numbers,
// and uses an efficient mathematical approach (repeated division by 10).
// It also explicitly addresses the `INT_MIN` edge case using `long long`
// to ensure `std::abs` behavior is safe and well-defined.
int countDigits(int num) {
    if (num == 0) {
        return 1; // 0 has one digit
    }
    int count = 0;
    // Use long long for the working copy to safely handle std::abs(INT_MIN)
    // without undefined behavior.
    long long temp_num = num;
    if (temp_num < 0) {
        temp_num = -temp_num; // Make positive
    }

    while (temp_num > 0) {
        temp_num /= 10;
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