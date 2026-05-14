#include <iostream>
#include <vector>
#include <numeric> // For std::iota

// Function to rotate an array one position to the right
// Readability / Efficiency Issue: Uses an auxiliary array, leading to O(N) space complexity.
// While correct, an in-place O(1) space solution is more efficient.
void rotateArrayRight(int arr[], int size) {
    if (size <= 1) {
        return; // No rotation needed for 0 or 1 element
    }

    // Create a temporary array to store the rotated elements
    // This uses O(N) extra space, which is inefficient for this problem.
    int* tempArr = new int[size];

    // The last element moves to the first position
    tempArr[0] = arr[size - 1];

    // Shift the remaining elements one position to the right
    for (int i = 0; i < size - 1; ++i) {
        tempArr[i + 1] = arr[i];
    }

    // Copy elements back to the original array
    for (int i = 0; i < size; ++i) {
        arr[i] = tempArr[i];
    }

    delete[] tempArr; // Clean up dynamically allocated memory
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
    std::cout << "Demonstrating rotateArrayRight function with readability/efficiency issue.\n";

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

    // Test Case 3: Empty array
    int arr3[] = {};
    int size3 = 0;
    std::cout << "Original array: ";
    printArray(arr3, size3);
    std::cout << "\n";
    rotateArrayRight(arr3, size3);
    std::cout << "Rotated array:  ";
    printArray(arr3, size3);
    std::cout << "\n\n";

    // Test Case 4: Larger array
    int arr4[10];
    std::iota(arr4, arr4 + 10, 100); // Fills with 100, 101, ..., 109
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    std::cout << "Original array: ";
    printArray(arr4, size4);
    std::cout << "\n";
    rotateArrayRight(arr4, size4);
    std::cout << "Rotated array:  ";
    printArray(arr4, size4);
    std::cout << "\n\n";

    return 0;
}