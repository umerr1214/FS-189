#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <utility> // For std::pair

// Function to find the maximum and minimum elements in an array
// This version has robustness issues related to initialization and empty arrays.
std::pair<int, int> findMinMax(int arr[], int size) {
    // Robustness Issue 1: Arbitrary handling for an empty array.
    // Returning {0, 0} is an arbitrary sentinel that might conflict with valid data
    // or not clearly indicate an error state. A more robust solution would throw
    // an exception or use specific sentinel values like INT_MAX/INT_MIN.
    if (size == 0) {
        return {0, 0};
    }

    // Robustness Issue 2: Initializing min_val and max_val to 0.
    // This leads to incorrect results if all array elements are positive (min will be 0)
    // or all array elements are negative (max will be 0).
    // For example, if array is {5, 10, 2}, min_val will incorrectly remain 0.
    // If array is {-5, -10, -2}, max_val will incorrectly remain 0.
    int min_val = 0;
    int max_val = 0;

    // Loop through all elements, comparing against the initial 0 values.
    for (int i = 0; i < size; ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    return {min_val, max_val};
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss_input(line);
        std::vector<int> arr_vec;
        std::string segment;

        if (line.empty()) {
            // Treat empty line as empty array
        } else {
            // Parse comma-separated integers
            while(std::getline(ss_input, segment, ',')) {
                if (!segment.empty()) {
                    arr_vec.push_back(std::stoi(segment));
                }
            }
        }

        std::pair<int, int> result = findMinMax(arr_vec.data(), arr_vec.size());
        std::cout << "Min: " << result.first << ", Max: " << result.second << std::endl;
    }
    return 0;
}