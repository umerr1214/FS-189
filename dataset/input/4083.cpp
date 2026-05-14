#include <iostream>
#include <string> // For std::to_string in main output

// Function to check if a number is a palindrome.
// This version is correct, efficient, and readable.
bool isPalindrome(int num) {
    // Negative numbers are not considered palindromes.
    if (num < 0) {
        return false;
    }

    // 0 is a palindrome.
    if (num == 0) {
        return true;
    }

    // Numbers ending in 0 (e.g., 120) cannot be palindromes unless the number itself is 0.
    // This is an important optimization and correctly handles cases like 10, 100, etc.
    // If a number ends in 0, its reverse would start with 0 (e.g., 120 -> 021),
    // which is not equal to the original number (unless the number is just 0).
    if (num % 10 == 0) {
        return false;
    }

    int reversedHalf = 0;
    // We only need to reverse half of the number.
    // The loop continues as long as num is greater than reversedHalf.
    // When num becomes less than or equal to reversedHalf, we've processed half the digits.
    while (num > reversedHalf) {
        reversedHalf = reversedHalf * 10 + (num % 10);
        num /= 10;
    }

    // For even-length numbers, num and reversedHalf will be equal (e.g., 1221 -> num=12, reversedHalf=12).
    // For odd-length numbers, num will be the middle digit, and reversedHalf will have one extra digit.
    // In the odd case, we can remove the last digit from reversedHalf (reversedHalf / 10) to compare.
    // E.g., 121 -> num=1, reversedHalf=12. Compare num (1) with reversedHalf/10 (12/10=1).
    return num == reversedHalf || num == reversedHalf / 10;
}

int main() {
    int userInput;
    std::cout << "Enter an integer: ";
    std::cin >> userInput;

    if (isPalindrome(userInput)) {
        std::cout << userInput << " is a palindrome." << std::endl;
    } else {
        std::cout << userInput << " is not a palindrome." << std::endl;
    }

    return 0;
}