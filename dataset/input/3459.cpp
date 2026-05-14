#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse

// Helper function for testing purposes: reverses a string efficiently and clearly.
std::string getReversedString(std::string input_word) {
    // std::reverse reverses the string in-place, which is efficient (O(N) time complexity).
    std::reverse(input_word.begin(), input_word.end());
    return input_word;
}

int main() {
    std::string word;
    std::cout << "Enter a word: ";
    std::cin >> word; // Reads a single word (sequence of non-whitespace characters)

    std::string reversed_word = getReversedString(word);
    std::cout << "Reversed word: " << reversed_word << std::endl;

    return 0;
}