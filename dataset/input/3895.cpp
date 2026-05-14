#include <iostream>

int main() {
    char ch = '\0'; // Initialize to null character for predictable behavior on input failure
    std::cout << "Enter a character: ";
    std::cin >> ch; // No check for cin.fail() or for multiple characters entered

    // Manually check if it's an alphabet (less robust than std::isalpha for diverse character sets)
    bool is_alpha = false;
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        is_alpha = true;
    }

    // Print character. If ch is '\0' (e.g., from failed input), it might print nothing visible or a space.
    // The program proceeds to classify even if input failed.
    std::cout << ch << " ";

    if (is_alpha) {
        char lower_ch = ch;
        if (ch >= 'A' && ch <= 'Z') {
            lower_ch = ch + ('a' - 'A'); // Manual tolower conversion
        }

        if (lower_ch == 'a' || lower_ch == 'e' || lower_ch == 'i' || lower_ch == 'o' || lower_ch == 'u') {
            std::cout << "is a vowel." << std::endl;
        } else {
            std::cout << "is a consonant." << std::endl;
        }
    } else {
        // This message is printed even if std::cin failed to read anything (e.g., EOF),
        // which is misleading as it's an input error, not just a non-alphabet character.
        std::cout << "is not an alphabet." << std::endl;
    }

    return 0;
}