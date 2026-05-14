#include <iostream>
#include <cstring> // For strlen, strcpy, strcat
#include <cstdio>  // For printf

// Function with a robustness issue:
// It does not handle nullptr inputs for s1 or s2.
// Calling C-style string functions (strlen, strcpy, strcat) with nullptr
// will lead to a segmentation fault or other undefined behavior.
void concatenateStrings(const char* s1, const char* s2) {
    // CRITICAL ROBUSTNESS ISSUE: No nullptr checks for s1 or s2.
    // If s1 or s2 is nullptr, the following calls to strlen, strcpy, or strcat
    // will result in a program crash (segmentation fault).
    size_t len1 = strlen(s1); 
    size_t len2 = strlen(s2);

    // Allocate dynamic memory for the combined string.
    // This assumes the problem implies creating a new combined string.
    char* buffer = new char[len1 + len2 + 1];

    strcpy(buffer, s1);
    strcat(buffer, s2);

    printf("%s\n", buffer);

    delete[] buffer; // Clean up dynamically allocated memory
}

int main() {
    // Test cases for concatenateStrings
    std::cout << "--- Test Case 1: Valid Inputs ---" << std::endl;
    concatenateStrings("Hello", " World"); // Expected: Hello World

    std::cout << "--- Test Case 2: Empty String 1 ---" << std::endl;
    concatenateStrings("", "World"); // Expected: World

    std::cout << "--- Test Case 3: Empty String 2 ---" << std::endl;
    concatenateStrings("Hello", ""); // Expected: Hello

    std::cout << "--- Test Case 4: Both Empty ---" << std::endl;
    concatenateStrings("", ""); // Expected: (empty line)

    std::cout << "--- Test Case 5: Robustness Issue (s1 is nullptr) ---" << std::endl;
    // This call is expected to cause a segmentation fault.
    // The program will crash here due to dereferencing a nullptr in strlen.
    concatenateStrings(nullptr, "World"); 

    // The following test case will likely not be reached if the above crashes.
    // std::cout << "--- Test Case 6: Robustness Issue (s2 is nullptr) ---" << std::endl;
    // concatenateStrings("Hello", nullptr);

    return 0;
}