#include <iostream>
#include <cctype> // For toupper or isupper
#include <cstring> // For strlen

// Function to count vowels
int countVowels(const char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        // Logical Error: Only checks for uppercase vowels directly,
        // failing to convert to a common case (e.g., lowercase) first.
        // Thus, "hello" will have 0 vowels, but "HELLO" will have 2.
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' ||
            str[i] == 'O' || str[i] == 'U') {
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