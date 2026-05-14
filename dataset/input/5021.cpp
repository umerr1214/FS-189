#include <iostream>
#include <cstring> // Required for strlen, though not used in this specific implementation

// Function to count words in a C-style string with a logical error
int countWords(char* str) {
    // Handle empty or null strings
    if (str == nullptr || *str == '\0') {
        return 0;
    }

    // Logical error: This logic counts spaces, not words.
    // For N words, there are N-1 spaces.
    // If there's 1 word ("hello"), there are 0 spaces, but it should return 1.
    // If there are 2 words ("hello world"), there's 1 space, but it should return 2.
    int spaceCount = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ') {
            spaceCount++;
        }
    }
    return spaceCount; // Should be spaceCount + 1 for non-empty strings
}

int main() {
    // This main function is for compilation purposes.
    // The actual test driver will be provided in the JSON.
    char s1[] = "hello world";
    char s2[] = "test";
    char s3[] = "";
    char* s4 = nullptr;

    std::cout << "Words in \"" << s1 << "\": " << countWords(s1) << std::endl; // Expected 2, Got 1
    std::cout << "Words in \"" << s2 << "\": " << countWords(s2) << std::endl; // Expected 1, Got 0
    std::cout << "Words in \"" << s3 << "\": " << countWords(s3) << std::endl; // Expected 0, Got 0
    // Calling with nullptr would lead to a crash if not handled, but the question implies valid strings.
    // std::cout << "Words in nullptr: " << countWords(s4) << std::endl;

    return 0;
}