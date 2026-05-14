#include <cstring> // Required for strlen in some implementations, and for driver.

// Function to concatenate two C-style strings.
// Robustness Issue: Fails to null-terminate the destination string if the source string is not empty.
// This can lead to undefined behavior when the string is later read or processed.
void strConcatenate(char* dest, const char* src) {
    size_t dest_len = 0;
    while (dest[dest_len] != '\0') {
        dest_len++;
    }

    size_t src_idx = 0;
    while (src[src_idx] != '\0') {
        dest[dest_len + src_idx] = src[src_idx];
        src_idx++;
    }
    // BUG: Missing explicit null-termination at dest[dest_len + src_idx] = '\0';
    // If src is empty (src_idx remains 0), the original dest string remains
    // correctly null-terminated by its existing '\0'.
    // However, if src is not empty, the loop copies all characters but does not
    // place a new null terminator at the end of the combined string.
    // This leaves 'dest' unterminated, which is a significant robustness issue.
}

// Driver code for testing
#include <iostream>

int main() {
    struct TestCase {
        char initial_dest[256];
        const char* src;
        const char* expected;
    };

    TestCase test_cases[] = {
        {"Hello ", "World!", "Hello World!"},
        {"", "Test", "Test"},
        {"Base", "", "Base"}, // This case will pass due to the nature of the bug
        {"A", "B", "AB"},
        {"", "", ""}, // This case will pass due to the nature of the bug
        {"Very long initial string that needs to be concatenated ", "with another long string to test buffer capacity assumptions.", "Very long initial string that needs to be concatenated with another long string to test buffer capacity assumptions."},
        {"Short", "LongerString", "ShortLongerString"}
    };

    int num_passed = 0;
    for (int i = 0; i < sizeof(test_cases) / sizeof(TestCase); ++i) {
        char dest_buffer[256];
        strcpy(dest_buffer, test_cases[i].initial_dest);

        strConcatenate(dest_buffer, test_cases[i].src);

        // For robustness issue, strcmp might fail due to unterminated string,
        // or it might pass if the memory immediately after happens to be '\0'.
        // However, the intent is that it's an issue.
        if (strcmp(dest_buffer, test_cases[i].expected) == 0) {
            std::cout << "Test " << (i + 1) << " Passed." << std::endl;
        } else {
            std::cout << "Test " << (i + 1) << " Failed." << std::endl;
            std::cout << "  Input dest: \"" << test_cases[i].initial_dest << "\", src: \"" << test_cases[i].src << "\"" << std::endl;
            std::cout << "  Expected: \"" << test_cases[i].expected << "\", Got: \"" << dest_buffer << "\"" << std::endl;
        }
    }

    std::cout << "\n" << num_passed << "/" << (sizeof(test_cases) / sizeof(TestCase)) << " tests passed." << std::endl;

    return 0;
}