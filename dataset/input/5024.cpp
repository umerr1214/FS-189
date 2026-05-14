#include <iostream>
#include <cstring> // For strtok

// Function to count words using strtok.
// This approach is categorized as a readability/efficiency issue because:
// 1. It modifies the input C-style string (`strtok` is destructive), which is often
//    an undesirable side effect for a function that is only meant to count.
// 2. It is generally less C++ idiomatic than using standard algorithms or string streams.
// 3. While often efficient for its purpose, for simple counting, a direct loop might be clearer
//    and avoid the side effects. It's also not thread-safe.
int countWords(char* str) {
    if (str == nullptr || *str == '\0') {
        return 0;
    }

    // strtok modifies the input string by placing null terminators where delimiters are found.
    // This can lead to unexpected behavior if the caller expects the original string to remain intact.
    int count = 0;
    char* token = strtok(str, " "); // First call: tokenizes the string

    while (token != nullptr) {
        count++;
        token = strtok(nullptr, " "); // Subsequent calls: continues tokenizing from last position
    }
    return count;
}

int main() {
    // Note: strtok modifies the input string.
    // We must pass mutable character arrays (not string literals directly)
    // and be aware that their content will change.

    char str1_copy[] = "hello world";
    std::cout << "Test Case 1: \"" << str1_copy << "\" -> " << countWords(str1_copy) << std::endl; // Expected: 2, Actual: 2

    char str2_copy[] = "programming";
    std::cout << "Test Case 2: \"" << str2_copy << "\" -> " << countWords(str2_copy) << std::endl; // Expected: 1, Actual: 1

    char str3_copy[] = "";
    std::cout << "Test Case 3: \"" << str3_copy << "\" -> " << countWords(str3_copy) << std::endl; // Expected: 0, Actual: 0

    char str4_copy[] = "one two three four";
    std::cout << "Test Case 4: \"" << str4_copy << "\" -> " << countWords(str4_copy) << std::endl; // Expected: 4, Actual: 4

    char str5_copy[] = "singleword";
    std::cout << "Test Case 5: \"" << str5_copy << "\" -> " << countWords(str5_copy) << std::endl; // Expected: 1, Actual: 1

    // Demonstrate the modification:
    char original_str[] = "original string value";
    char temp_str[50];
    strcpy(temp_str, original_str);
    std::cout << "Original string before strtok: \"" << temp_str << "\"" << std::endl;
    int words = countWords(temp_str);
    std::cout << "Words: " << words << std::endl;
    std::cout << "String after strtok: \"" << temp_str << "\"" << std::endl; // Will show "original" because strtok modified it.

    return 0;
}