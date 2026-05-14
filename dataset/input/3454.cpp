#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse

int main() {
    std::string word;
    std::cout << "Enter a word: ";
    std::cin >> word // Syntax Error: Missing semicolon here
    std::reverse(word.begin(), word.end());
    std::cout << "Reversed word: " << word << std::endl;
    return 0;
}