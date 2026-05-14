#include <iostream>
#include <cctype> // For tolower

int main() {
    char ch;
    std::cout << "Enter a character: ";
    std::cin >> ch;

    char lowerCh = std::tolower(ch);

    if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
        std::cout << "'" << ch << "' is a vowel." << std::endl;
    } else {
        // This version incorrectly classifies non-alphabetic characters as consonants.
        // It lacks a check to ensure the input is actually an alphabet.
        std::cout << "'" << ch << "' is a consonant." << std::endl;
    }

    return 0;
}