#include <iostream>
#include <vector>
#include <algorithm> // Not strictly needed for manual min/max, but useful for other operations
#include <limits>    // For std::numeric_limits if initializing to extreme values (not used here)

// Function definition - Robust and efficient (single pass)
// Handles empty arrays gracefully and finds min/max in a single iteration.
void analyzeArray(const int* arr, int size, int& minVal, int& maxVal) {
    if (arr == nullptr || size <= 0) {
        // For an empty or invalid array, there are no min/max elements to find.
        // The function will not modify minVal and maxVal, leaving them as they were
        // initialized by the caller. The caller should handle this case (e.g., print a message).
        return;
    }

    // Initialize minVal and maxVal with the first element.
    // This is safe because 'size' is guaranteed to be > 0 here.
    minVal = arr[0];
    maxVal = arr[0];

    // Iterate from the second element in a single pass to find both min and max.
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
}

int main() {
    // Example 1: Normal array
    std::vector<int> arr_vec1 = {5, 1, 9, 3, 7};
    int size1 = arr_vec1.size();
    int min1_val = 0, max1_val = 0; // Initialize for safety

    std::cout << "Demonstration 1: Normal array" << std::endl;
    std::cout << "Array: {5, 1, 9, 3, 7}, Size: " << size1 << std::endl;
    analyzeArray(arr_vec1.data(), size1, min1_val, max1_val);
    std::cout << "Min: " << min1_val << ", Max: " << max1_val << std::endl;
    std::cout << "---" << std::endl;

    // Example 2: Array with one element
    std::vector<int> arr_vec2 = {42};
    int size2 = arr_vec2.size();
    int min2_val = 0, max2_val = 0;

    std::cout << "Demonstration 2: Single element array" << std::endl;
    std::cout << "Array: {42}, Size: " << size2 << std::endl;
    analyzeArray(arr_vec2.data(), size2, min2_val, max2_val);
    std::cout << "Min: " << min2_val << ", Max: " << max2_val << std::endl;
    std::cout << "---" << std::endl;

    // Example 3: Empty array (robust handling)
    std::vector<int> arr_vec3; // An empty vector
    int size3 = arr_vec3.size(); // size3 will be 0
    int min3_val = 0, max3_val = 0; // These will remain 0 after the call

    std::cout << "Demonstration 3: Empty array (robust handling)" << std::endl;
    std::cout << "Array: {}, Size: " << size3 << std::endl;
    analyzeArray(arr_vec3.data(), size3, min3_val, max3_val);
    
    if (size3 <= 0) {
        std::cout << "Cannot find min/max for an empty array. minVal and maxVal remain at their initial values (0, 0)." << std::endl;
    } else {
        std::cout << "Min: " << min3_val << ", Max: " << max3_val << std::endl;
    }
    std::cout << "---" << std::endl;

    return 0;
}