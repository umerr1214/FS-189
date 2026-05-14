#include <iostream>
#include <string>
#include <algorithm> // Included for general practice, though not used in the flawed logic

// Function to check if a word is a palindrome (case-sensitive)
bool isPalindrome(std::string word) { // Passed by value to allow modification
    // Logical error: The function reverses the input word but then compares the reversed word to itself.
    // This will always result in the comparison being true.
    std::reverse(word.begin(), word.end());
    return word == word; // This comparison will always be true
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