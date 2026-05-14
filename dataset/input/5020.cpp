#include <iostream>
#include <cstring> // Required for strlen, though not used in this specific implementation

// Function to count words in a C-style string with a syntax error
int countWords(char* str) {
    // Handle empty or null strings
    if (str == nullptr || *str == '\0') {
        return 0;
    }

    int wordCount = 1; // Start with 1 word if the string is not empty
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ') {
            wordCount++;
        }
    }
    return wordCount // Missing semicolon here
}

int main() {
    // This main function is for compilation purposes.
    // The actual test driver will be provided in the JSON.
    char s1[] = "hello world";
    char s2[] = "test";
    char s3[] = "";
    char* s4 = nullptr;

    std::cout << "Words in \"" << s1 << "\": " << countWords(s1) << std::endl;
    std::cout << "Words in \"" << s2 << "\": " << countWords(s2) << std::endl;
    std::cout << "Words in \"" << s3 << "\": " << countWords(s3) << std::endl;
    // This line would cause a crash if the function were called with nullptr without a check.
    // The syntax error prevents compilation anyway.
    // std::cout << "Words in nullptr: " << countWords(s4) << std::endl;

    return 0;
}