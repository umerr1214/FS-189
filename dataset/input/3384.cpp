#include <iostream>
#include <limits> // Required for std::numeric_limits
#include <vector>
#include <string>
#include <sstream>

// Function to find maximum and minimum values in an array
void find_max_min(const int* arr, int size, int* max_val, int* min_val) {
    // SEMANTIC ERROR: No explicit check for `size <= 0`.
    // If `size` is 0, accessing `arr[0]` results in out-of-bounds memory access,
    // leading to undefined behavior.
    // Also, assumes `max_val` and `min_val` are non-null.

    *max_val = arr[0]; // Potential undefined behavior if size is 0
    *min_val = arr[0]; // Potential undefined behavior if size is 0

    for (int i = 1; i < size; i++) {
        if (arr[i] > *max_val) {
            *max_val = arr[i];
        }
        if (arr[i] < *min_val) {
            *min_val = arr[i];
        }
    }
}

// Helper function to convert an array to string for printing
std::string array_to_string(const int* arr, int size) {
    if (size <= 0) return "[]";
    std::stringstream ss;
    ss << "[";
    for (int i = 0; i < size; ++i) {
        ss << arr[i];
        if (i < size - 1) ss << ", ";
    }
    ss << "]";
    return ss.str();
}

int main() {
    int max_val_res, min_val_res;

    // Test Case 1: Standard positive numbers
    int arr1[] = {10, 5, 20, 15, 30};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    find_max_min(arr1, size1, &max_val_res, &min_val_res);
    std::cout << "Input: " << array_to_string(arr1, size1) << ", Size: " << size1 << std::endl;
    std::cout << "Output: Max=" << max_val_res << ", Min=" << min_val_res << std::endl;

    // Test Case 2: Negative numbers
    int arr2[] = {-1, -5, -10, -2};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    find_max_min(arr2, size2, &max_val_res, &min_val_res);
    std::cout << "Input: " << array_to_string(arr2, size2) << ", Size: " << size2 << std::endl;
    std::cout << "Output: Max=" << max_val_res << ", Min=" << min_val_res << std::endl;

    // Test Case 3: Single element
    int arr3[] = {42};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    find_max_min(arr3, size3, &max_val_res, &min_val_res);
    std::cout << "Input: " << array_to_string(arr3, size3) << ", Size: " << size3 << std::endl;
    std::cout << "Output: Max=" << max_val_res << ", Min=" << min_val_res << std::endl;

    // Test Case 4: Mixed positive and negative
    int arr4[] = {5, -3, 0, 10, -8};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    find_max_min(arr4, size4, &max_val_res, &min_val_res);
    std::cout << "Input: " << array_to_string(arr4, size4) << ", Size: " << size4 << std::endl;
    std::cout << "Output: Max=" << max_val_res << ", Min=" << min_val_res << std::endl;

    // Test Case 5: Empty array - This will likely cause a crash or garbage output due to the semantic error.
    int arr5[] = {};
    int size5 = 0;
    int initial_max_for_empty = 12345;
    int initial_min_for_empty = -54321;
    max_val_res = initial_max_for_empty;
    min_val_res = initial_min_for_empty;
    find_max_min(arr5, size5, &max_val_res, &min_val_res); // UNDEFINED BEHAVIOR HERE
    std::cout << "Input: " << array_to_string(arr5, size5) << ", Size: " << size5 << std::endl;
    std::cout << "Output (for empty): Max=" << max_val_res << ", Min=" << min_val_res << std::endl;

    return 0;
}