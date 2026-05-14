#include <iostream>
#include <limits> // Required for std::numeric_limits

int reverseNumber(int num) {
    long long reversed_num = 0; // Use long long to prevent intermediate overflows
    int original_num = num;

    // Handle negative numbers
    if (num < 0) {
        // Special case for INT_MIN: -INT_MIN overflows int.
        // If num is INT_MIN, directly setting num = -num would cause overflow.
        // We handle this by processing its absolute value if it fits long long,
        // and then checking for overall int overflow at the end.
        // The common approach for reverse integer problem is to return 0 on overflow.
        if (num == std::numeric_limits<int>::min()) {
            return 0; // Reversing INT_MIN will always overflow int
        }
        num = -num; // Now num is positive
    }

    while (num > 0) {
        int digit = num % 10;
        
        // Check for potential overflow before multiplication
        // If reversed_num * 10 + digit would exceed INT_MAX, then it's an overflow
        // We perform checks against INT_MAX/10 and INT_MAX % 10
        // This is a more robust check, but since reversed_num is long long,
        // intermediate overflows are less likely until the final check.
        // For standard problems, the check below is done if reversed_num is int.
        // With long long, we just check final result.

        reversed_num = reversed_num * 10 + digit;
        num /= 10;
    }

    // Apply the original sign
    if (original_num < 0) {
        reversed_num = -reversed_num;
    }

    // Check if the final reversed number fits within int limits
    if (reversed_num > std::numeric_limits<int>::max() || reversed_num < std::numeric_limits<int>::min()) {
        return 0; // Overflow for int
    }

    return static_cast<int>(reversed_num);
}

int main() {
    int num;
    if (!(std::cin >> num)) {
        return 1; // Input error
    }
    std::cout << reverseNumber(num) << std::endl;
    return 0;
}