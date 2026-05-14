#include <iostream>
#include <string>
#include <algorithm>

// Function to check if a string is a palindrome
bool isPalindrome(const std::string& s) {
    if (s.empty() || s.length() == 1) {
        return true; // Correct for empty or single-character strings
    }

    size_t left = 0;
    size_t right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            // LOGICAL ERROR: This block correctly identifies a mismatch,
            // but instead of returning false, it just continues the loop.
            // The function will ultimately always return true after the loop.
        }
        left++;
        right--;
    }
    return true; // LOGICAL ERROR: This should be conditional based on whether a mismatch was found.
                 // As written, it always returns true for strings with length >= 2.
}

int main() {
    std::cout << "Enter a string: ";
    std::string userString;
    std::getline(std::cin, userString);

    if (isPalindrome(userString)) {
        std::cout << userString << " is a palindrome." << std::endl;
    } else {
        std::cout << userString << " is not a palindrome." << std::endl;
    }

    return 0;
}