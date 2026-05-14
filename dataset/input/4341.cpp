#include <iostream>
#include <string>
#include <vector>
#include <cmath>   // For std::abs in robustness - included for consistency, not strictly needed here
#include <limits>  // For std::numeric_limits<int>::min() - included for consistency, not strictly needed here

// Correct and efficient function
bool isEven(int num) {
    // The modulo operator (%) correctly handles positive, negative, and zero.
    // An integer 'x' is even if x % 2 == 0.
    return num % 2 == 0;
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

    // Add specific test case for the robustness issue: INT_MIN (will pass here)
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