#include <iostream>
#include <string>
#include <vector> // Included for completeness, not strictly used by countWords logic here

// Function to count words, exhibiting a readability/efficiency issue.
// It correctly handles various space conditions (multiple, leading, trailing)
// but does so inefficiently by repeatedly modifying the string using erase.
int countWords(const std::string& sentence) {
    std::string temp_sentence = sentence;
    int wordCount = 0;

    while (true) {
        // Find the first non-space character (start of a word)
        size_t first_non_space = temp_sentence.find_first_not_of(' ');
        
        if (first_non_space == std::string::npos) {
            // No more non-space characters, so no more words
            break;
        }

        // A word is found
        wordCount++;

        // Find the first space character after the current word
        size_t first_space_after_word = temp_sentence.find(' ', first_non_space);

        if (first_space_after_word == std::string::npos) {
            // No more spaces after the current word, means it's the last word
            break;
        }

        // Erase the word and the space(s) that followed it
        // This is inefficient as it involves creating new string copies repeatedly
        temp_sentence.erase(0, first_space_after_word + 1);
    }
    return wordCount;
}

int main() {
    std::string sentence;
    std::getline(std::cin, sentence);
    std::cout << countWords(sentence) << std::endl;
    return 0;
}