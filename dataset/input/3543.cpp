#include <iostream> // Required for standard input/output operations

// Function to perform a linear search on a 1D integer array.
// Returns the index of the target element if found, or -1 if not found.
// This is the correct and well-optimized version for a linear search.
int linearSearch(int arr[], int size, int target) {
    // Iterate through the array from the first element to the last.
    // The loop condition `i < size` correctly handles empty arrays (size = 0)
    // by not executing the loop body, and also handles non-positive sizes gracefully.
    for (int i = 0; i < size; ++i) {
        // If the current element matches the target, return its index.
        if (arr[i] == target) {
            return i;
        }
    }
    // If the loop completes without finding the target, return -1.
    return -1;
}

int main() {
    // --- Test Cases ---

    // Test Case 1: Target found in the middle of the array
    int arr1[] = {10, 20, 30, 40, 50};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int target1 = 30;
    std::cout << "Searching for " << target1 << " in {10, 20, 30, 40, 50}: "
              << linearSearch(arr1, size1, target1) << " (Expected: 2)" << std::endl;

    // Test Case 2: Target not found in the array
    int arr2[] = {10, 20, 30, 40, 50};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int target2 = 99;
    std::cout << "Searching for " << target2 << " in {10, 20, 30, 40, 50}: "
              << linearSearch(arr2, size2, target2) << " (Expected: -1)" << std::endl;

    // Test Case 3: Searching in an empty array
    int arr3[] = {}; // An empty array
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
              
    // Test Case 6: Target at the beginning of a larger array
    int arr6[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    int target6 = 1;
    std::cout << "Searching for " << target6 << " in {1..10}: "
              << linearSearch(arr6, size6, target6) << " (Expected: 0)" << std::endl;

    // Test Case 7: Target at the end of a larger array
    int arr7[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size7 = sizeof(arr7) / sizeof(arr7[0]);
    int target7 = 10;
    std::cout << "Searching for " << target7 << " in {1..10}: "
              << linearSearch(arr7, size7, target7) << " (Expected: 9)" << std::endl;

    return 0;
}