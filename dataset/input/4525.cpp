#include <iostream>
#include <limits> // Required for std::numeric_limits

// This program checks if a given integer is a palindrome.
//
// Robustness Issue:
// This implementation incorrectly considers negative numbers whose absolute value
// is a palindrome as palindromes themselves (e.g., -121, -1).
// Most standard definitions for integer palindromes only apply to non-negative integers.
// While the mathematical reversal works, the semantic interpretation for negative numbers is flawed.
// For example, isPalindrome(-121) will return true.

bool isPalindrome(int x) {
    long long reversed_num = 0; // Use long long to prevent overflow during reversal for large numbers
    int temp_num = x;           // Use a temporary variable to manipulate without changing original x

    // Handles 0 correctly (0 % 10 = 0, reversed_num remains 0, 0 == 0 is true)
    // Handles positive palindromes (e.g., 121) correctly.
    // Handles negative palindromes (e.g., -121) by reversing them to themselves,
    // leading to `x == reversed_num` being true, which is the robustness issue.
    while (temp_num != 0) {
        int digit = temp_num % 10;
        reversed_num = reversed_num * 10 + digit;
        temp_num /= 10;
    }
    
    // The comparison `x == reversed_num` will evaluate to true for negative inputs
    // like -121 or -1, as their mathematical reversal is themselves.
    // This is contrary to the common definition of an integer palindrome.
    return x == reversed_num;
}

int main() {
    std::cout << "Checking palindrome status for various integers:\n";

    // Example usage (these are for demonstration, actual test cases are in JSON)
    std::cout << "121 is palindrome: " << (isPalindrome(121) ? "true" : "false") << std::endl;      // Expected: true
    std::cout << "0 is palindrome: " << (isPalindrome(0) ? "true" : "false") << std::endl;         // Expected: true
    std::cout << "-121 is palindrome: " << (isPalindrome(-121) ? "true" : "false") << std::endl;    // Expected: true (Robustness Issue)
    std::cout << "123 is palindrome: " << (isPalindrome(123) ? "true" : "false") << std::endl;      // Expected: false
    std::cout << "-1 is palindrome: " << (isPalindrome(-1) ? "true" : "false") << std::endl;       // Expected: true (Robustness Issue)
    std::cout << "10 is palindrome: " << (isPalindrome(10) ? "true" : "false") << std::endl;        // Expected: false
    
    return 0;
}