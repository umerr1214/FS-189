#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// Function with a robustness issue:
// It fails to check the last pair of elements in the array,
// leading to incorrect results for arrays where only the last pair is unsorted.
// For example, for an array like {1, 2, 4, 3}, it will incorrectly return true.
bool isSorted(const int* arr, int size) {
    if (size <= 1) {
        return true; // Correctly handles empty or single-element arrays
    }

    // Robustness issue: The loop condition `i < size - 2` is off by one.
    // It should be `i < size - 1` to compare `arr[size-2]` with `arr[size-1]`.
    // This implementation misses checking the last pair of elements.
    for (int i = 0; i < size - 2; ++i) { // Incorrect loop upper bound
        if (arr[i] > arr[i+1]) {
            return false;
        }
    }
    // If the loop completes, it means elements up to `arr[size-3]` compared with `arr[size-2]`
    // are in ascending order. However, `arr[size-2]` and `arr[size-1]` are not checked.
    return true; // May return true for arrays like {1, 2, 4, 3}
}

// Helper to convert boolean to string for output
std::string boolToString(bool b) {
    return b ? "true" : "false";
}

// Helper to parse input string like "{1, 2, 3}" into a vector
std::vector<int> parseVector(const std::string& s) {
    std::vector<int> vec;
    if (s == "{}") return vec;
    std::string temp = s.substr(1, s.length() - 2); // Remove braces
    std::stringstream ss(temp);
    std::string item;
    while (std::getline(ss, item, ',')) {
        vec.push_back(std::stoi(item));
    }
    return vec;
}

int main() {
    std::vector<std::pair<std::string, std::string>> test_cases = {
        { "{}", "true" },
        { "{5}", "true" },
        { "{1, 2, 3, 4, 5}", "true" },
        { "{1, 1, 2, 3}", "true" },
        { "{5, 4, 3, 2, 1}", "false" },
        { "{1, 3, 2, 4, 5}", "false" },
        { "{1, 2, 4, 3}", "false" }, // This specific test case highlights the robustness issue
        { "{0, 1, 0}", "false" }
    };

    for (size_t i = 0; i < test_cases.size(); ++i) {
        const auto& test_case = test_cases[i];
        std::vector<int> arr = parseVector(test_case.first);
        
        bool result = isSorted(arr.data(), arr.size());
        std::string result_str = boolToString(result);

        std::cout << "Test Case " << i + 1 << ":\n";
        std::cout << "Input: " << test_case.first << "\n";
        std::cout << "Expected: " << test_case.second << "\n";
        std::cout << "Actual: " << result_str << "\n";
        if (result_str == test_case.second) {
            std::cout << "Status: PASSED\n\n";
        } else {
            std::cout << "Status: FAILED\n\n";
        }
    }

    return 0;
}