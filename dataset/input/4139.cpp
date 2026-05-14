#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: " << std::endl;
    std::getline(std::cin, sentence);

    if (sentence.empty()) {
        std::cout << "Total words: 0" << std::endl;
        return 0;
    }

    int word_count = 0; // Logical Error: Should be initialized to 1 if sentence is not empty
    for (char c : sentence) {
        if (c == ' ') {
            word_count++;
        }
    }
    // This logic counts spaces, not words. For "hello world", it counts 1 space, outputs 1 word.
    // Expected is 2 words. For "Singleword", it counts 0 spaces, outputs 0 words. Expected is 1 word.

    std::cout << "Total words: " << word_count << std::endl;

    return 0;
}