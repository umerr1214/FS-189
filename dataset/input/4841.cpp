#include <iostream>
#include <string>
#include <sstream> // Not used for counting, but included

int main() {
    std::cout << "Enter a sentence: ";
    std::string sentence;
    std::getline(std::cin, sentence);

    int word_count = 0;

    // Logical Error: This logic attempts to count words by assuming each space
    // indicates a new word, starting with 1 if the sentence is not empty.
    // This fails for multiple consecutive spaces and strings consisting only of spaces,
    // and leading/trailing spaces.
    if (!sentence.empty()) {
        word_count = 1; // Assume at least one word if not empty
        for (char c : sentence) {
            if (c == ' ') {
                word_count++; // Increments for every space, leading to overcounting
            }
        }
    }

    std::cout << "Total number of words: " << word_count << std::endl;

    return 0;
}