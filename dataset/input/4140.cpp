#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: " << std::endl;
    std::getline(std::cin, sentence);

    // Semantic Error: sizeof(sentence) returns the size of the std::string object itself
    // (e.g., 24 or 32 bytes on a 64-bit system), not the length of the string content
    // or the word count. This is a misunderstanding of the sizeof operator's behavior
    // with std::string objects when the intent is to analyze string content.
    int word_count = sizeof(sentence); 
    // This compiles and runs, but the result is semantically incorrect for the problem's goal.

    std::cout << "Total words: " << word_count << std::endl;

    return 0;
}