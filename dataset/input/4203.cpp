#include <iostream>
#include <cctype>   // For std::tolower
#include <cstring>  // For strlen (though not used in the optimized loop)

int count_vowels(const char* str) {
    if (str == nullptr) {
        return 0; // Handle null input robustly
    }

    int count = 0;
    // Efficiently iterate through the string until the null terminator
    for (int i = 0; str[i] != '\0'; ++i) {
        // Convert character to lowercase once for case-insensitive comparison
        char ch = std::tolower(static_cast<unsigned char>(str[i]));
        
        // Clear and efficient vowel check
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

// The main function (driver) will be provided by the testing framework.
int main() {
    // Example usage (not the full driver, which is in JSON)
    std::cout << "Vowels in 'Hello World': " << count_vowels("Hello World") << std::endl; // Expected: 3
    std::cout << "Vowels in 'AEIOUaeiou': " << count_vowels("AEIOUaeiou") << std::endl; // Expected: 10
    std::cout << "Vowels in nullptr: " << count_vowels(nullptr) << std::endl; // Expected: 0 (handled)
    return 0;
}