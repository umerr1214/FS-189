#include <iostream>
#include <cctype> // For tolower
#include <cstring> // For strlen

int count_vowels(const char* str) {
    if (str == nullptr) { // Basic robustness check, but the core issue is efficiency/readability
        return 0;
    }
    int vowelCount = 0;
    // Efficiency Issue: strlen(str) is called in every iteration of the loop,
    // making the complexity O(N^2) where N is the string length.
    for (int i = 0; i < strlen(str); ++i) {
        char currentChar = str[i];
        // Readability / minor efficiency: std::tolower is called on every character,
        // even if it's not an alphabet, and the conditional is verbose.
        char lowerChar = std::tolower(static_cast<unsigned char>(currentChar));

        // Readability Issue: Verbose conditional check for vowels
        if (lowerChar == 'a' || lowerChar == 'e' || lowerChar == 'i' ||
            lowerChar == 'o' || lowerChar == 'u') {
            vowelCount++;
        }
    }
    return vowelCount;
}

// The main function (driver) will be provided by the testing framework.
int main() {
    // Example usage (not the full driver, which is in JSON)
    std::cout << "Vowels in 'Programming is Fun': " << count_vowels("Programming is Fun") << std::endl; // Expected: 5
    std::cout << "Vowels in 'rhythm': " << count_vowels("rhythm") << std::endl; // Expected: 0
    return 0;
}