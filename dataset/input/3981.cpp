#include <iostream>
#include <vector>
#include <numeric> // For std::iota

// Function to rotate an array one position to the right
// Correct Version: Efficient and handles edge cases.
void rotateArrayRight(int arr[], int size) {
    if (size <= 1) {
        return; // No rotation needed for 0 or 1 element
    }

    // Store the last element
    int lastElement = arr[size - 1];

    // Shift all elements from size-2 down to 0, one position to the right
    for (int i = size - 1; i > 0; --i) {
        arr[i] = arr[i - 1];
    }

    // Place the stored last element at the first position
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
    std::cout << "Demonstrating the correct rotateArrayRight function.\n";

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

    // Test Case 5: Array with two elements
    int arr5[] = {10, 20};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    std::cout << "Original array: ";
    printArray(arr5, size5);
    std::cout << "\n";
    rotateArrayRight(arr5, size5);
    std::cout << "Rotated array:  ";
    printArray(arr5, size5);
    std::cout << "\n\n";

    return 0;
}