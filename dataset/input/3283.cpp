#include <iostream>
#include <cctype> // For isupper, islower, isdigit
#include <string>

// Helper function to encapsulate the classification logic for testing
std::string classify_char_category(char c) {
    // This helper assumes 'c' is a valid character.
    // The robustness issue for this sample lies in the main function's input handling.
    if (std::isupper(static_cast<unsigned char>(c))) {
        return "Category: Uppercase Letter";
    } else if (std::islower(static_cast<unsigned char>(c))) {
        return "Category: Lowercase Letter";
    } else if (std::isdigit(static_cast<unsigned char>(c))) {
        return "Category: Digit";
    } else {
        return "Category: Special Character";
    }
}

int main() {
    char c;
    std::cout << "Enter a character: ";
    // Robustness issue: No check for input failure.
    // If std::cin fails (e.g., EOF, or unexpected input that causes stream failure),
    // 'c' might not be properly initialized or the stream state is bad.
    // The program will proceed without acknowledging the input failure, potentially
    // leading to undefined behavior or incorrect classification based on garbage data.
    std::cin >> c;

    std::cout << classify_char_category(c) << std::endl;

    return 0;
}