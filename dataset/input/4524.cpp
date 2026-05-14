#include <iostream>
#include <limits> // Required for std::numeric_limits

bool isPalindrome(int num) {
    if (num < 0) {
        return false; // Negative numbers are not palindromes
    }
    if (num == 0) {
        return true; // 0 is a palindrome
    }

    int originalNum = num;
    // Semantic error: 'reversedNum' is declared as 'int'.
    // For large input numbers, the reversed value can exceed the maximum capacity of an 'int' (INT_MAX).
    // This leads to integer overflow, which is undefined behavior for signed integers,
    // resulting in incorrect or unexpected results for palindrome checks.
    int reversedNum = 0; 
    while (num > 0) {
        int digit = num % 10;
        // No explicit check for overflow before `reversedNum * 10 + digit`.
        // If an overflow occurs here, the value of `reversedNum` becomes incorrect.
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }
    return originalNum == reversedNum;
}

int main() {
    // Driver code will be in JSON to test the isPalindrome function.
    return 0;
}