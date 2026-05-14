#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    if (sentence.empty()) {
        std::cout << "Number of words: 0" << std::endl;
        return 0;
    }

    std::stringstream ss(sentence);
    std::string word;
    int wordCount = 0;

    while (ss >> word) {
        wordCount++;
    }

    std::cout << "Number of words: " << wordCount << std::endl // Syntax Error: Missing semicolon
    return 0;
}