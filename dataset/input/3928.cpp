#include <iostream>
#include <limits> // Required for numeric_limits if checking for overflow, not strictly needed for basic reverse

int main() {
    int num;
    std::cout << "Enter an integer: "
    std::cin >> num;

    long long reversed_num = 0;
    bool is_negative = false;

    if (num < 0) {
        is_negative = true;
        // Handle INT_MIN as a special case if needed, but for general reversal, abs works.
        // std::abs(INT_MIN) is undefined behavior or INT_MIN itself depending on system.
        // For simplicity, assuming num won't be INT_MIN or that -num fits in long long.
        num = -num;
    } else if (num == 0) {
        std::cout << "Reversed number: 0" << std::endl;
        return 0;
    }

    while (num > 0) {
        int digit = num % 10;
        reversed_num = reversed_num * 10 + digit;
        num /= 10;
    }

    if (is_negative) {
        reversed_num = -reversed_num;
    }

    std::cout << "Reversed number: " << reversed_num << std::endl;

    return 0;
}