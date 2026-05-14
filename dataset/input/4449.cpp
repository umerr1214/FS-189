#include <string>
#include <sstream> // For std::stringstream
#include <iostream>
#include <vector>
#include <utility> // For std::pair

// Correct, readable, and efficient function
int countWords(const std::string& sentence) {
    std::stringstream ss(sentence); // Create a stringstream from the input sentence
    std::string word;
    int count = 0;
    // The operator>> for stringstream extracts non-whitespace sequences (words).
    // It automatically handles leading/trailing whitespace and treats multiple
    // spaces between words as a single delimiter, making it robust for this task.
    while (ss >> word) {
        count++;
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
        int expected = tc.second;
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