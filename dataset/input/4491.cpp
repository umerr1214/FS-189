#include <iostream>
#include <cctype> // For tolower and isalpha

int main() {
    char ch;
    std::cout << "Enter a character: ";
    std::cin >> ch;

    if (std::isalpha(ch)) { // First, check if it's an alphabetic character
        char lowerCh = std::tolower(ch); // Convert to lowercase for case-insensitive check

        if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
            std::cout << "'" << ch << "' is a vowel." << std::endl;
        } else {
            std::cout << "'" << ch << "' is a consonant." << std::endl;
        }
    } else {
        // Handle non-alphabetic input gracefully
        std::cout << "'" << ch << "' is not an alphabetic character." << std::endl;
    }

    return 0;
}