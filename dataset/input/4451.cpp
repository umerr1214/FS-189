#include <iostream>
#include <vector>
#include <numeric> // For std::iota

// Logical error: The loop condition is off-by-one, causing the last element to be missed.
void initializeWithDefaults(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) { // Should be i < size
        arr[i] = -1;
    }
}

int main() {
    int arr1[5];
    std::iota(arr1, arr1 + 5, 1); // Initialize to {1, 2, 3, 4, 5}
    initializeWithDefaults(arr1, 5);
    std::cout << "arr1: [";
    for (int i = 0; i < 5; ++i) {
        std::cout << arr1[i] << (i < 4 ? ", " : "");
    }
    std::cout << "]" << std::endl; // Expected: [-1, -1, -1, -1, -1], Actual: [-1, -1, -1, -1, 5]

    int arr2[3];
    std::iota(arr2, arr2 + 3, 10); // Initialize to {10, 20, 30}
    initializeWithDefaults(arr2, 3);
    std::cout << "arr2: [";
    for (int i = 0; i < 3; ++i) {
        std::cout << arr2[i] << (i < 2 ? ", " : "");
    }
    std::cout << "]" << std::endl; // Expected: [-1, -1, -1], Actual: [-1, -1, 30]

    int arr3[1];
    std::iota(arr3, arr3 + 1, 100); // Initialize to {100}
    initializeWithDefaults(arr3, 1);
    std::cout << "arr3: [";
    for (int i = 0; i < 1; ++i) {
        std::cout << arr3[i] << (i < 0 ? ", " : "");
    }
    std::cout << "]" << std::endl; // Expected: [-1], Actual: [100]

    int arr4[0];
    initializeWithDefaults(arr4, 0);
    std::cout << "arr4: []" << std::endl; // Expected: [], Actual: [] (correct for size 0, as loop doesn't run)

    return 0;
}