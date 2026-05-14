#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <utility> // For std::pair
#include <limits>  // For std::numeric_limits

// Function to find the maximum and minimum elements in an array
// This is a correct, efficient, and robust version.
std::pair<int, int> findMinMax(int arr[], int size) {
    if (size == 0) {
        // Robustly handle an empty array by returning specific sentinel values.
        // INT_MAX for min and INT_MIN for max signifies that no elements were found.
        return {std::numeric_limits<int>::max(), std::numeric_limits<int>::min()};
    }

    // Initialize min_val and max_val with the first element of the array.
    // This handles arrays with a single element correctly and provides a valid starting point
    // for comparison with subsequent elements.
    int min_val = arr[0];
    int max_val = arr[0];

    // Iterate through the rest of the array (starting from the second element).
    // This finds both min and max in a single pass, which is efficient (O(N) time complexity).
    for (int i = 1; i < size; ++i) {
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
        if (arr_vec.empty()) {
            // Check for the specific sentinel values used for empty arrays
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