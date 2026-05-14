#include <iostream>
#include <string>
#include <algorithm> // Not strictly necessary for this implementation, but often included

// Function to check if a string is a palindrome
bool isPalindrome(const std::string& s) {
    if (s.empty()) {
        return true; // Correct for empty strings
    }
    // SEMANTIC ERROR: s.length() - i will cause out-of-bounds access.
    // When i = 0, s.length() - i becomes s.length(), which is an invalid index for std::string.
    // The valid range for std::string indices is 0 to s.length() - 1.
    for (size_t i = 0; i < s.length() / 2; ++i) {
        if (s[i] != s[s.length() - i]) { // ERROR: Should be s[s.length() - 1 - i]
            return false;
        }
    }
    return true;
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