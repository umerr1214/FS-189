#include <iostream>
#include <cstring> // For strlen
#include <cctype>  // For tolower

int main() {
    const int MAX_LENGTH = 100;
    char str[MAX_LENGTH];

    std::cout << "Enter a C-style string: " // Missing semicolon here
    std::cin.getline(str, MAX_LENGTH);

    int vowelCount = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        char lowerChar = std::tolower(str[i]);
        if (lowerChar == 'a' || lowerChar == 'e' || lowerChar == 'i' || lowerChar == 'o' || lowerChar == 'u') {
            vowelCount++;
        }
    }

    std::cout << "Total number of vowels: " << vowelCount << std::endl;

    return 0;
}