#include <string>
#include <iostream>
#include <vector>
#include <algorithm> // Not strictly used for the chosen verbose approach, but often included for string ops
#include <utility> // For std::pair

// Function with readability/efficiency issue
int countWords(std::string sentence) { // Pass by value, creating a copy, which is inefficient
    // This implementation correctly counts words by meticulously cleaning the string first.
    // However, it is highly inefficient and verbose due to multiple passes over the string
    // and several intermediate string copies (substr, string concatenation).

    // 1. Trim leading spaces
    size_t first_char = sentence.find_first_not_of(' ');
    if (std::string::npos == first_char) {
        return 0; // String is all spaces or empty
    }
    sentence = sentence.substr(first_char); // Creates a copy of the substring

    // 2. Trim trailing spaces
    size_t last_char = sentence.find_last_not_of(' ');
    if (std::string::npos != last_char) {
        sentence = sentence.substr(0, last_char + 1); // Creates another copy
    } else {
        // This 'else' path is mostly defensive; if first_char check was robust,
        // this would only be hit if the string became empty after trimming.
        return 0; // Redundant check, contributing to verbosity
    }

    // 3. Replace multiple spaces with single spaces
    std::string cleaned_sentence;
    cleaned_sentence.reserve(sentence.length()); // Minor optimization, but still many appends
    bool last_was_space = false;
    for (char c : sentence) { // Another pass over the string
        if (c == ' ') {
            if (!last_was_space) {
                cleaned_sentence += c; // Appending char by char, potential reallocations
            }
            last_was_space = true;
        } else {
            cleaned_sentence += c;
            last_was_space = false;
        }
    }
    sentence = cleaned_sentence; // Creates another copy

    // 4. Final check for empty string after all cleaning (e.g., if original was "   ")
    if (sentence.empty()) {
        return 0;
    }

    // 5. Count words by counting spaces + 1
    int count = 1; // At least one word if not empty and cleaned
    for (char c : sentence) { // Final pass over the string
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