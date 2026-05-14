#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <utility> // For std::pair
#include <limits>  // For std::numeric_limits

// Function to find the maximum and minimum elements in an array
// This version has an efficiency issue: it iterates through the array twice.
std::pair<int, int> findMinMax(int arr[], int size) {
    if (size == 0) {
        // Robustly handle an empty array by returning specific sentinel values.
        // INT_MAX for min and INT_MIN for max signifies that no elements were found.
        return {std::numeric_limits<int>::max(), std::numeric_limits<int>::min()};
    }

    // Efficiency Issue: First pass to find the minimum.
    // This requires iterating through the entire array.
    int minimumValue = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minimumValue) {
            minimumValue = arr[i];
        }
    }

    // Efficiency Issue: Second pass to find the maximum.
    // This also requires iterating through the entire array, making it less efficient
    // than a single pass solution that finds both min and max simultaneously.
    int maximumValue = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maximumValue) {
            maximumValue = arr[i];
        }
    }

    return {minimumValue, maximumValue};
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
        if (arr_vec.empty()) {
            if (result.first == std::numeric_limits<int>::max() && result.second == std::numeric_limits<int>::min()) {
                std::cout << "Empty Array" << std::endl;
            } else {
                // This branch should ideally not be reached if empty array is handled correctly by findMinMax
                std::cout << "Min: " << result.first << ", Max: " << result.second << std::endl;
            }
        } else {
            std::cout << "Min: " << result.first << ", Max: " << result.second << std::endl;
        }
    }
    return 0;
}