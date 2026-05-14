#include <iostream>

bool isPalindrome(int num) {
    if (num < 0) return false; // Negative numbers are generally not considered palindromes
    if (num >= 0 && num < 10) return true; // Single-digit numbers and 0 are palindromes

    int originalNum = num;
    long long reversedNum = 0; // Use long long to prevent overflow during reversal

    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }
    return originalNum == reversedNum;
}

int main() {
    int userNum;
    std::cout << "Enter an integer: " // SYNTAX ERROR: Missing semicolon
    std::cin >> userNum;

    if (isPalindrome(userNum)) {
        std::cout << userNum << " is a palindrome." << std::endl;
    } else {
        std::cout << userNum << " is not a palindrome." << std::endl;
    }

    return 0;
}