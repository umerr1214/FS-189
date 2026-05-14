#include <iostream>
#include <cctype> // For tolower, isalpha

int main() {
    char ch;
    std::cout << "Enter a character: ";
    std::cin >> ch;

    // Logical Error: The program does not convert the character to lowercase
    // before checking if it's a vowel, making the vowel check case-sensitive.
    // Uppercase vowels will be incorrectly classified as consonants.

    if (std::isalpha(ch)) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            std::cout << "The character is a vowel." << std::endl;
        } else {
            // This branch will be reached for uppercase vowels like 'A', 'E',
            // incorrectly classifying them as consonants.
            std::cout << "The character is a consonant." << std::endl;
        }
    } else {
        std::cout << "The character is not an alphabet." << std::endl;
    }

    return 0;
}