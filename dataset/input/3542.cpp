#include <iostream> // For standard I/O operations

// Function to perform a linear search on an integer array.
// This version has readability/efficiency issues due to a convoluted while loop
// and less descriptive variable names.
int linearSearch(int arr_ptr[], int arr_len, int search_val) {
    // Readability Issue: Less descriptive variable names (arr_ptr, arr_len, search_val).
    // Readability/Efficiency Issue: Uses a while loop with a boolean flag and manual increment,
    // which is less concise and slightly less idiomatic for this common pattern than a for loop.
    
    int current_idx = 0; // Initialize index
    bool found_flag = false; // Flag to indicate if target is found
    int result_idx = -1; // Stores the index if found

    // Loop through the array
    while (current_idx < arr_len) {
        if (arr_ptr[current_idx] == search_val) {
            found_flag = true; // Set flag if value is found
            result_idx = current_idx; // Store the index
            break; // Exit loop immediately once found (minor efficiency, but still less readable structure)
        }
        current_idx++; // Manually increment index
    }

    // Return the stored index, which will be -1 if not found
    return result_idx;
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
              
    // Test Case 6: Target at start
    int arr6[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    int target6 = 1;
    std::cout << "Searching for " << target6 << " in {1..10}: "
              << linearSearch(arr6, size6, target6) << " (Expected: 0)" << std::endl;

    // Test Case 7: Target at end
    int arr7[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size7 = sizeof(arr7) / sizeof(arr7[0]);
    int target7 = 10;
    std::cout << "Searching for " << target7 << " in {1..10}: "
              << linearSearch(arr7, size7, target7) << " (Expected: 9)" << std::endl;

    return 0;
}