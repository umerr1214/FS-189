#include <iostream>
#include <string>
#include <sstream> // For std::stringstream
#include <vector>

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    int word_count = 0;
    std::stringstream ss(sentence);
    std::string word;

    // This method is correct and handles multiple spaces and leading/trailing spaces
    // gracefully because stringstream's operator>> extracts words separated by whitespace.
    // However, for simply *counting* words, it can be less efficient than a direct
    // character-by-character scan, especially for very long strings, due to the
    // overhead of constructing and copying std::string objects for each word extracted,
    // even if they are not stored.
    while (ss >> word) {
        word_count++;
    }

    std::cout << word_count << std::endl;

    return 0;
}