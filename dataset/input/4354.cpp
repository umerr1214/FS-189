#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: " // Missing semicolon here
    std::getline(std::cin, sentence);

    // Count characters (including spaces)
    // The length() method of std::string already counts all characters.
    std::cout << "Total characters: " << sentence.length() << std::endl;

    return 0;
}