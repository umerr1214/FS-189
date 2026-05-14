#include <iostream> // For standard I/O operations
#include <cstddef>  // For nullptr_t (though not strictly needed for nullptr keyword)

// Function to perform a linear search on an integer array.
// This version has a robustness issue: it does not handle a nullptr array pointer gracefully
// if size > 0, leading to undefined behavior or a crash.
int linearSearch(int arr[], int size, int target) {
    // Robustness Issue: No check for arr == nullptr.
    // If arr is nullptr and size > 0, dereferencing arr[i] will cause a segmentation fault.
    
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Target found, return its index
        }
    }
    return -1; // Target not found
}

int main() {
    // --- Test Cases ---

    // Test Case 1: Target found in the middle
    int arr1[] = {10, 20, 30, 40, 50};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int target1 = 30;
    std::cout << "Searching for " << target1 << " in {10, 20, 30, 40, 50}: "
              << linearSearch(arr1, size1, target1) << " (Expected: 2)" << std::endl;

    // Test Case 2: Target not found
    int arr2[] = {10, 20, 30, 40, 50};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int target2 = 99;
    std::cout << "Searching for " << target2 << " in {10, 20, 30, 40, 50}: "
              << linearSearch(arr2, size2, target2) << " (Expected: -1)" << std::endl;

    // Test Case 3: Empty array
    int arr3[] = {};
    int size3 = 0;
    int target3 = 5;
    std::cout << "Searching for " << target3 << " in {}: "
              << linearSearch(arr3, size3, target3) << " (Expected: -1)" << std::endl;

    // Test Case 4: Single element array - target found
    int arr4[] = {7};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    int target4 = 7;
    std::cout << "Searching for " << target4 << " in {7}: "
              << linearSearch(arr4, size4, target4) << " (Expected: 0)" << std::endl;

    // Test Case 5: Single element array - target not found
    int arr5[] = {7};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    int target5 = 10;
    std::cout << "Searching for " << target5 << " in {7}: "
              << linearSearch(arr5, size5, target5) << " (Expected: -1)" << std::endl;

    // Test Case 6: Robustness Issue Demonstration - Passing a nullptr array with positive size
    // This will likely cause a segmentation fault or other undefined behavior.
    int* null_arr = nullptr;
    int null_size = 3;
    int null_target = 10;
    std::cout << "Searching for " << null_target << " in nullptr array (size 3): " << std::endl;
    // The following line is expected to crash the program.
    // Uncommenting it will demonstrate the robustness issue.
    // std::cout << linearSearch(null_arr, null_size, null_target) << " (Expected: CRASH)" << std::endl;
    std::cout << " (Expected: CRASH if uncommented. Code is designed to expose robustness issue.)" << std::endl;

    return 0;
}