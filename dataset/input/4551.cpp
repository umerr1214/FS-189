#include <iostream>
#include <algorithm> // For std::swap
#include <vector>
#include <numeric>

// Correct Version:
// This function correctly reverses an array in-place using a two-pointer approach.
// It uses clear variable names, efficient swapping with `std::swap`, and handles edge cases
// like empty arrays, single-element arrays, and invalid negative sizes robustly.
void reverseArray(int arr[], int size) {
    // Robustness: Handle invalid size gracefully
    if (size < 0) {
        std::cerr << "Error: Array size cannot be negative." << std::endl;
        return;
    }
    // No explicit check for size <= 1 is needed, as the loop condition `left < right`
    // correctly handles these cases by not executing any swaps.

    int left = 0;
    int right = size - 1;

    while (left < right) {
        // Use std::swap for clear, efficient, and safe swapping
        std::swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i == size - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Demonstrating reverseArray function (Correct Version):" << std::endl;

    // Test case 1: Normal array (odd size)
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Original array 1: ";
    printArray(arr1, size1);
    reverseArray(arr1, size1);
    std::cout << "Reversed array 1: ";
    printArray(arr1, size1);
    std::cout << std::endl;

    // Test case 2: Normal array (even size)
    int arr2[] = {10, 20, 30, 40};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Original array 2: ";
    printArray(arr2, size2);
    reverseArray(arr2, size2);
    std::cout << "Reversed array 2: ";
    printArray(arr2, size2);
    std::cout << std::endl;

    // Test case 3: Empty array (size = 0)
    int arr3[] = {};
    int size3 = 0;
    std::cout << "Original array 3 (empty): ";
    printArray(arr3, size3);
    reverseArray(arr3, size3);
    std::cout << "Reversed array 3 (empty): ";
    printArray(arr3, size3);
    std::cout << std::endl;

    // Test case 4: Single element array (size = 1)
    int arr4[] = {100};
    int size4 = 1;
    std::cout << "Original array 4 (single element): ";
    printArray(arr4, size4);
    reverseArray(arr4, size4);
    std::cout << "Reversed array 4 (single element): ";
    printArray(arr4, size4);
    std::cout << std::endl;

    // Test case 5: Negative size (Robustness handled)
    int arr5[] = {9, 8, 7};
    int size5 = -3; // Invalid size
    std::cout << "Original array 5 (with invalid negative size): ";
    printArray(arr5, 3); // Print with actual size to show content
    reverseArray(arr5, size5); // This call will print an error message to stderr
    std::cout << "Reversed array 5 (after calling with negative size): ";
    printArray(arr5, 3); // Print with actual size
    std::cout << std::endl;

    return 0;
}