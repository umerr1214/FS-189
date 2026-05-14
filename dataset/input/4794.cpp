#include <iostream>
#include <cctype>
#include <cstring> // For strlen

// Function to count vowels
int countVowels(const char* str) {
    int count = 0;
    // Semantic Error: Using sizeof(str) which returns the size of the pointer (e.g., 8 bytes on a 64-bit system),
    // instead of strlen(str) which returns the length of the string.
    // This will cause the loop to iterate a fixed small number of times,
    // likely missing most of the string, or going out of bounds if the string is shorter than sizeof(str).
    for (int i = 0; i < sizeof(str); ++i) { // Incorrect loop condition
        if (str[i] == '\0') { // Check for null terminator to prevent immediate crash if string is shorter
            break;
        }
        char lowerChar = std::tolower(static_cast<unsigned char>(str[i]));
        if (lowerChar == 'a' || lowerChar == 'e' || lowerChar == 'i' ||
            lowerChar == 'o' || lowerChar == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    char inputString[100];
    std::cout << "Enter a string: ";
    std::cin.getline(inputString, 100);

    int vowelCount = countVowels(inputString);
    std::cout << "Number of vowels: " << vowelCount << std::endl;

    return 0;
}