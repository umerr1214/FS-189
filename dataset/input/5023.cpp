#include <iostream>
#include <cstring> // For strlen, though not used in the broken logic

// Function to count words, with robustness issues
// This version has two main robustness issues:
// 1. It crashes when given a nullptr input because it dereferences 'str' without checking.
// 2. It incorrectly returns 1 for an empty string ("") instead of 0.
int countWords(char* str) {
    // Robustness issue: Does not handle nullptr. Dereferencing str will crash.
    // The loop condition `str[i] != '\0'` will attempt to access memory at a null address.
    
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) { // Potential crash point if str is nullptr
        if (str[i] == ' ') {
            count++;
        }
    }

    // Robustness issue: This logic implicitly assumes there's at least one word
    // if the string is not empty. For an empty string "", 'count' will be 0,
    // and this will return 1, which is incorrect.
    return count + 1;
}

int main() {
    // Test cases
    char str1[] = "hello world";
    char str2[] = "programming";
    char str3[] = ""; // Empty string
    char str4[] = "one two three four";

    std::cout << "Test Case 1: \"" << str1 << "\" -> " << countWords(str1) << std::endl;
    std::cout << "Test Case 2: \"" << str2 << "\" -> " << countWords(str2) << std::endl;
    std::cout << "Test Case 3: \"" << str3 << "\" -> " << countWords(str3) << std::endl; // Expected: 0, Actual: 1 (Incorrect)
    std::cout << "Test Case 4: \"" << str4 << "\" -> " << countWords(str4) << std::endl;

    // Test Case for nullptr: This call is expected to cause a segmentation fault (crash).
    // For demonstration purposes in a running program, we explicitly state it.
    // In a real test harness, this would be run in isolation to capture the crash.
    std::cout << "Test Case 5: nullptr -> (Expected: crash, Actual: Program would crash if called)" << std::endl;
    // char* str5 = nullptr;
    // countWords(str5); // Uncommenting this line would cause a crash.

    return 0;
}