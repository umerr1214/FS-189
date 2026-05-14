#include <iostream>
#include <string>
#include <algorithm> // Not strictly needed for the two-pointer approach, but often included

// Correct Version: This function efficiently and correctly checks if a string is a palindrome.
// It uses a two-pointer approach, comparing characters from both ends of the string.
// The string is passed by const reference to avoid unnecessary copying.
// It handles empty strings and single-character strings correctly.
bool isPalindrome(const std::string& s) {
    if (s.empty()) {
        return true; // An empty string is considered a palindrome.
    }

    // Initialize two pointers: one at the beginning, one at the end.
    size_t left = 0;
    size_t right = s.length() - 1;

    // Iterate while the left pointer is less than the right pointer.
    // This ensures that characters are compared from the outside inwards.
    while (left < right) {
        // If characters at the current pointers do not match, it's not a palindrome.
        if (s[left] != s[right]) {
            return false;
        }
        // Move pointers inwards.
        left++;
        right--;
    }

    // If the loop completes, no mismatches were found, so it's a palindrome.
    return true;
}

int main() {
    std::string word;
    std::cout << "Enter a word: ";

    // Robust input reading: check for stream failure
    // This handles cases where input might fail (e.g., EOF, invalid data for other types)
    if (!(std::cin >> word)) {
        std::cerr << "Error: Failed to read input word. Please ensure valid input." << std::endl;
        return 1; // Indicate an error occurred
    }

    if (isPalindrome(word)) {
        std::cout << "\"" << word << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "\"" << word << "\" is not a palindrome." << std::endl;
    }

    return 0;
}