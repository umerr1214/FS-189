#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::cout << "Enter a sentence: ";
    std::string sentence;
    std::getline(std::cin, sentence);

    std::stringstream ss; // Semantic Error: The stringstream is created but never initialized with the 'sentence' data.
    std::string word;
    int word_count = 0;

    // This loop will never extract any words because 'ss' is empty.
    while (ss >> word) {
        word_count++;
    }

    std::cout << "Total number of words: " << word_count << std::endl;

    return 0;
}