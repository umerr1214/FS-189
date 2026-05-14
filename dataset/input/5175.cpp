#include <iostream>
#include <cstddef> // For std::ptrdiff_t, though int is sufficient for typical lengths

// Correct, efficient, and robust version
int customStrlen(const char* str) {
    if (str == nullptr) {
        // Robustly handle nullptr input by returning 0, consistent with an empty string.
        return 0;
    }

    const char* end_ptr = str;
    // Iterate through the string using a pointer until the null terminator is found.
    while (*end_ptr != '\0') {
        end_ptr++;
    }
    // The length is the difference between the end pointer and the start pointer.
    return static_cast<int>(end_ptr - str);
}

int main() {
    // Test cases
    const char* s1 = "hello";
    const char* s2 = "";
    const char* s3 = "a";
    const char* s4 = "long string with spaces";
    const char* s5 = nullptr; // Robustly handled

    std::cout << "Testing with \"hello\": " << customStrlen(s1) << std::endl; // Expected: 5
    std::cout << "Testing with \"\": " << customStrlen(s2) << std::endl;     // Expected: 0
    std::cout << "Testing with \"a\": " << customStrlen(s3) << std::endl;      // Expected: 1
    std::cout << "Testing with \"long string with spaces\": " << customStrlen(s4) << std::endl; // Expected: 23
    std::cout << "Testing with nullptr: " << customStrlen(s5) << std::endl; // Expected: 0

    return 0;
}