#include <iostream>

int linearSearch(int arr[], int size, int target) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            found = true; // Target found, but its index is not stored
        }
    }
    if (found) {
        return 0; // Logical Error: Always returns 0 if target is found anywhere
    } else {
        return -1;
    }
}

int main() {
    int arr1[] = {10, 20, 30, 40, 50};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Target 30 in arr1: " << linearSearch(arr1, size1, 30) << std::endl; // Expected: 2, Actual: 0
    std::cout << "Target 10 in arr1: " << linearSearch(arr1, size1, 10) << std::endl; // Expected: 0, Actual: 0 (Correct by chance)

    int arr2[] = {5, 15, 25};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Target 5 in arr2: " << linearSearch(arr2, size2, 5) << std::endl;   // Expected: 0, Actual: 0 (Correct by chance)
    std::cout << "Target 15 in arr2: " << linearSearch(arr2, size2, 15) << std::endl; // Expected: 1, Actual: 0
    std::cout << "Target 10 in arr2: " << linearSearch(arr2, size2, 10) << std::endl; // Expected: -1, Actual: -1 (Correct)

    int arr3[] = {};
    int size3 = 0;
    std::cout << "Target 10 in empty arr3: " << linearSearch(arr3, size3, 10) << std::endl; // Expected: -1, Actual: -1 (Correct)

    return 0;
}