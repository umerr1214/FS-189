#include <iostream>
#include <string>
#include <sstream> // For std::stringstream
#include <limits>    // For std::numeric_limits

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    // Use std::getline to read the entire line, including spaces
    std::getline(std::cin, sentence);

    std::stringstream ss(sentence);
    std::string word;
    int wordCount = 0;

    // std::stringstream extracts words separated by whitespace (including multiple spaces,
    // leading/trailing spaces, and tabs/newlines if present). This is a robust and idiomatic
    // C++ way to count words, fulfilling the requirement correctly and efficiently for typical inputs.
    while (ss >> word) {
        wordCount++;
    }

    std::cout << "Total number of words: " << wordCount << std::endl;

    return 0;
}