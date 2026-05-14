#include <iostream>
#include <cctype> // Not strictly needed for this switch, but good practice for char operations

int main() {
    char ch;

    std::cout << "Enter a character: ";
    std::cin >> ch;

    std::cout << ch; // Print the character first

    // Correct Version: Uses fall-through cases for readability and efficiency.
    switch (ch) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            std::cout << " is an uppercase vowel." << std::endl;
            break;
        default:
            std::cout << " is not an uppercase vowel." << std::endl;
            break;
    }

    return 0;
}