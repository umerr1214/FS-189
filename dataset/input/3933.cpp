#include <iostream>
#include <limits> // Required for std::numeric_limits

// Function to reverse the digits of an integer.
// This version is robust, efficient, and readable.
// It handles negative numbers, zero, and includes explicit checks for integer overflow.
int reverseNumber(int n) {
    long long reversedNum = 0; // Use long long to detect potential overflow before casting to int
    int temp = n;

    while (temp != 0) {
        int digit = temp % 10;

        // Check for potential overflow before multiplying and adding.
        // If 'reversedNum' is already too large/small, or if adding the next 'digit'
        // would exceed INT_MAX or fall below INT_MIN, it indicates an overflow.
        if (reversedNum > std::numeric_limits<int>::max() / 10 ||
            (reversedNum == std::numeric_limits<int>::max() / 10 && digit > 7)) {
            return 0; // Indicate overflow by returning 0 (as per common practice for these problems)
        }
        if (reversedNum < std::numeric_limits<int>::min() / 10 ||
            (reversedNum == std::numeric_limits<int>::min() / 10 && digit < -8)) {
            return 0; // Indicate underflow by returning 0
        }

        reversedNum = reversedNum * 10 + digit;
        temp /= 10;
    }

    // After the loop, reversedNum holds the correct reversed value,
    // and we've already checked that it fits within int range.
    return static_cast<int>(reversedNum);
}

int main() {
    int number;
    // For automated testing, input is read from stdin without a prompt.
    std::cin >> number;
    int reversed = reverseNumber(number);
    std::cout << reversed << std::endl;
    return 0;
}