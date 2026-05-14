#include <iostream>
#include <cctype> // For tolower
#include <cstring> // For strlen

// Function to count vowels
int countVowels(const char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
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
    std::cout << "Number of vowels: " << vowelCount std::endl; // Syntax Error: missing '<<' operator

    return 0;
}