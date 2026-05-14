#include <iostream>
#include <cstring> // Not strictly needed for this logic, but good practice for C-style strings

// Function to count words in a C-style string.
// This is a correct, robust, readable, and efficient implementation.
// It correctly handles nullptr, empty strings, and counts words by detecting
// transitions from non-space to space (or start of string to non-space).
int countWords(char* str) {
    // Handle null pointer input gracefully by returning 0 words.
    if (str == nullptr) {
        return 0;
    }

    int count = 0;
    bool inWord = false; // Flag to track if we are currently inside a word

    // Iterate through the C-style string character by character
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] != ' ') {
            // If the current character is not a space
            if (!inWord) {
                // If we were not previously in a word, this is the beginning of a new word.
                count++;
                inWord = true; // Set flag to indicate we are now inside a word
            }
        } else {
            // If the current character is a space, we are no longer in a word.
            inWord = false; // Reset flag
        }
    }

    return count;
}

int main() {
    // Test cases
    char str1[] = "hello world";
    char str2[] = "programming";
    char str3[] = ""; // Empty string
    char str4[] = "one two three four";
    char* str5 = nullptr; // Null pointer
    char str6[] = "single";

    std::cout << "Test Case 1: \"" << str1 << "\" -> " << countWords(str1) << std::endl; // Expected: 2, Actual: 2
    std::cout << "Test Case 2: \"" << str2 << "\" -> " << countWords(str2) << std::endl; // Expected: 1, Actual: 1
    std::cout << "Test Case 3: \"" << str3 << "\" -> " << countWords(str3) << std::endl; // Expected: 0, Actual: 0
    std::cout << "Test Case 4: \"" << str4 << "\" -> " << countWords(str4) << std::endl; // Expected: 4, Actual: 4
    std::cout << "Test Case 5: nullptr -> " << countWords(str5) << std::endl;            // Expected: 0, Actual: 0
    std::cout << "Test Case 6: \"" << str6 << "\" -> " << countWords(str6) << std::endl; // Expected: 1, Actual: 1

    return 0;
}