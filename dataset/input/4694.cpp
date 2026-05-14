#include <cstring> // Required for strlen for both function and driver.

// Function to concatenate two C-style strings.
// Readability / Efficiency Issue: Inefficiently calls strlen(dest) in a loop.
// This recalculates the length of 'dest' from the beginning in each iteration.
void strConcatenate(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        // Efficiency issue: strlen(dest) is called in every iteration of the loop.
        // As characters are appended to 'dest', strlen(dest) has to scan a longer string each time.
        // If dest has length D and src has length S, this loop performs approximately S * O(D+S) operations,
        // instead of the optimal O(D+S).
        dest[strlen(dest)] = src[i];
        i++;
    }
    // This final strlen(dest) call is also inefficient, but less impactful than inside the loop.
    dest[strlen(dest)] = '\0'; // Ensures null termination
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