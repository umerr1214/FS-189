#include <iostream>
#include <algorithm> // Not strictly necessary for this implementation, but useful for std::fill

void initializeWithDefaults(int* arr, int size) {
    // Correct Version:
    // This function is robust, readable, and efficient.
    // 1. It handles nullptr gracefully by returning early.
    // 2. It handles non-positive sizes (including size=0) correctly.
    // 3. It uses a standard 'for' loop for iteration, which is clear and efficient.
    
    if (arr == nullptr || size <= 0) {
        // No operation needed for a null array pointer or a non-positive size.
        // For size=0, the loop below would naturally not run, but checking 'arr == nullptr'
        // is crucial for robustness.
        return;
    }

    for (int i = 0; i < size; ++i) {
        arr[i] = -1;
    }

    // Alternative correct and idiomatic implementation using std::fill:
    // std::fill(arr, arr + size, -1);
}

int main() {
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
    int arr2[0];
    int size2 = 0;
    initializeWithDefaults(arr2, size2);
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

    // Test Case 4: Nullptr array (robustness check)
    int* arr4 = nullptr;
    int size4 = 3;
    std::cout << "Calling initializeWithDefaults with nullptr array and size " << size4 << std::endl;
    initializeWithDefaults(arr4, size4); // Should handle gracefully without crashing
    std::cout << "Expected: No crash, no change to non-existent array. Actual: No crash." << std::endl;
    // No array to print for nullptr

    // Test Case 5: Negative size (should also be handled gracefully)
    int arr5[2] = {1, 2};
    int size5 = -5;
    std::cout << "Calling initializeWithDefaults with negative size " << size5 << std::endl;
    initializeWithDefaults(arr5, size5); // Should handle gracefully
    std::cout << "Array 5 after initialization with negative size: [";
    for (int i = 0; i < 2; ++i) { // Print original array to show no change
        std::cout << arr5[i] << (i == 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl; // Expected: [1, 2] (unchanged)

    return 0;
}