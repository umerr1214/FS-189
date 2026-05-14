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
// LOGICAL ERROR: Forgetting to null-terminate the destination string
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

    // Missing: dest[len1 + len2] = '\0';
    // This will lead to the string not being properly terminated, potentially
    // causing `std::string` or other string functions to read past the intended end.
}

// Driver code for testing
#include <vector>
#include <string> // Only for comparison in driver, not in concatenation logic

struct TestCase {
    const char* s1;
    const char* s2;
    const char* expected;
    char buffer[256]; // Buffer for the result
};

int main() {
    std::vector<TestCase> testCases = {
        {"Hello", "World", "HelloWorld", ""},
        {"Open", "AI", "OpenAI", ""},
        {"", "Test", "Test", ""},
        {"Test", "", "Test", ""},
        {"LongString", "AnotherLongString", "LongStringAnotherLongString", ""}
    };

    bool all_passed = true;
    for (size_t i = 0; i < testCases.size(); ++i) {
        // Reset buffer for each test case
        for (int k = 0; k < 256; ++k) testCases[i].buffer[k] = '\0';

        concatenate(testCases[i].buffer, testCases[i].s1, testCases[i].s2);

        // Compare with expected (using std::string for easy comparison in driver)
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