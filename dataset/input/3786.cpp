#include <iostream>
#include <string>
#include <algorithm>

// Function to check if a word is a palindrome (case-sensitive)
bool isPalindrome(const std::string& word) {
    if (word.length() <= 1) {
        return true;
    }

    // Semantic error: Incorrect indexing for palindrome check.
    // 'word.length() - i' is used instead of 'word.length() - 1 - i'.
    // When i = 0, this attempts to access 'word[word.length()]', which is out-of-bounds,
    // leading to undefined behavior (e.g., crash, corrupted data).
    for (size_t i = 0; i < word.length() / 2; ++i) {
        if (word[i] != word[word.length() - i]) { // Semantic error here
            return false;
        }
    }
    return true;
}

int main() {
    std::string word;
    std::cout << "Enter a word: ";
    std::cin >> word;

    if (isPalindrome(word)) {
        std::cout << "The word \"" << word << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "The word \"" << word << "\" is not a palindrome." << std::endl;
    }

    return 0;
}