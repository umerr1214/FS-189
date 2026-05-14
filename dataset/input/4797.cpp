#include <iostream>
#include <cctype> // For std::tolower
#include <cstring> // For strlen (not strictly needed, but common for C-strings)

// Function to count vowels in a C-style string
// Correct Version: Robust, readable, and efficient.
int countVowels(const char* str) {
    if (str == nullptr) { // Robustness: Handle nullptr input gracefully
        return 0;
    }

    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        // Efficiency & Readability: Convert character to lowercase once
        // and then check against lowercase vowels.
        char c = std::tolower(static_cast<unsigned char>(str[i]));
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    char inputString1[] = "Hello World!";
    std::cout << "Input: \"" << inputString1 << "\"" << std::endl;
    std::cout << "Number of vowels: " << countVowels(inputString1) << std::endl;
    std::cout << "---" << std::endl;

    char inputString2[] = "Programming is FUN";
    std::cout << "Input: \"" << inputString2 << "\"" << std::endl;
    std::cout << "Number of vowels: " << countVowels(inputString2) << std::endl;
    std::cout << "---" << std::endl;

    char inputString3[] = "AEIOUaeiou";
    std::cout << "Input: \"" << inputString3 << "\"" << std::endl;
    std::cout << "Number of vowels: " << countVowels(inputString3) << std::endl;
    std::cout << "---" << std::endl;

    char inputString4[] = "Rhythm";
    std::cout << "Input: \"" << inputString4 << "\"" << std::endl;
    std::cout << "Number of vowels: " << countVowels(inputString4) << std::endl;
    std::cout << "---" << std::endl;

    char inputString5[] = ""; // Empty string
    std::cout << "Input: \"" << inputString5 << "\"" << std::endl;
    std::cout << "Number of vowels: " << countVowels(inputString5) << std::endl;
    std::cout << "---" << std::endl;

    // Test with nullptr for robustness (should return 0)
    const char* nullPtrString = nullptr;
    std::cout << "Input: (nullptr)" << std::endl;
    std::cout << "Number of vowels: " << countVowels(nullPtrString) << std::endl;
    std::cout << "---" << std::endl;

    return 0;
}