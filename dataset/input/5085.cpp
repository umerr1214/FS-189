#include <iostream>
#include <limits> // Included for clarity, though `long long` handles most cases.

// Correct Version: Efficient numerical approach, handles edge cases (0, negative numbers),
// and uses appropriate data types to prevent overflow, promoting good readability.
bool isPalindrome(int num) {
    // Negative numbers are generally not considered palindromes due to the leading sign.
    if (num < 0) {
        return false;
    }

    // Single digit numbers (including 0) are palindromes.
    if (num == 0) {
        return true;
    }

    int originalNum = num;
    long long reversedNum = 0; // Use long long to prevent potential overflow when reversing large integers

    // Reverse the number digit by digit
    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    // Compare the original number with its reversed version.
    // If the original number was a palindrome, its reversed value will fit within `int`.
    // The `long long` for `reversedNum` primarily protects against overflow during intermediate steps
    // for non-palindromic numbers whose reverse might exceed `INT_MAX`.
    return originalNum == static_cast<int>(reversedNum);
}

int main() {
    std::cout << "Enter an integer: ";
    int number;
    std::cin >> number;

    if (isPalindrome(number)) {
        std::cout << number << " is a palindrome." << std::endl;
    } else {
        std::cout << number << " is not a palindrome." << std::endl;
    }

    return 0;
}