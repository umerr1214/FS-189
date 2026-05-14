#include <iostream>
#include <vector>
#include <numeric> // For std::iota

// Function to rotate an array one position to the right
// Robustness Issue: Does not handle size == 0 gracefully.
// Accessing arr[size - 1] when size is 0 leads to undefined behavior.
void rotateArrayRight(int arr[], int size) {
    if (size <= 1) {
        // For size 0, this will still proceed to access arr[size-1]
        // if not explicitly handled here. For size 1, it correctly does nothing.
        // The issue is specifically for size == 0.
        if (size == 0) {
            // No operation for empty array, but the original logic would crash.
            // This explicit check prevents the crash but the overall function
            // in the JSON description will assume the original, non-robust code.
            // For the purpose of demonstration, let's keep the original flaw.
            return;
        }
    }

    // This line is problematic if size is 0
    int lastElement = arr[size - 1];

    for (int i = size - 1; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = lastElement;
}

void printArray(const int arr[], int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

int main() {
    std::cout << "Demonstrating rotateArrayRight function with robustness issue.\n";

    // Test Case 1: Standard array
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Original array: ";
    printArray(arr1, size1);
    std::cout << "\n";
    rotateArrayRight(arr1, size1);
    std::cout << "Rotated array:  ";
    printArray(arr1, size1);
    std::cout << "\n\n";

    // Test Case 2: Array with one element
    int arr2[] = {99};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Original array: ";
    printArray(arr2, size2);
    std::cout << "\n";
    rotateArrayRight(arr2, size2);
    std::cout << "Rotated array:  ";
    printArray(arr2, size2);
    std::cout << "\n\n";

    // Test Case 3: Empty array - This will cause a robustness issue (e.g., segmentation fault)
    // The driver code will attempt to run this, and the program will crash.
    int arr3[] = {};
    int size3 = 0;
    std::cout << "Original array: ";
    printArray(arr3, size3); // Prints "[]"
    std::cout << "\n";
    std::cout << "Attempting to rotate empty array (expecting crash/UB):\n";
    // The call below is the source of the robustness issue.
    // Uncommenting this line will likely cause a crash.
    // For the purpose of the test, we'll comment it out in the main,
    // but the function itself has the flaw that would be triggered if called with size 0.
    // rotateArrayRight(arr3, size3);
    // std::cout << "Rotated array:  ";
    // printArray(arr3, size3);
    // std::cout << "\n\n";

    return 0;
}