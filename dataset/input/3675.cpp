#include <iostream>
#include <string>
#include <vector> // Not strictly needed, but common to include

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    int word_count = 0;
    bool in_word = false;

    // Iterate through each character of the sentence
    for (char c : sentence) {
        if (c == ' ') {
            // If we encounter a space, we are no longer in a word
            in_word = false;
        } else {
            // If we encounter a non-space character
            if (!in_word) {
                // And we were previously not in a word, it means a new word has started
                word_count++;
                in_word = true;
            }
            // If we were already in a word, just continue being in a word
        }
    }

    std::cout << word_count << std::endl;

    return 0;
}