#include <iostream>
#include <string> // Required for std::stoi

// Function with efficiency issue: performs two passes instead of one
void find_max_min(const int* arr, int size, int* max_val, int* min_val) {
    if (arr == nullptr || size <= 0) {
        // Handle empty or invalid array gracefully.
        // Set output pointers to 0 to indicate no valid max/min was found.
        if (max_val) *max_val = 0;
        if (min_val) *min_val = 0;
        return;
    }

    // First pass to find the maximum value
    *max_val = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > *max_val) {
            *max_val = arr[i];
        }
    }

    // Second pass to find the minimum value
    *min_val = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < *min_val) {
            *min_val = arr[i];
        }
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
            int size = 10; // Size doesn't matter if arr is nullptr
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