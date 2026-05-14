#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: " << std::endl // Missing semicolon here
    std::getline(std::cin, sentence);

    if (sentence.empty()) {
        std::cout << "Total words: 0" << std::endl;
        return 0;
    }

    int word_count = 1; // Start with 1 word if sentence is not empty
    for (char c : sentence) {
        if (c == ' ') {
            word_count++;
        }
    }

    std::cout << "Total words: " << word_count << std::endl;

    return 0;
}