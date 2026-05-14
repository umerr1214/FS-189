#include <iostream>
#include <cctype> // For std::islower and std::toupper

// Correct, robust, readable, and efficient implementation
void strToUpper(char* str) {
    if (str == nullptr) {
        return; // Handle nullptr input robustly
    }
    char* ptr = str;
    while (*ptr != '\0') {
        // Use std::islower and std::toupper for correct and locale-aware conversion.
        // static_cast<unsigned char> is crucial for correct behavior with cctype functions.
        if (std::islower(static_cast<unsigned char>(*ptr))) {
            *ptr = static_cast<char>(std::toupper(static_cast<unsigned char>(*ptr)));
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