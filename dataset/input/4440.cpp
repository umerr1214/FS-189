#include <iostream>

int linearSearch(int arr[], int size, int target) {
    // Semantic Error: The loop condition `i <= size` allows 'i' to reach 'size'.
    // This results in an out-of-bounds access when `arr[i]` is evaluated with `i == size`.
    for (int i = 0; i <= size; ++i) {
        if (arr[i] == target) { // Accesses arr[size] when target is not found or array is empty
            return i;
        }
    }
    return -1;
}

int main() {
    int arr1[] = {10, 20, 30, 40, 50}; // size = 5, valid indices 0-4
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Target 30 in arr1: " << linearSearch(arr1, size1, 30) << std::endl; // Expected: 2, might work
    std::cout << "Target 60 in arr1: " << linearSearch(arr1, size1, 60) << std::endl; // Expected: -1, will trigger Undefined Behavior

    int arr2[] = {5, 15, 25}; // size = 3, valid indices 0-2
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Target 10 in arr2: " << linearSearch(arr2, size2, 10) << std::endl; // Expected: -1, will trigger Undefined Behavior

    int arr3[] = {}; // size = 0
    int size3 = 0;
    std::cout << "Target 10 in empty arr3: " << linearSearch(arr3, size3, 10) << std::endl; // Expected: -1, will trigger Undefined Behavior immediately (accesses arr[0] when size is 0)

    return 0;
}