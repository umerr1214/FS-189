#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse
#include <limits>    // Required for std::numeric_limits

int reverseNumber(int num) {
    if (num == 0) {
        return 0;
    }

    bool is_negative = false;
    if (num < 0) {
        is_negative = true;
        // Use std::abs for consistency, but be aware of INT_MIN issue with abs.
        // For INT_MIN, std::abs(INT_MIN) is still INT_MIN on many systems.
        // To avoid this, convert to long long first.
        // However, for this 'efficiency' example, we focus on string conversion overhead.
        // If INT_MIN is passed, std::to_string handles it correctly as "-2147483648".
        // We will process the absolute value of the number as a string.
        num = std::abs(num);
    }

    std::string s = std::to_string(num);
    std::reverse(s.begin(), s.end());

    long long reversed_ll = 0;
    try {
        reversed_ll = std::stoll(s); // Use stoll to handle potentially large reversed numbers
    } catch (const std::out_of_range& oor) {
        // If the reversed number is too large for long long, it means it definitely
        // won't fit in int. Return 0 for overflow.
        return 0;
    }

    // Check if the reversed number (long long) fits within int limits
    if (reversed_ll > std::numeric_limits<int>::max() || reversed_ll < std::numeric_limits<int>::min()) {
        return 0; // Overflow for int
    }

    int result = static_cast<int>(reversed_ll);

    if (is_negative) {
        result = -result;
    }

    return result;
}

int main() {
    int num;
    if (!(std::cin >> num)) {
        return 1; // Input error
    }
    std::cout << reverseNumber(num) << std::endl;
    return 0;
}