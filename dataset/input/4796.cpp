#include <iostream>
#include <cctype> // For tolower (used inefficiently here)
#include <cstring> // For strlen

// Function to count vowels in a C-style string
// Readability/Efficiency Issue: Overly verbose and slightly inefficient vowel check.
int countVowels(const char* str) {
    int count = 0;
    if (str == nullptr) { // Basic robustness check, not the focus of this error type
        return 0;
    }
    for (int i = 0; str[i] != '\0'; ++i) {
        char currentChar = str[i];
        // Inefficient and verbose check: explicitly checks both upper and lower case
        // instead of converting to lowercase once per character.
        if (currentChar == 'a' || currentChar == 'A' ||
            currentChar == 'e' || currentChar == 'E' ||
            currentChar == 'i' || currentChar == 'I' ||
            currentChar == 'o' || currentChar == 'O' ||
            currentChar == 'u' || currentChar == 'U') {
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

    return 0;
}