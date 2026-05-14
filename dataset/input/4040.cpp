#include <iostream>
#include <cctype> // Required for isupper, though not strictly used in switch logic

int main() {
    char ch;

    std::cout << "Enter a character: ";
    std::cin >> ch;

    std::cout << ch; // Print the character first

    // Readability / Efficiency Issue: Each vowel has its own 'case' block with a redundant print statement.
    // This is less concise and less efficient than using fall-through 'case' labels.
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