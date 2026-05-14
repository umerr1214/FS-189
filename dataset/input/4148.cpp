#include <iostream>
// No cctype for manual conversion, demonstrating readability/efficiency issue
// For completeness and basic safety, a null check is included.

// Function with readability/efficiency issue: uses manual character conversion
void strToUpper(char* str) {
    if (str == nullptr) {
        return; // Basic null check for safety, not the core issue here
    }
    char* ptr = str;
    while (*ptr != '\0') {
        // Manual check and conversion without cctype functions, less readable and less robust
        // for different character sets/locales. This assumes ASCII.
        if (*ptr >= 'a' && *ptr <= 'z') {
            *ptr = static_cast<char>(*ptr - ('a' - 'A')); // Convert to uppercase using ASCII offset
        }
        ptr++;
    }
}

int main() {
    char myString1[] = "Hello World!";
    std::cout << "Original: \"" << myString1 << "\"" << std::endl;
    strToUpper(myString1);
    std::cout << "Uppercase: \"" << myString1 << "\"" << std::endl;

    char myString2[] = "this is a test with numbers 123.";
    std::cout << "Original: \"" << myString2 << "\"" << std::endl;
    strToUpper(myString2);
    std::cout << "Uppercase: \"" << myString2 << "\"" << std::endl;

    char myString3[] = "ALREADY UPPERCASE!";
    std::cout << "Original: \"" << myString3 << "\"" << std::endl;
    strToUpper(myString3);
    std::cout << "Uppercase: \"" << myString3 << "\"" << std::endl;

    char myString4[] = "";
    std::cout << "Original: \"" << myString4 << "\"" << std::endl;
    strToUpper(myString4);
    std::cout << "Uppercase: \"" << myString4 << "\"" << std::endl;

    char* nullStr = nullptr;
    strToUpper(nullStr); // Should handle nullptr gracefully
    std::cout << "Processed nullptr (no crash expected)." << std::endl;

    return 0;
}