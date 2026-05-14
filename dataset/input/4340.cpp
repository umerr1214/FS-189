#include <iostream>
#include <string>
#include <vector>
#include <cmath>   // For std::abs in robustness - included for consistency, not strictly needed here
#include <limits>  // For std::numeric_limits<int>::min() - included for consistency, not strictly needed here

// Function with readability and efficiency issues
bool isEven(int num) {
    if (num == 0) {
        return true;
    } else if (num > 0) {
        // Inefficiently subtract 2 until num is 0 or 1
        while (num >= 2) {
            num -= 2;
        }
        return num == 0;
    } else { // num < 0
        // Inefficiently add 2 until num is 0 or -1
        while (num <= -2) {
            num += 2;
        }
        return num == 0;
    }
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

    // Add specific test case for the robustness issue: INT_MIN (will pass here, but for consistency in driver)
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