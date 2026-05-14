#include <iostream>
#include <limits> // For std::numeric_limits

int findMin(int arr[], int size) {
    if (size <= 0) {
        return std::numeric_limits<int>::max();
    }
    int minVal = 0; // Logical error: Initializing minVal to 0 instead of arr[0] or std::numeric_limits<int>::max()
    for (int i = 0; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int main() {
    int arr1[] = {5, 2, 9, 1, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Min in arr1: " << findMin(arr1, size1) << std::endl; // Expected: 1, Actual: 0 (since all elements are positive and > 0)

    int arr2[] = {-10, -5, -20};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Min in arr2: " << findMin(arr2, size2) << std::endl; // Expected: -20, Actual: -20 (coincidentally correct as -20 < 0)

    int arr3[] = {0};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Min in arr3: " << findMin(arr3, size3) << std::endl; // Expected: 0, Actual: 0 (coincidentally correct)

    int arr4[] = {10, 20, 30};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    std::cout << "Min in arr4: " << findMin(arr4, size4) << std::endl; // Expected: 10, Actual: 0

    return 0;
}