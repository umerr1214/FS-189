#include <iostream>
#include <vector>

// Function to reverse an array in-place
void reverseArray(int arr[], int size) {
    // Logical Error: The loop iterates through the entire array,
    // effectively swapping each element twice (e.g., arr[0] with arr[size-1],
    // then later arr[size-1] with arr[0]), resulting in the original array.
    for (int i = 0; i < size; ++i) { // Should be i < size / 2
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

// Helper function to print an array
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i == size - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Original array 1: ";
    printArray(arr1, size1);
    reverseArray(arr1, size1);
    std::cout << "Reversed array 1: ";
    printArray(arr1, size1); // Expected: 5 4 3 2 1, Actual: 1 2 3 4 5

    int arr2[] = {10, 20, 30, 40};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Original array 2: ";
    printArray(arr2, size2);
    reverseArray(arr2, size2);
    std::cout << "Reversed array 2: ";
    printArray(arr2, size2); // Expected: 40 30 20 10, Actual: 10 20 30 40

    int arr3[] = {7};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Original array 3: ";
    printArray(arr3, size3);
    reverseArray(arr3, size3);
    std::cout << "Reversed array 3: ";
    printArray(arr3, size3); // Expected: 7, Actual: 7 (correct for single element, but for wrong reason)

    return 0;
}