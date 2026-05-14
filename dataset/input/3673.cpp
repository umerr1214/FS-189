#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    int word_count = 0;
    if (!sentence.empty()) {
        // This simple approach counts spaces and adds 1.
        // It fails for empty strings, leading/trailing spaces, and multiple spaces.
        // For example, " hello world " would count 3 words (2 spaces + 1).
        // "hello   world" would count 3 words (2 spaces + 1).
        // "" (empty string) would count 1 word.
        for (char c : sentence) {
            if (c == ' ') {
                word_count++;
            }
        }
        word_count++; // Add 1 for the last word (or the only word if no spaces)
    }
    // If sentence is empty, word_count remains 0, which is incorrect for this logic.
    // The previous if condition handles the empty string case but not robustly for other scenarios.

    std::cout << word_count << std::endl;

    return 0;
}