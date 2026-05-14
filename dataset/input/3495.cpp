#include <iostream>
#include <cstring> // For strlen (not directly used, but good to include for C-style strings)
#include <cctype>  // For std::tolower
#include <limits>  // For std::numeric_limits

// Function to count vowels (case-insensitive)
int countVowels(const char* str) {
    int count = 0;
    if (str == nullptr) {
        return 0;
    }
    // Iterate through the string until the null terminator
    for (int i = 0; str[i] != '\0'; ++i) {
        // Convert character to lowercase for case-insensitive comparison
        // static_cast<unsigned char> is used for safe conversion to prevent issues with negative char values
        char c = std::tolower(static_cast<unsigned char>(str[i]));
        // Check if the character is one of the vowels
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    const int MAX_INPUT_SIZE = 256; // A sufficiently large and reasonable buffer for typical inputs
    char inputString[MAX_INPUT_SIZE]; // C-style string buffer

    std::cout << "Enter a C-style string: ";
    // Read input safely using std::cin.getline.
    // It reads up to MAX_INPUT_SIZE-1 characters or until a newline.
    // This prevents buffer overflows.
    std::cin.getline(inputString, MAX_INPUT_SIZE);

    // Check if the input operation failed (e.g., input was too long and truncated)
    if (std::cin.fail() && !std::cin.eof()) {
        std::cerr << "Warning: Input was too long and might have been truncated." << std::endl;
        std::cin.clear(); // Clear the error flag
        // Discard the rest of the line to prevent issues with subsequent reads
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int vowelCount = countVowels(inputString);
    std::cout << "Total number of vowels: " << vowelCount << std::endl;

    return 0;
}