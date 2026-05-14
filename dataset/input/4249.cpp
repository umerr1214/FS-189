#include <iostream>

// Function with robustness issue: off-by-one error in loop condition.
// It fails to check the last element of the array.
int linear_search(int* arr, int size, int target) {
    // Robustness issue: The loop condition 'i < size - 1' causes the function
    // to skip checking the last element of the array (at index 'size - 1').
    // This leads to incorrect results if the target is the last element or
    // the only element in a non-empty array.
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::cout << "--- Testing Robustness Issue (off-by-one) ---" << std::endl;

    // Case 1: Target in middle - works correctly
    int arr1[] = {10, 20, 30, 40, 50};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int target1 = 30;
    std::cout << "Array: {10, 20, 30, 40, 50}, Target: 30 -> Index: " << linear_search(arr1, size1, target1) << std::endl;

    // Case 2: Target at end - fails (robustness issue)
    int arr2[] = {5, 15, 25};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int target2 = 25;
    std::cout << "Array: {5, 15, 25}, Target: 25 -> Index: " << linear_search(arr2, size2, target2) << std::endl;

    // Case 3: Empty array - works correctly (loop doesn't run)
    int arr3[] = {};
    int size3 = 0;
    int target3 = 100;
    std::cout << "Array: {}, Target: 100 -> Index: " << linear_search(arr3, size3, target3) << std::endl;

    // Case 4: Single element array, target found - fails (robustness issue)
    int arr4[] = {7};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    int target4 = 7;
    std::cout << "Array: {7}, Target: 7 -> Index: " << linear_search(arr4, size4, target4) << std::endl;

    // Case 5: Single element array, target not found - works correctly (loop doesn't run, returns -1)
    int arr5[] = {7};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    int target5 = 8;
    std::cout << "Array: {7}, Target: 8 -> Index: " << linear_search(arr5, size5, target5) << std::endl;

    // Case 6: Target not found in a larger array (where it would be in the last position)
    int arr6[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    int target6 = 10;
    std::cout << "Array: {1..10}, Target: 10 -> Index: " << linear_search(arr6, size6, target6) << std::endl;

    // Case 7: Target at beginning - works correctly
    int arr7[] = {10, 20, 30};
    int size7 = sizeof(arr7) / sizeof(arr7[0]);
    int target7 = 10;
    std::cout << "Array: {10, 20, 30}, Target: 10 -> Index: " << linear_search(arr7, size7, target7) << std::endl;

    return 0;
}