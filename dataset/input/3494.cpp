#include <iostream>
#include <cstring> // For strlen
#include <cctype>  // For tolower, though not used optimally here
#include <limits>  // For std::numeric_limits

// Function to count vowels (case-insensitive)
int countVowels(const char* str) {
    int count = 0;
    if (str == nullptr) {
        return 0;
    }
    // Readability/Efficiency Issue 1: strlen(str) is called in each iteration, re-calculating length.
    // This makes the loop O(N^2) instead of O(N) where N is string length.
    for (int i = 0; i < strlen(str); ++i) {
        char c = str[i];
        // Readability/Efficiency Issue 2: Very verbose vowel check without converting to a common case first.
        // It's more efficient and readable to convert 'c' to lowercase (or uppercase) once.
        if (c == 'a' || c == 'A' ||
            c == 'e' || c == 'E' ||
            c == 'i' || c == 'I' ||
            c == 'o' || c == 'O' ||
            c == 'u' || c == 'U') {
            count++;
        }
    }
    return count;
}

int main() {
    const int MAX_INPUT_SIZE = 256; // A reasonable buffer size for robustness
    char inputString[MAX_INPUT_SIZE]; // C-style string buffer

    std::cout << "Enter a C-style string: ";
    // Using std::cin.getline for robust input handling (not the issue here)
    std::cin.getline(inputString, MAX_INPUT_SIZE);

    if (std::cin.fail() && !std::cin.eof()) {
        std::cerr << "Warning: Input might have been truncated.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int vowelCount = countVowels(inputString);
    std::cout << "Total number of vowels: " << vowelCount << std::endl;

    return 0;
}