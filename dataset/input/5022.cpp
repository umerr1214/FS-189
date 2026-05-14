#include <iostream>
#include <cstring> // Required for strlen

// Function to count words in a C-style string with a semantic error
int countWords(char* str) {
    // Semantic error: Calling strlen(str) without checking if str is nullptr.
    // If str is a null pointer, calling strlen on it results in undefined behavior.
    // While the problem implies valid C-style strings, a char* can technically be nullptr,
    // and a robust function should handle this, or at least not cause UB.
    if (strlen(str) == 0) { // This line causes Undefined Behavior if 'str' is nullptr
        return 0;
    }

    int wordCount = 1; // Start with 1 word if the string is not empty (after strlen check)
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ') {
            wordCount++;
        }
    }
    return wordCount;
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
    // This call will trigger the semantic error (Undefined Behavior)
    std::cout << "Words in nullptr: " << countWords(s4) << std::endl;

    return 0;
}