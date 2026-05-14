#include <iostream>
#include <limits> // Potentially useful for checking INT_MAX, but not directly used in the erroneous logic.

// Function to reverse an integer using a while loop.
// This function has a semantic error: it doesn't handle potential integer overflow
// when the reversed number exceeds the maximum value for 'int'.
int reverse_integer_logic(int n) {
    int reversed_n = 0;
    int remainder;
    bool is_negative = false;

    if (n == 0) return 0;

    if (n < 0) {
        is_negative = true;
        n = -n;
    }

    while (n != 0) {
        remainder = n % 10;
        // This multiplication (reversed_n * 10) can cause integer overflow
        // if reversed_n is already large enough that multiplying by 10
        // pushes it beyond INT_MAX (e.g., 2,147,483,647 for a 32-bit int).
        // For example, reversing 1000000007 should yield 7000000001,
        // which is larger than INT_MAX, leading to undefined behavior (often a negative value).
        reversed_n = reversed_n * 10 + remainder;
        n /= 10;
    }

    if (is_negative) {
        reversed_n = -reversed_n;
    }
    return reversed_n;
}

int main() {
    int input_num;
    std::cout << "Enter an integer: ";
    std::cin >> input_num;

    int result = reverse_integer_logic(input_num);
    std::cout << "Reversed number: " << result << std::endl;
    return 0;
}