#include <iostream>
#include <string> // Required for std::stoi
#include <algorithm> // For std::min and std::max (optional, but good practice)

// Correct and efficient function to find maximum and minimum values in a single pass
void find_max_min(const int* arr, int size, int* max_val, int* min_val) {
    // Robustness checks:
    // If the array is empty or null, we cannot find max/min.
    // Set output pointers to 0 (or a sentinel value like numeric_limits<int>::min/max)
    // to indicate that no valid max/min was found.
    if (arr == nullptr || size <= 0) {
        if (max_val) *max_val = 0; // Default value for no elements
        if (min_val) *min_val = 0; // Default value for no elements
        return;
    }

    // Initialize max_val and min_val with the first element of the array.
    // This is safe because we've already checked that size > 0.
    *max_val = arr[0];
    *min_val = arr[0];

    // Iterate from the second element (index 1) to find the true max and min in a single pass.
    for (int i = 1; i < size; ++i) {
        // Update maximum if current element is greater
        if (arr[i] > *max_val) {
            *max_val = arr[i];
        }
        // Update minimum if current element is smaller
        if (arr[i] < *min_val) {
            *min_val = arr[i];
        }
        // Alternatively, using std::max and std::min for conciseness:
        // *max_val = std::max(*max_val, arr[i]);
        // *min_val = std::min(*min_val, arr[i]);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <test_case_id>" << std::endl;
        return 1;
    }

    int test_case_id = std::stoi(argv[1]);

    int max_val = 0, min_val = 0; // Initialize to avoid warnings

    switch (test_case_id) {
        case 1: { // Standard array
            int arr[] = {5, 2, 9, 1, 7};
            int size = sizeof(arr) / sizeof(arr[0]);
            find_max_min(arr, size, &max_val, &min_val);
            std::cout << "Max: " << max_val << ", Min: " << min_val << std::endl;
            break;
        }
        case 2: { // Single element array
            int arr[] = {42};
            int size = sizeof(arr) / sizeof(arr[0]);
            find_max_min(arr, size, &max_val, &min_val);
            std::cout << "Max: " << max_val << ", Min: " << min_val << std::endl;
            break;
        }
        case 3: { // Empty array
            int arr[] = {}; // Represents an empty array
            int size = 0;
            find_max_min(arr, size, &max_val, &min_val);
            // Expected to set max_val/min_val to 0 as per implementation
            std::cout << "Max: " << max_val << ", Min: " << min_val << std::endl;
            break;
        }
        case 4: { // Array with negative numbers
            int arr[] = {-5, -2, -9, -1, -7};
            int size = sizeof(arr) / sizeof(arr[0]);
            find_max_min(arr, size, &max_val, &min_val);
            std::cout << "Max: " << max_val << ", Min: " << min_val << std::endl;
            break;
        }
        case 5: { // Null array pointer
            int* arr = nullptr;
            int size = 10; // Size doesn't matter if arr is nullptr, as the check handles it
            find_max_min(arr, size, &max_val, &min_val);
            // Expected to set max_val/min_val to 0 as per implementation
            std::cout << "Max: " << max_val << ", Min: " << min_val << std::endl;
            break;
        }
        default:
            std::cerr << "Invalid test case ID." << std::endl;
            return 1;
    }

    return 0;
}