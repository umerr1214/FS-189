#include <iostream>
#include <string>
#include <algorithm>

// Function to check if a string is a palindrome
bool is_palindrome(std::string s)
{
    // Logical Error: Only checks the first character against the last.
    // It doesn't iterate through the entire string.
    if (s.empty()) {
        return true;
    }
    // This logic only checks the first and last character, not the entire string
    return s[0] == s[s.length() - 1];
}

int main() {
    // Test cases
    std::cout << "Is 'madam' a palindrome? " << (is_palindrome("madam") ? "Yes" : "No") << std::endl;      // Expected: Yes, Actual: Yes (incorrectly for full string)
    std::cout << "Is 'racecar' a palindrome? " << (is_palindrome("racecar") ? "Yes" : "No") << std::endl;  // Expected: Yes, Actual: Yes (incorrectly for full string)
    std::cout << "Is 'hello' a palindrome? " << (is_palindrome("hello") ? "Yes" : "No") << std::endl;      // Expected: No, Actual: No (correct for this specific case, 'h' != 'o')
    std::cout << "Is 'A' a palindrome? " << (is_palindrome("A") ? "Yes" : "No") << std::endl;              // Expected: Yes, Actual: Yes (s[0] == s[0])
    std::cout << "Is '' a palindrome? " << (is_palindrome("") ? "Yes" : "No") << std::endl;                // Expected: Yes, Actual: Yes
    std::cout << "Is 'ab' a palindrome? " << (is_palindrome("ab") ? "Yes" : "No") << std::endl;            // Expected: No, Actual: No ('a' != 'b')
    std::cout << "Is 'aba' a palindrome? " << (is_palindrome("aba") ? "Yes" : "No") << std::endl;          // Expected: Yes, Actual: Yes (incorrectly for full string)
    std::cout << "Is 'Madam' a palindrome? " << (is_palindrome("Madam") ? "Yes" : "No") << std::endl;      // Expected: No, Actual: No ('M' != 'm')
    std::cout << "Is 'abba' a palindrome? " << (is_palindrome("abba") ? "Yes" : "No") << std::endl;        // Expected: Yes, Actual: Yes (incorrectly for full string)
    std::cout << "Is 'abca' a palindrome? " << (is_palindrome("abca") ? "Yes" : "No") << std::endl;        // Expected: No, Actual: Yes ('a' == 'a') - This case explicitly shows the error.

    return 0;
}