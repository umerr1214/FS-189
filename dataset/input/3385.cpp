#include <iostream>
#include <vector>
#include <string> // Required for std::stoi

// Function with robustness issue: does not handle empty array or null pointer
void find_max_min(const int* arr, int size, int* max_val, int* min_val) {
    // CRITICAL ROBUSTNESS ISSUE: No check for size == 0 or arr == nullptr.
    // Accessing arr[0] when size is 0 or arr is nullptr will lead to undefined behavior or a program crash (e.g., segmentation fault).
    *max_val = arr[0]; // Potential crash here if size is 0 or arr is nullptr
    *min_val = arr[0]; // Potential crash here if size is 0 or arr is nullptr

    for (int i = 1; i < size; ++i) {
        if (arr[i] > *max_val) {
            *max_val = arr[i];
        }
        if (arr[i] < *min_val) {
            *min_val = arr[i];
        }
    }
}

int main(int argc, char* argv[]) {
    // This main is designed to be run by the JSON driver.
    // It takes command line arguments to select a test case.
    // This allows the driver to selectively trigger the crashing case.

    if (argc < 2) {
        // If no test case ID is provided, print usage and exit.
        std::cerr << "Usage: " << argv[0] << " <test_case_id>" << std::endl;
        return 1;
    }

    int test_case_id = std::stoi(argv[1]); // Convert argument to integer

    int max_val = 0, min_val = 0; // Initialize to avoid uninitialized read warnings

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
        case 3: { // Empty array - EXPECTED CRASH/UNDEFINED BEHAVIOR
            // This is where the robustness issue manifests.
            // The function will attempt to access arr[0] when size is 0.
            int* arr = nullptr; // Represents an empty array scenario or null pointer
            int size = 0;
            std::cout << "Attempting to call find_max_min with empty array/nullptr (expected crash)..." << std::endl;
            find_max_min(arr, size, &max_val, &min_val); // This line is expected to crash the program.
            // If the program somehow survives, print values (though it's still undefined behavior).
            std::cout << "Survived crash attempt. Max: " << max_val << ", Min: " << min_val << std::endl;
            break;
        }
        case 4: { // Array with negative numbers
            int arr[] = {-5, -2, -9, -1, -7};
            int size = sizeof(arr) / sizeof(arr[0]);
            find_max_min(arr, size, &max_val, &min_val);
            std::cout << "Max: " << max_val << ", Min: " << min_val << std::endl;
            break;
        }
        default:
            std::cerr << "Invalid test case ID." << std::endl;
            return 1;
    }

    return 0;
}