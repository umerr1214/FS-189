#include <iostream>

bool isPalindrome(int num) {
    if (num < 0) return false; // Negative numbers are generally not considered palindromes
    if (num >= 0 && num < 10) return true; // Single-digit numbers and 0 are palindromes

    // LOGICAL ERROR: The original value of 'num' is not stored in a temporary variable.
    // 'num' itself is modified in the loop, so by the end of the loop, 'num' will be 0.
    // The comparison `num == reversedNum` will then be incorrect for any non-zero number.
    // int originalNum = num; // This line is intentionally missing for the logical error

    long long reversedNum = 0;

    while (num > 0) { // 'num' is consumed here
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }
    // LOGICAL ERROR: 'num' is now 0, so this comparison will only be true if reversedNum is also 0.
    // This makes the function incorrectly return false for all multi-digit palindromes.
    return num == reversedNum;
}

int main() {
    int userNum;
    std::cout << "Enter an integer: ";
    std::cin >> userNum;

    if (isPalindrome(userNum)) {
        std::cout << userNum << " is a palindrome." << std::endl;
    } else {
        std::cout << userNum << " is not a palindrome." << std::endl;
    }

    return 0;
}