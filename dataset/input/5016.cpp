#include <iostream>
#include <cstring> // For strcmp and strlen
#include <vector>  // Not strictly needed for this problem, but often included

// Function with a semantic error: writes one byte past the intended buffer end
void myStrcpy(char* dest, const char* src) {
    char* current_dest = dest;
    const char* current_src = src;

    while (*current_src != '\0') {
        *current_dest = *current_src;
        current_dest++;
        current_src++;
    }
    // At this point, current_dest points to the location where the null terminator should go.
    // And current_src points to the null terminator itself.

    // Semantic error: Copies the null terminator, then increments current_dest,
    // then writes *another* null terminator one byte past the intended end.
    // This results in a 1-byte buffer overflow/memory corruption.
    *current_dest = *current_src; // Copies the first null terminator (correctly terminating the string)
    current_dest++;               // Increments current_dest past the first null terminator
    *current_dest = '\0';         // ERROR: Writes a second null terminator one byte past the intended end.
                                  // This is an out-of-bounds write if dest_buffer was exactly sized.
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
        // For semantic error, fill buffer with known pattern to detect overwrite
        char* dest_buffer = new char[test_cases[i].dest_size];
        memset(dest_buffer, 'X', test_cases[i].dest_size); // Fill with 'X' to easily spot unintended writes

        myStrcpy(dest_buffer, test_cases[i].src);

        // The string content will appear correct because the first null terminator is in place.
        // The semantic error is a side-effect (extra write).
        if (strcmp(dest_buffer, test_cases[i].expected) == 0) {
            std::cout << "Test " << i + 1 << " Passed (content).\n";
            passed_count++;
        } else {
            std::cout << "Test " << i + 1 << " Failed (content).\n";
            std::cout << "  Input src: \"" << test_cases[i].src << "\"\n";
            std::cout << "  Expected: \"" << test_cases[i].expected << "\"\n";
            std::cout << "  Got:      \"" << dest_buffer << "\"\n";
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