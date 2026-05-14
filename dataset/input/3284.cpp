#include <iostream>
#include <string>

// Helper function to encapsulate the classification logic for testing
std::string classify_char_category(char c) {
    // Readability/Efficiency Issue: verbose and less idiomatic character checks
    // using explicit ASCII range comparisons instead of standard library functions
    // like std::isupper, std::islower, std::isdigit.
    // This approach is harder to read, less maintainable, and less robust across
    // different character sets or locales (e.g., non-ASCII characters).
    if (c >= 'A' && c <= 'Z') {
        return "Category: Uppercase Letter";
    } else if (c >= 'a' && c <= 'z') {
        return "Category: Lowercase Letter";
    } else if (c >= '0' && c <= '9') {
        return "Category: Digit";
    } else {
        return "Category: Special Character";
    }
}

int main() {
    char c;
    std::cout << "Enter a character: ";
    std::cin >> c;

    std::cout << classify_char_category(c) << std::endl;

    return 0;
}