#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse
#include <vector>    // Unnecessary include, contributes to clutter
#include <cmath>     // Unnecessary include, contributes to clutter

// This program checks if a given integer is a palindrome.
//
// Readability / Efficiency Issue:
// The implementation converts the integer to a string to perform the palindrome check.
// While functionally correct, this approach is generally less efficient than a purely
// mathematical digit-by-digit reversal, especially for very large numbers, due to
// string conversion and manipulation overhead.
// Additionally, unnecessary includes like <vector> and <cmath> add clutter and slightly
// impact compilation time/binary size, reducing overall code quality/readability.

bool isPalindrome(int x) {
    // Negative numbers are not palindromes.
    if (x < 0) {
        return false;
    }
    
    // Convert the integer to a string.
    // This is the main efficiency concern for an integer palindrome problem.
    std::string s = std::to_string(x);
    
    // Create a reversed copy of the string.
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());
    
    // Compare the original and reversed strings.
    return s == reversed_s;
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