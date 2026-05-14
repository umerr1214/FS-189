#include <iostream>
#include <limits> // For std::numeric_limits

int findMin(int arr[], int size) {
    if (size <= 0) {
        return std::numeric_limits<int>::max();
    }
    int minVal = arr[0];
    for (int i = 0; i <= size; ++i) { // Semantic error: loop condition should be i < size, not i <= size
        // This loop accesses arr[size], which is an out-of-bounds access,
        // leading to undefined behavior at runtime.
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int main() {
    int arr1[] = {5, 2, 9, 1, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Min in arr1: " << findMin(arr1, size1) << std::endl; // Expected: 1, Actual: Undefined behavior

    int arr2[] = {-10, -5, -20};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Min in arr2: " << findMin(arr2, size2) << std::endl; // Expected: -20, Actual: Undefined behavior

    int arr3[] = {0};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Min in arr3: " << findMin(arr3, size3) << std::endl; // Expected: 0, Actual: Undefined behavior

    return 0;
}