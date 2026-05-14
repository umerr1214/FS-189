#include <iostream>

void initializeWithDefaults(int* arr, int size) {
    // Robustness issue: This function does not check if 'arr' is a nullptr.
    // If 'arr' is nullptr and 'size' is greater than 0, dereferencing arr[i]
    // will lead to a segmentation fault or undefined behavior.
    for (int i = 0; i < size; ++i) {
        arr[i] = -1;
    }
}

int main() {
    // This main function demonstrates the usage, but the robustness issue
    // for a nullptr input is not directly triggered here to prevent a crash
    // in the example program itself. The issue is documented in the JSON.

    // Test Case 1: Normal array
    int arr1[5] = {1, 2, 3, 4, 5};
    int size1 = 5;
    initializeWithDefaults(arr1, size1);
    std::cout << "Array 1 after initialization: [";
    for (int i = 0; i < size1; ++i) {
        std::cout << arr1[i] << (i == size1 - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl; // Expected: [-1, -1, -1, -1, -1]

    // Test Case 2: Empty array
    int arr2[0]; // C-style array of size 0, valid but cannot be dereferenced
    int size2 = 0;
    initializeWithDefaults(arr2, size2); // Loop won't run, no issue
    std::cout << "Array 2 after initialization (size 0): []" << std::endl; // Expected: []

    // Test Case 3: Single element array
    int arr3[1] = {100};
    int size3 = 1;
    initializeWithDefaults(arr3, size3);
    std::cout << "Array 3 after initialization: [";
    for (int i = 0; i < size3; ++i) {
        std::cout << arr3[i] << (i == size3 - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl; // Expected: [-1]

    // A call like initializeWithDefaults(nullptr, 5) would cause a crash here.
    // This program avoids that call to ensure it runs to completion for demonstration.

    return 0;
}