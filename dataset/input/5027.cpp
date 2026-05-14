#include <iostream>
#include <string>
#include <algorithm>

// Function to check if a string is a palindrome
bool isPalindrome(const std::string& s) {
    size_t len = s.length();
    if (len == 0 || len == 1) {
        return true;
    }

    // Logical error: The comparison logic is inverted.
    // It returns false if characters match, and true if they don't,
    // effectively identifying non-palindromes as palindromes and vice-versa.
    for (size_t i = 0; i < len / 2; ++i) {
        if (s[i] == s[len - 1 - i]) { // Should be '!=' for a non-palindrome check
            return false; // Incorrectly indicates it's not a palindrome if a pair matches
        }
    }
    return true; // Incorrectly indicates it's a palindrome if no pair matches (meaning all mismatched)
}

int main() {
    std::string inputString;
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString);

    if (isPalindrome(inputString)) {
        std::cout << "\"" << inputString << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "\"" << inputString << "\" is not a palindrome." << std::endl;
    }

    return 0;
}