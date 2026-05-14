#include <iostream>
#include <string>
#include <sstream> // Required for std::stringstream
#include <vector> // Included for completeness

// Correct, robust, readable, and efficient function to count words.
// Uses std::stringstream to extract words, which handles various
// spacing scenarios (leading, trailing, multiple spaces) gracefully.
int countWords(const std::string& sentence) {
    std::stringstream ss(sentence);
    std::string word;
    int wordCount = 0;

    // The '>>' operator extracts words separated by whitespace.
    // It automatically skips leading whitespace and stops at the next whitespace.
    while (ss >> word) {
        wordCount++;
    }
    return wordCount;
}

int main() {
    std::string sentence;
    std::getline(std::cin, sentence);
    std::cout << countWords(sentence) << std::endl;
    return 0;
}