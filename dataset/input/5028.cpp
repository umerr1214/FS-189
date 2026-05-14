#include <iostream>
#include <string>
#include <algorithm>

// Function to check if a string is a palindrome
bool isPalindrome(const std::string& s) {
    size_t len = s.length();
    if (len == 0 || len == 1) {
        return true;
    }

    // Semantic error: Accessing s[len - i] instead of s[len - 1 - i].
    // When i = 0, this attempts to access s[len], which is out-of-bounds.
    // This leads to undefined behavior.
    for (size_t i = 0; i < len / 2; ++i) {
        if (s[i] != s[len - i]) { // Should be s[len - 1 - i]
            return false;
        }
    }
    return true;
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