#include <string>
#include <iostream>
#include <vector>
#include <utility> // For std::pair

// Function with robustness issue
int countWords(const std::string& sentence) {
    // This implementation attempts to count words by counting spaces + 1.
    // It correctly handles an empty string, but fails for other edge cases:
    // - Strings with only spaces (e.g., "   " will return 4 instead of 0)
    // - Leading/trailing spaces (e.g., " hello " will return 3 instead of 1)
    // - Multiple spaces between words (e.g., "hello   world" will return 3 instead of 2)

    if (sentence.empty()) {
        return 0; // Correctly handles empty string
    }

    int count = 1; // Assume at least one word if the string is not empty
    for (char c : sentence) {
        if (c == ' ') {
            count++;
        }
    }
    return count;
}

int main() {
    // Driver code for testing
    std::vector<std::pair<std::string, int>> test_cases = {
        {"", 0},
        {"hello", 1},
        {"hello world", 2},
        {"  hello world  ", 2},
        {"hello   world", 2},
        {"   ", 0},
        {"one", 1},
        {"multiple words test string", 4}
    };

    bool all_passed = true;
    for (size_t i = 0; i < test_cases.size(); ++i) {
        const auto& tc = test_cases[i];
        std::string input = tc.first;
        int expected = tc.second; // Expected based on correct logic
        int actual = countWords(input);

        if (actual == expected) {
            std::cout << "Test " << i + 1 << " Passed: Input=\"" << input << "\", Expected=" << expected << ", Got=" << actual << std::endl;
        } else {
            std::cout << "Test " << i + 1 << " FAILED: Input=\"" << input << "\", Expected=" << expected << ", Got=" << actual << std::endl;
            all_passed = false;
        }
    }

    if (all_passed) {
        std::cout << "All tests passed!" << std::endl;
        return 0;
    } else {
        std::cout << "Some tests failed." << std::endl;
        return 1;
    }
}