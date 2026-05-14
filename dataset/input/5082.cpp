#include <iostream>
#include <limits> // Required for std::numeric_limits

bool isPalindrome(int num) {
    if (num < 0) return false; // Negative numbers are generally not considered palindromes
    if (num >= 0 && num < 10) return true; // Single-digit numbers and 0 are palindromes

    int originalNum = num;
    int reversedNum = 0; // SEMANTIC ERROR: Using 'int' for reversedNum can lead to integer overflow

    while (num > 0) {
        int digit = num % 10;
        // Potential integer overflow if reversedNum * 10 + digit exceeds INT_MAX
        // For example, if num is 1234567899, its reverse 9987654321 exceeds INT_MAX
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }
    return originalNum == reversedNum;
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