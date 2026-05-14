#include <iostream>
#include <cstring> // For strcmp and strlen
#include <vector>  // Not strictly needed for this problem, but often included

// Function with a logical error: copies content but fails to null-terminate the destination
void myStrcpy(char* dest, const char* src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    // Logical error: Missing '*dest = '\\0';'
    // The destination string will not be properly null-terminated, leading to undefined behavior
    // when read by functions like strcmp or cout.
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
        // DO NOT memset to 0 here for this logical error,
        // otherwise the `strcmp` might find a null byte from the initialization
        // and hide the error of `myStrcpy` not null-terminating.
        // For the empty string case, dest_buffer[0] might be garbage, causing strcmp("", "") to fail.
        // This is the correct behavior for detecting the missing null terminator.

        myStrcpy(dest_buffer, test_cases[i].src);

        // Check if the string is null-terminated at the correct position and content matches
        size_t expected_len = strlen(test_cases[i].expected);
        bool is_null_terminated_correctly = (expected_len < test_cases[i].dest_size) && (dest_buffer[expected_len] == '\0');
        bool content_matches = (strcmp(dest_buffer, test_cases[i].expected) == 0);

        if (content_matches && is_null_terminated_correctly) {
            std::cout << "Test " << i + 1 << " Passed.\n";
            passed_count++;
        } else {
            std::cout << "Test " << i + 1 << " Failed.\n";
            std::cout << "  Input src: \"" << test_cases[i].src << "\"\n";
            std::cout << "  Expected: \"" << test_cases[i].expected << "\"\n";
            std::cout << "  Got:      \"" << dest_buffer << "\"\n";
            if (!content_matches) {
                std::cout << "  Error: Content mismatch.\n";
            }
            if (!is_null_terminated_correctly) {
                std::cout << "  Error: Destination not null-terminated correctly at expected position.\n";
            }
        }
        delete[] dest_buffer;
    }

    std::cout << "\n" << passed_count << "/" << total_count << " tests passed.\n";

    if (passed_count == total_count) {
        return 0;
    } else {
        return 1;
    }
}