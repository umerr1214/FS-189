#include <iostream>
#include <cstring> // For strcmp and strlen
#include <vector>  // Not strictly needed for this problem, but often included

// Function with a syntax error: missing semicolon in while loop condition
void myStrcpy(char* dest, const char* src) {
    while (*src != '\0') // ERROR: Missing semicolon here
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int main() {
    struct TestCase {
        const char* src;
        int dest_size;
        const char* expected;
    };

    TestCase test_cases[] = {
        {"hello world", 20, "hello world"},
        {"", 5, ""},
        {"short", 10, "short"},
        {"a very long string that should fit", 50, "a very long string that should fit"}
    };

    int passed_count = 0;
    int total_count = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < total_count; ++i) {
        char* dest_buffer = new char[test_cases[i].dest_size];
        // Initialize dest_buffer to ensure it's clean for comparison
        memset(dest_buffer, 0, test_cases[i].dest_size);

        // Call the function under test
        myStrcpy(dest_buffer, test_cases[i].src);

        if (strcmp(dest_buffer, test_cases[i].expected) == 0) {
            std::cout << "Test " << i + 1 << " Passed.\n";
            passed_count++;
        } else {
            std::cout << "Test " << i + 1 << " Failed.\n";
            std::cout << "  Input src: \"" << test_cases[i].src << "\"\n";
            std::cout << "  Expected: \"" << test_cases[i].expected << "\"\n";
            std::cout << "  Got:      \"" << dest_buffer << "\"\n";
        }
        delete[] dest_buffer;
    }

    std::cout << "\n" << passed_count << "/" << total_count << " tests passed.\n";

    if (passed_count == total_count) {
        return 0; // All tests passed
    } else {
        return 1; // Some tests failed
    }
}