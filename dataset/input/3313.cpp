#include <iostream>
#include <limits> // Required for std::numeric_limits

int reverseNumber(int num) {
    int reversed_num = 0;
    bool is_negative = false;

    // Handle INT_MIN as a special case for robustness flaw:
    // -num for INT_MIN results in overflow (it remains INT_MIN on many systems)
    // and then the while loop doesn't execute, returning 0.
    // This is an incorrect handling.
    if (num < 0) {
        is_negative = true;
        // This line causes overflow if num is std::numeric_limits<int>::min()
        // For example, on a 32-bit system, -(-2147483648) is still -2147483648.
        num = -num;
    }

    // This loop does not check for overflow of 'reversed_num'
    // For large numbers, reversed_num * 10 + digit can exceed INT_MAX,
    // leading to an incorrect (overflowed) value.
    while (num > 0) {
        int digit = num % 10;
        reversed_num = reversed_num * 10 + digit; // Potential overflow here
        num /= 10;
    }

    if (is_negative) {
        reversed_num = -reversed_num;
    }

    return reversed_num;
}

int main() {
    int num;
    if (!(std::cin >> num)) {
        return 1; // Input error
    }
    std::cout << reverseNumber(num) << std::endl;
    return 0;
}