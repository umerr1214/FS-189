#include <iostream>
#include <cctype> // For tolower, isalpha

int main() {
    char ch;
    std::cout << "Enter a character: ";
    std::cin >> ch;

    ch = std::tolower(ch); // Convert to lowercase for case-insensitivity

    if (std::isalpha(ch)) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            std::cout << "The character is a vowel." << std::endl
        } else {
            std::cout << "The character is a consonant." << std::endl;
        }
    } else {
        std::cout << "The character is not an alphabet." << std::endl;
    }

    return 0;
}