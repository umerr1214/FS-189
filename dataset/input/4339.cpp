#include <iostream>
#include <string>
#include <vector>
#include <cmath>   // For std::abs
#include <limits>  // For std::numeric_limits<int>::min()

// Function with a robustness issue: std::abs(INT_MIN) is undefined behavior.
bool isEven(int num) {
    // For INT_MIN, std::abs(INT_MIN) is undefined behavior,
    // as there is no positive representation for INT_MIN.
    return std::abs(num) % 2 == 0;
}

int main() {
    std::vector<std::pair<int, bool>> testCases = {
        {4, true},
        {7, false},
        {0, true},
        {-2, true},
        {-3, false},
        {100, true},
        {99, false},
        {-100, true},
        {-99, false}
    };

    // Add specific test case for the robustness issue: INT_MIN
    int min_int = std::numeric_limits<int>::min();
    testCases.push_back({min_int, true}); // INT_MIN is an even number

    std::cout << std::boolalpha; // Print true/false instead of 1/0

    for (const auto& tc : testCases) {
        int input = tc.first;
        bool expected = tc.second;
        bool actual = isEven(input);
        std::cout << "Input: " << input
                  << ", Expected: " << expected
                  << ", Actual: " << actual;
        if (actual == expected) {
            std::cout << " [PASSED]\n";
        } else {
            std::cout << " [FAILED]\n";
        }
    }

    return 0;
}