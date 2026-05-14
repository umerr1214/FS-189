#include <iostream>
#include <cctype> // Required for isupper, though not strictly used in switch logic

int main() {
    char ch;

    std::cout << "Enter a character: ";
    // Robustness Issue: Does not check for cin.fail() or clear input buffer if multiple characters are entered.
    // If the input stream fails (e.g., unexpected EOF), 'ch' might be uninitialized, leading to undefined behavior.
    // If user enters "AB", 'A' is read, 'B' remains in buffer, which could cause issues in a larger program.
    std::cin >> ch;

    std::cout << ch; // Print the character first

    switch (ch) {
        case 'A':
            std::cout << " is an uppercase vowel." << std::endl;
            break;
        case 'E':
            std::cout << " is an uppercase vowel." << std::endl;
            break;
        case 'I':
            std::cout << " is an uppercase vowel." << std::endl;
            break;
        case 'O':
            std::cout << " is an uppercase vowel." << std::endl;
            break;
        case 'U':
            std::cout << " is an uppercase vowel." << std::endl;
            break;
        default:
            std::cout << " is not an uppercase vowel." << std::endl;
            break;
    }

    return 0;
}