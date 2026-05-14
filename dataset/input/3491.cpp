#include <iostream>
#include <cstring> // For strlen
#include <cctype>  // For tolower, toupper

int main() {
    const int MAX_LENGTH = 100;
    char str[MAX_LENGTH];

    std::cout << "Enter a C-style string: ";
    std::cin.getline(str, MAX_LENGTH);

    int vowelCount = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        // Logical Error: Only checks for lowercase vowels, making it case-sensitive.
        // It should convert the character to lowercase first.
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            vowelCount++;
        }
    }

    std::cout << "Total number of vowels: " << vowelCount << std::endl;

    return 0;
}