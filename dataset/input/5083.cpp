#include <iostream>
#include <limits> // Required for INT_MAX if using overflow checks, but not strictly needed for this specific bug.

// Robustness Issue: The function fails to correctly identify '0' as a palindrome.
// It returns 'false' for '0' when it should return 'true'.
bool isPalindrome(int num) {
    // Negative numbers are generally not considered palindromes due to the sign.
    if (num < 0) {
        return false;
    }

    // The logic below incorrectly handles num = 0.
    // If num is 0, the while loop (num > 0) is skipped,
    // reversedNum remains 0, originalNum is 0.
    // Then originalNum == reversedNum (0 == 0) returns true.
    // This is a common pitfall. Let's adjust the logic slightly to cause the bug.
    // A more direct way to introduce the bug for 0 is to have a condition that explicitly excludes it,
    // or a loop that doesn't run for 0. The current numerical reversal logic actually works for 0
    // if `originalNum == reversedNum` is the final check.
    //
    // Let's modify it to specifically return false for 0 to demonstrate the robustness issue.
    // This makes the error more explicit for the '0' case.
    if (num == 0) {
        return false; // BUG: 0 should be a palindrome, but this returns false.
    }

    int originalNum = num;
    long long reversedNum = 0; // Using long long to prevent overflow during reversal for other large numbers

    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

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