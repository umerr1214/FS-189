#include <iostream>
#include <string>
#include <algorithm>

// Function to check if a word is a palindrome (case-sensitive)
bool isPalindrome(const std::string& word) {
    std::string reversed_word = word;
    std::reverse(reversed_word.begin(), reversed_word.end());
    return word == reversed_word;
}

int main() {
    std::string word;
    std::cout << "Enter a word: ";
    std::cin >> word // Missing semicolon here, causing a syntax error

    if (isPalindrome(word)) {
        std::cout << "The word \"" << word << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "The word \"" << word << "\" is not a palindrome." << std::endl;
    }

    return 0;
}