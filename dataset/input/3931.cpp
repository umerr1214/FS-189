#include <iostream>
#include <limits> // Required for INT_MAX, but not directly used in the logic for this specific robustness issue

// Function to reverse the digits of an integer.
// This version has a robustness issue: it does not explicitly check for
// integer overflow if the reversed number exceeds the maximum value of `int`.
// While the modulo/division approach naturally handles negative numbers
// (e.g., -123 becomes -321), it will silently wrap around on overflow for large positive inputs.
int reverseNumber(int n) {
    int reversedNum = 0;
    int temp = n;

    while (temp != 0) {
        int digit = temp % 10;
        // No explicit overflow check here. If reversedNum * 10 + digit exceeds
        // INT_MAX or goes below INT_MIN, it will result in an incorrect, wrapped value.
        reversedNum = reversedNum * 10 + digit;
        temp /= 10;
    }

    return reversedNum;
}

int main() {
    int num;
    // For automated testing, input is read from stdin without a prompt.
    std::cin >> num;
    int reversed = reverseNumber(num);
    std::cout << reversed << std::endl;
    return 0;
}