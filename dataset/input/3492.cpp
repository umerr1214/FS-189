#include <iostream>
#include <cstring> // For strlen
#include <cctype>  // For tolower

int main() {
    const int BUFFER_SIZE = 10; // Semantic Error: Small buffer size
    char str[BUFFER_SIZE];

    std::cout << "Enter a C-style string: ";
    // Semantic Error: Using std::cin >> str for C-style arrays is unsafe.
    // It does not check buffer bounds and can lead to buffer overflow if input is longer than BUFFER_SIZE - 1.
    std::cin >> str; 

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