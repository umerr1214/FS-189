#include <iostream>
#include <string>
#include <algorithm> // Not strictly needed for the palindrome logic, but often included

// Function to check if a string is a palindrome
bool is_palindrome(std::string s)
{
    // A syntax error: missing semicolon after the return statement
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());
    return s == reversed_s
} // Missing semicolon here, will cause a compile error.

int main() {
    // Test cases
    std::cout << "Is 'madam' a palindrome? " << (is_palindrome("madam") ? "Yes" : "No") << std::endl;      // Expected: Yes
    std::cout << "Is 'racecar' a palindrome? " << (is_palindrome("racecar") ? "Yes" : "No") << std::endl;  // Expected: Yes
    std::cout << "Is 'hello' a palindrome? " << (is_palindrome("hello") ? "Yes" : "No") << std::endl;      // Expected: No
    std::cout << "Is 'A' a palindrome? " << (is_palindrome("A") ? "Yes" : "No") << std::endl;              // Expected: Yes
    std::cout << "Is '' a palindrome? " << (is_palindrome("") ? "Yes" : "No") << std::endl;                // Expected: Yes
    std::cout << "Is 'ab' a palindrome? " << (is_palindrome("ab") ? "Yes" : "No") << std::endl;            // Expected: No
    std::cout << "Is 'aba' a palindrome? " << (is_palindrome("aba") ? "Yes" : "No") << std::endl;          // Expected: Yes
    std::cout << "Is 'Madam' a palindrome? " << (is_palindrome("Madam") ? "Yes" : "No") << std::endl;      // Expected: No (case-sensitive)

    return 0;
}