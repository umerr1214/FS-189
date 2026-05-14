#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// Correct and efficient function to check if a 1D integer array is sorted in ascending order.
// This implementation uses an O(N) approach, iterating through the array once.
bool isSorted(const int* arr, int size) {
    // An empty array or an array with a single element is always considered sorted.
    // The loop condition `i < size - 1` naturally handles these cases:
    // If size is 0, `i < -1` is false, the loop does not execute, and true is returned.
    // If size is 1, `i < 0` is false, the loop does not execute, and true is returned.
    for (int i = 0; i < size - 1; ++i) {
        // If any element is greater than its subsequent element, the array is not sorted
        // in ascending order, so we can immediately return false.
        if (arr[i] > arr[i+1]) {
            return false;
        }
    }
    // If the loop completes without finding any out-of-order elements,
    // the array is sorted in ascending order.
    return true;
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
        { "{1, 2, 4, 3}", "false" },
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