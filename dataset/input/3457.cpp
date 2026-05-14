#include <iostream>
#include <string>
#include <algorithm> // For std::swap

// Helper function for testing purposes: performs in-place string reversal.
// This function itself is correct and robust.
// The robustness issue lies in the main function's lack of input stream error checking.
std::string getReversedString(std::string input_word) {
    size_t n = input_word.length();
    for (size_t i = 0; i < n / 2; ++i) {
        std::swap(input_word[i], input_word[n - 1 - i]);
    }
    return input_word;
}

int main() {
    std::string word;
    std::cout << "Enter a word: ";
    std::cin >> word; // Robustness issue: No check for std::cin.fail() after input.
                      // If the input stream fails (e.g., EOF), 'word' will be empty,
                      // but the program proceeds without indicating an error.

    std::string reversed_word = getReversedString(word);
    std::cout << "Reversed word: " << reversed_word << std::endl;

    return 0;
}