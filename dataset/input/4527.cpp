#include <iostream>
#include <limits> // For std::numeric_limits, good practice although not strictly needed for this solution's logic

// This program checks if a given integer is a palindrome using an efficient mathematical approach.
//
// Correct Version:
// This implementation correctly handles all specified cases:
// - Returns false for negative numbers (standard definition of integer palindromes).
// - Returns true for 0.
// - Accurately reverses positive integers and compares them to the original.
// - Uses `long long` for `reversed_num` to prevent potential overflow during reversal
//   if the reversed number exceeds `INT_MAX`, ensuring correctness for large inputs within `int` range.
// - It is efficient as it avoids string conversions and operates purely with integer arithmetic.

bool isPalindrome(int x) {
    // Negative numbers are generally not considered palindromes.
    if (x < 0) {
        return false;
    }

    // 0 is a palindrome.
    if (x == 0) {
        return true;
    }

    long long reversed_num = 0; // Use long long to prevent overflow during reversal for large numbers
    int original_num = x;       // Store the original number for comparison

    // Reverse the number mathematically.
    // The loop continues as long as x is positive.
    while (x > 0) {
        int digit = x % 10;
        reversed_num = reversed_num * 10 + digit;
        x /= 10;
    }
    
    // Compare the original number with its reversed version.
    // If the reversed_num overflowed beyond INT_MAX, it cannot be equal to original_num (an int).
    // So, this comparison implicitly handles potential overflow of the reversed number.
    return original_num == reversed_num;
}

int main() {
    std::cout << "Checking palindrome status for various integers:\n";

    // Example usage (these are for demonstration, actual test cases are in JSON)
    std::cout << "121 is palindrome: " << (isPalindrome(121) ? "true" : "false") << std::endl;      // Expected: true
    std::cout << "0 is palindrome: " << (isPalindrome(0) ? "true" : "false") << std::endl;         // Expected: true
    std::cout << "-121 is palindrome: " << (isPalindrome(-121) ? "true" : "false") << std::endl;    // Expected: false
    std::cout << "123 is palindrome: " << (isPalindrome(123) ? "true" : "false") << std::endl;      // Expected: false
    std::cout << "10 is palindrome: " << (isPalindrome(10) ? "true" : "false") << std::endl;        // Expected: false
    
    return 0;
}