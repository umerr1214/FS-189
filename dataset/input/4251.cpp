#include <iostream>

// Correct, efficient, and readable linear_search function
int linear_search(int* arr, int size, int target) {
    // The loop iterates from the first element up to (but not including) 'size'.
    // If 'size' is 0 or negative, the loop condition 'i < size' correctly handles it
    // by not iterating at all, and the function proceeds to return -1.
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Return immediately upon finding the first occurrence (efficient)
        }
    }
    return -1; // Target not found after checking all elements
}

int main() {
    std::cout << "--- Testing Correct Version ---" << std::endl;

    // Case 1: Target found at beginning
    int arr1[] = {10, 20, 30, 40, 50};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int target1 = 10;
    std::cout << "Array: {10, 20, 30, 40, 50}, Target: 10 -> Index: " << linear_search(arr1, size1, target1) << std::endl;

    // Case 2: Target found in middle
    int arr2[] = {5, 15, 25};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int target2 = 15;
    std::cout << "Array: {5, 15, 25}, Target: 15 -> Index: " << linear_search(arr2, size2, target2) << std::endl;

    // Case 3: Empty array
    int arr3[] = {};
    int size3 = 0;
    int target3 = 100;
    std::cout << "Array: {}, Target: 100 -> Index: " << linear_search(arr3, size3, target3) << std::endl;

    // Case 4: Target not found
    int arr4[] = {7, 8, 9};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    int target4 = 10;
    std::cout << "Array: {7, 8, 9}, Target: 10 -> Index: " << linear_search(arr4, size4, target4) << std::endl;

    // Case 5: Target at end
    int arr5[] = {1, 2, 3, 4};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    int target5 = 4;
    std::cout << "Array: {1, 2, 3, 4}, Target: 4 -> Index: " << linear_search(arr5, size5, target5) << std::endl;

    // Case 6: Array with duplicates, target found at first occurrence
    int arr6[] = {10, 20, 10, 30};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    int target6 = 10;
    std::cout << "Array: {10, 20, 10, 30}, Target: 10 -> Index: " << linear_search(arr6, size6, target6) << std::endl;

    // Case 7: Single element array, target found
    int arr7[] = {99};
    int size7 = sizeof(arr7) / sizeof(arr7[0]);
    int target7 = 99;
    std::cout << "Array: {99}, Target: 99 -> Index: " << linear_search(arr7, size7, target7) << std::endl;

    // Case 8: Single element array, target not found
    int arr8[] = {99};
    int size8 = sizeof(arr8) / sizeof(arr8[0]);
    int target8 = 100;
    std::cout << "Array: {99}, Target: 100 -> Index: " << linear_search(arr8, size8, target8) << std::endl;

    return 0;
}