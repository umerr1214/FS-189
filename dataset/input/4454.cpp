#include <iostream>

void initializeWithDefaults(int* arr, int size) {
    // Readability / Efficiency Issue:
    // This implementation uses a while loop with explicit pointer arithmetic.
    // While functionally correct, it is generally considered less readable
    // and less idiomatic C++ for array iteration compared to a simple 'for' loop
    // with an index, or using standard library algorithms like std::fill.
    // There is no significant efficiency gain, and potential for off-by-one errors
    // or incorrect pointer manipulation is higher than with a simple indexed loop.
    
    int* current = arr;
    int* end = arr + size;

    while (current < end) {
        *current = -1;
        current++;
    }
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

    return 0;
}