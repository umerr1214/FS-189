#include <iostream>

// Function with readability and efficiency issues
int linear_search(int* arr, int size, int target) {
    // Readability issue: Using a 'while' loop with manual index incrementation ('current_position++')
    // is generally less idiomatic and can be less clear than a 'for' loop for simple iteration.
    // Efficiency issue: The function does not return immediately after finding the target.
    // Instead, it continues iterating through the rest of the array, even if the target
    // was found at the very beginning. This leads to unnecessary computations, especially
    // for large arrays where the target is found early.
    // Readability issue: Variable name 'temp_idx' is not as descriptive as 'foundIndex' or 'resultIndex'.
    int temp_idx = -1;
    int current_position = 0;

    while (current_position < size) {
        if (arr[current_position] == target) {
            if (temp_idx == -1) { // Ensures only the index of the *first* occurrence is stored
                temp_idx = current_position;
            }
        }
        current_position++;
    }
    return temp_idx;
}

int main() {
    std::cout << "--- Testing Readability / Efficiency Issue ---" << std::endl;

    // Case 1: Target found at beginning (inefficient, scans whole array)
    int arr1[] = {10, 20, 30, 40, 50};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int target1 = 10;
    std::cout << "Array: {10, 20, 30, 40, 50}, Target: 10 -> Index: " << linear_search(arr1, size1, target1) << std::endl;

    // Case 2: Target found in middle (inefficient, scans rest of array)
    int arr2[] = {5, 15, 25};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int target2 = 15;
    std::cout << "Array: {5, 15, 25}, Target: 15 -> Index: " << linear_search(arr2, size2, target2) << std::endl;

    // Case 3: Empty array (works correctly)
    int arr3[] = {};
    int size3 = 0;
    int target3 = 100;
    std::cout << "Array: {}, Target: 100 -> Index: " << linear_search(arr3, size3, target3) << std::endl;

    // Case 4: Target not found (efficiency is not an issue here as full scan is required)
    int arr4[] = {7, 8, 9};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    int target4 = 10;
    std::cout << "Array: {7, 8, 9}, Target: 10 -> Index: " << linear_search(arr4, size4, target4) << std::endl;

    // Case 5: Target at end (efficiency is not an issue here as full scan is required)
    int arr5[] = {1, 2, 3, 4};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    int target5 = 4;
    std::cout << "Array: {1, 2, 3, 4}, Target: 4 -> Index: " << linear_search(arr5, size5, target5) << std::endl;

    // Case 6: Array with duplicates, target found at first occurrence (still inefficient)
    int arr6[] = {10, 20, 10, 30};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    int target6 = 10;
    std::cout << "Array: {10, 20, 10, 30}, Target: 10 -> Index: " << linear_search(arr6, size6, target6) << std::endl;

    return 0;
}