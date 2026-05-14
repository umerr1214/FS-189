#include <iostream>
#include <string>

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    int wordCount = 0;

    if (sentence.empty()) {
        std::cout << "Number of words: 0" << std::endl;
        return 0;
    }

    size_t spaceCount = 0;
    for (char c : sentence) {
        if (c == ' ') {
            spaceCount++;
        }
    }

    // Semantic Error: The logic for counting words based on spaces is semantically flawed
    // for the case of a single-word sentence.
    // It correctly handles empty sentences and multi-word sentences (spaceCount + 1),
    // but for a single word (e.g., "Hello"), spaceCount is 0, and the logic incorrectly
    // sets wordCount to 0, misinterpreting the meaning of "no spaces" for a non-empty string.
    if (spaceCount > 0) {
        wordCount = spaceCount + 1;
    } else {
        // This branch is executed when there are no spaces in a non-empty sentence.
        // Semantically, this implies a single word, so wordCount should be 1.
        // Setting it to 0 here is a semantic misinterpretation of the problem's definition.
        wordCount = 0; 
    }

    std::cout << "Number of words: " << wordCount << std::endl;

    return 0;
}