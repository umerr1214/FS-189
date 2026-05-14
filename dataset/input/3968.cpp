#include <iostream>
#include <vector>
#include <limits> // Potentially for std::numeric_limits, but not used in this specific implementation.

// Function definition - Correct but inefficient (uses two separate loops)
// This version is less efficient because it iterates through the array twice:
// once to find the minimum and once to find the maximum.
void analyzeArray(const int* arr, int size, int& minVal, int& maxVal) {
    // Basic check to prevent immediate crash, but the primary issue is efficiency.
    if (size <= 0) {
        // For an empty array, minVal and maxVal are not updated.
        return;
    }

    // Efficiency Issue: First loop to find the minimum value
    minVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }

    // Efficiency Issue: Second separate loop to find the maximum value
    maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
}

int main() {
    // Demonstrate with an example array
    std::vector<int> arr_vec = {10, 4, 20, 5, 15, 8};
    int size = arr_vec.size();
    int min_val = 0, max_val = 0; // Initialize for safety

    std::cout << "Demonstration 1: Normal array" << std::endl;
    std::cout << "Array: {10, 4, 20, 5, 15, 8}, Size: " << size << std::endl;
    analyzeArray(arr_vec.data(), size, min_val, max_val);
    std::cout << "Min: " << min_val << ", Max: " << max_val << std::endl;
    std::cout << "---" << std::endl;

    // Another example with a single element
    std::vector<int> arr_single_vec = {42};
    int size_single = arr_single_vec.size();
    int min_single = 0, max_single = 0;

    std::cout << "Demonstration 2: Single element array" << std::endl;
    std::cout << "Array: {42}, Size: " << size_single << std::endl;
    analyzeArray(arr_single_vec.data(), size_single, min_single, max_single);
    std::cout << "Min: " << min_single << ", Max: " << max_single << std::endl;

    return 0;
}