#include <iostream>

// Function to calculate string length without standard library functions
int getLength(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Function to concatenate two C-style strings
// This function does not perform bounds checking, making it susceptible to buffer overflows
void concatenate(char dest[], const char src1[], const char src2[]) {
    int len1 = getLength(src1);
    int len2 = getLength(src2);

    // Copy src1 to dest
    for (int i = 0; i < len1; ++i) {
        dest[i] = src1[i];
    }

    // Copy src2 to dest
    for (int i = 0; i < len2; ++i) {
        dest[len1 + i] = src2[i];
    }

    // Null-terminate dest
    dest[len1 + len2] = '\0';
}

// Driver code for testing
#include <vector>
#include <string> // Only for comparison in driver, not in concatenation logic

struct TestCase {
    const char* s1;
    const char* s2;
    const char* expected;
    char buffer[10]; // SEMANTIC ERROR: Buffer is too small for "HelloWorld" (length 10 + null terminator needs 11 bytes)
};

int main() {
    std::vector<TestCase> testCases = {
        {"Hello", "World", "HelloWorld", ""}, // Total length 10, needs 11 bytes. Will cause overflow.
        {"Open", "AI", "OpenAI", ""},         // Total length 6, needs 7 bytes. Fits.
        {"", "Test", "Test", ""},             // Total length 4, needs 5 bytes. Fits.
        {"Test", "", "Test", ""},             // Total length 4, needs 5 bytes. Fits.
        {"A", "B", "AB", ""}                  // Total length 2, needs 3 bytes. Fits.
    };

    bool all_passed = true;
    for (size_t i = 0; i < testCases.size(); ++i) {
        // Reset buffer for each test case
        for (int k = 0; k < 10; ++k) testCases[i].buffer[k] = '\0'; // Initialize small buffer

        // This call will cause a buffer overflow for the first test case
        // as "HelloWorld" requires 11 bytes (10 chars + null terminator)
        // but buffer is only 10 bytes.
        concatenate(testCases[i].buffer, testCases[i].s1, testCases[i].s2);

        // Compare with expected (using std::string for easy comparison in driver)
        // This might also read garbage or crash if buffer overflow corrupted memory
        std::string actual_str(testCases[i].buffer);
        std::string expected_str(testCases[i].expected);

        if (actual_str == expected_str) {
            std::cout << "Test Case " << i + 1 << " Passed: \"" << testCases[i].s1 << "\" + \"" << testCases[i].s2 << "\" -> \"" << actual_str << "\"" << std::endl;
        } else {
            std::cout << "Test Case " << i + 1 << " Failed: \"" << testCases[i].s1 << "\" + \"" << testCases[i].s2 << "\"" << std::endl;
            std::cout << "  Expected: \"" << expected_str << "\"" << std::endl;
            std::cout << "  Actual:   \"" << actual_str << "\"" << std::endl;
            all_passed = false;
        }
    }

    if (all_passed) {
        std::cout << "\nAll test cases passed!" << std::endl;
    } else {
        std::cout << "\nSome test cases failed." << std::endl;
    }

    return 0;
}