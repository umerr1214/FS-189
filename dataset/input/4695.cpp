#include <cstring> // Required for strlen in some implementations, and for driver.

// Function to concatenate two C-style strings.
// Correct Version: This implementation is correct, readable, and efficient.
void strConcatenate(char* dest, const char* src) {
    // Find the current length of the destination string efficiently (O(N))
    size_t dest_len = 0;
    while (dest[dest_len] != '\0') {
        dest_len++;
    }

    // Append the source string to the destination starting from dest_len (O(M))
    size_t i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }

    // Null-terminate the concatenated string (critical for C-strings)
    dest[dest_len + i] = '\0';
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
        {"Base", "", "Base"},
        {"A", "B", "AB"},
        {"", "", ""},
        {"Very long initial string that needs to be concatenated ", "with another long string to test buffer capacity assumptions.", "Very long initial string that needs to be concatenated with another long string to test buffer capacity assumptions."},
        {"Short", "LongerString", "ShortLongerString"}
    };

    int num_passed = 0;
    for (int i = 0; i < sizeof(test_cases) / sizeof(TestCase); ++i) {
        char dest_buffer[256];
        strcpy(dest_buffer, test_cases[i].initial_dest);

        strConcatenate(dest_buffer, test_cases[i].src);

        if (strcmp(dest_buffer, test_cases[i].expected) == 0) {
            std::cout << "Test " << (i + 1) << " Passed." << std::endl;
            num_passed++;
        } else {
            std::cout << "Test " << (i + 1) << " Failed." << std::endl;
            std::cout << "  Input dest: \"" << test_cases[i].initial_dest << "\", src: \"" << test_cases[i].src << "\"" << std::endl;
            std::cout << "  Expected: \"" << test_cases[i].expected << "\", Got: \"" << dest_buffer << "\"" << std::endl;
        }
    }

    std::cout << "\n" << num_passed << "/" << (sizeof(test_cases) / sizeof(TestCase)) << " tests passed." << std::endl;

    return 0;
}