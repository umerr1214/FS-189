#include <iostream>
#include <string>
// No <algorithm> needed for this incorrect manual reversal

int main() {
    std::string word;
    std::cout << "Enter a word: ";
    std::cin >> word;

    // Semantic Error: The manual reversal logic is flawed.
    // It attempts to swap characters without using a temporary variable,
    // leading to data loss and an incorrect reversal.
    // For example, if word is "abcde":
    // i=0: word[0] becomes word[4] ('e'), string is "ebcde".
    // i=1: word[1] becomes word[3] ('c'), string is "eccde".
    // The original character at word[i] is lost before it can be moved to word[length - 1 - i].
    for (size_t i = 0; i < word.length() / 2; ++i) {
        word[i] = word[word.length() - 1 - i]; // Incorrect assignment for a swap
        // A correct swap would use a temporary variable:
        // char temp = word[i];
        // word[i] = word[word.length() - 1 - i];
        // word[word.length() - 1 - i] = temp;
    }

    std::cout << "Reversed word: " << word << std::endl;
    return 0;
}