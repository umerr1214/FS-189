#include <iostream>
#include <vector>
#include <numeric> // For std::iota, if needed for complex test cases

// Robustness Issue: This function does not explicitly handle negative 'size' values.
// While the loop condition `i < size / 2` prevents out-of-bounds access for negative `size` (as the loop won't run),
// a robust function should validate input parameters and ideally report an error or throw an exception for invalid sizes,
// rather than silently doing nothing. This omission can lead to unexpected behavior in larger systems.
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        // Standard swap using a temporary variable
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i == size - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Demonstrating reverseArray function:" << std::endl;

    // Test case 1: Normal array
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Original array 1: ";
    printArray(arr1, size1);
    reverseArray(arr1, size1);
    std::cout << "Reversed array 1: ";
    printArray(arr1, size1);
    std::cout << std::endl;

    // Test case 2: Empty array (size = 0)
    int arr2[] = {};
    int size2 = 0;
    std::cout << "Original array 2 (empty): ";
    printArray(arr2, size2);
    reverseArray(arr2, size2);
    std::cout << "Reversed array 2 (empty): ";
    printArray(arr2, size2);
    std::cout << std::endl;

    // Test case 3: Single element array (size = 1)
    int arr3[] = {100};
    int size3 = 1;
    std::cout << "Original array 3 (single element): ";
    printArray(arr3, size3);
    reverseArray(arr3, size3);
    std::cout << "Reversed array 3 (single element): ";
    printArray(arr3, size3);
    std::cout << std::endl;

    // Test case 4: Negative size (Robustness Issue - silent failure)
    // The function silently does nothing for negative sizes.
    // A robust function would validate input (e.g., throw exception, print error).
    int arr4[] = {9, 8, 7};
    int size4 = -3; // Invalid size
    std::cout << "Original array 4 (with invalid negative size): ";
    printArray(arr4, 3); // Print with actual size to show content
    reverseArray(arr4, size4);
    std::cout << "Reversed array 4 (after calling with negative size): ";
    printArray(arr4, 3); // Print with actual size
    std::cout << "(Expected: no change, Actual: no change, but no error reported for invalid size)" << std::endl;
    std::cout << std::endl;

    return 0;
}