#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// Function with an efficiency issue:
// It uses an O(N^2) approach for a problem that can be solved in O(N).
bool isSorted(const int* arr, int size) {
    // Explicitly handle empty or single-element arrays for clarity,
    // though the nested loops would implicitly handle them by not executing.
    if (size <= 1) {
        return true;
    }

    // Efficiency issue: This implementation uses nested loops, resulting in O(N^2) time complexity.
    // For each element `arr[i]`, it compares it with all subsequent elements `arr[j]`.
    // While correct, this is highly inefficient for large arrays compared to the optimal O(N) solution.
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] > arr[j]) {
                return false; // Found an element that is greater than a subsequent element
            }
        }
    }
    return true; // If no such pair is found, the array is sorted
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