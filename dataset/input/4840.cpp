#include <iostream>
#include <string>
#include <sstream> // Include for stringstream

int main() {
    std::cout << "Enter a sentence: ";
    std::string sentence;
    std::getline(std::cin, sentence);

    std::stringstream ss(sentence);
    std::string word;
    int word_count = 0;

    while (ss >> word) {
        word_count++;
    }

    std::cout << "Total number of words: " << word_count // Syntax Error: Missing semicolon here
    return 0;
}