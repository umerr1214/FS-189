#include <iostream>
#include <string>
#include <algorithm> // Required for std::count

// Function to count words assuming single spaces and no leading/trailing spaces.
// This version has a robustness issue: it incorrectly counts 1 word for an empty string.
int countWords(const std::string& sentence) {
    // If the string is empty, std::count will return 0.
    // Adding 1 to it will result in 1, which is incorrect for an empty string (should be 0 words).
    return std::count(sentence.begin(), sentence.end(), ' ') + 1;
}

int main() {
    std::cout << "Enter a sentence: ";
    std::string sentence;
    std::getline(std::cin, sentence);

    int numWords = countWords(sentence);
    std::cout << "Number of words: " << numWords << std::endl;

    return 0;
}