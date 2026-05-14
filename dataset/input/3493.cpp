#include <iostream>
#include <cstring> // For strlen (though not used in robust way here)
#include <cctype>  // For tolower
#include <cstdio>  // For scanf
#include <limits>  // For std::numeric_limits

// Function to count vowels (case-insensitive)
int countVowels(const char* str) {
    int count = 0;
    if (str == nullptr) {
        return 0;
    }
    for (int i = 0; str[i] != '\0'; ++i) {
        char c = std::tolower(static_cast<unsigned char>(str[i])); // Convert to lowercase
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    const int MAX_LEN = 20; // A small buffer size, making it vulnerable
    char inputString[MAX_LEN]; // C-style string buffer

    std::cout << "Enter a C-style string: ";
    // Robustness Issue: Using scanf without specifying maximum width.
    // This is a classic buffer overflow vulnerability.
    // If the user enters more than MAX_LEN-1 characters, it will write past the end of the buffer,
    // leading to undefined behavior, crashes, or security vulnerabilities.
    // Also, scanf("%s", ...) stops reading at the first whitespace character.
    if (scanf("%s", inputString) == 1) { // scanf returns number of items successfully read
        int vowelCount = countVowels(inputString);
        std::cout << "Total number of vowels: " << vowelCount << std::endl;
    } else {
        std::cerr << "Error reading input.\n";
    }

    // Clear any remaining input in the buffer if scanf didn't read the whole line
    // This is not directly related to the buffer overflow vulnerability of scanf("%s")
    // but is good practice if further input is expected.
    // For this single input program, it's less critical for program flow but might prevent
    // issues in a test harness that provides multiple lines of input.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return 0;
}