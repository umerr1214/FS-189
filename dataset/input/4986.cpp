#include <iostream>
#include <vector>

// Function to reverse an array in-place
void reverseArray(int arr[], int size) {
    int left = 0;
    // Semantic Error: 'right' is initialized to 'size' instead of 'size - 1'.
    // This leads to an out-of-bounds array access (arr[size]) when 'arr[right]'
    // is accessed in the first iteration, resulting in undefined behavior or a crash.
    int right = size; // Should be size - 1
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right]; // Accesses arr[size] which is out of bounds
        arr[right] = temp;
        left++;
        right--;
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
    reverseArray(arr1, size1); // This call will likely cause a crash or UB
    std::cout << "Reversed array 1: ";
    printArray(arr1, size1);

    int arr2[] = {10, 20};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Original array 2: ";
    printArray(arr2, size2);
    reverseArray(arr2, size2); // This call will also likely cause a crash or UB
    std::cout << "Reversed array 2: ";
    printArray(arr2, size2);

    int arr3[] = {7};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Original array 3: ";
    printArray(arr3, size3);
    reverseArray(arr3, size3); // For size 1, right becomes 1, left becomes 0. Loop condition (0 < 1) is true.
                               // arr[0] = arr[1] (out of bounds).
    std::cout << "Reversed array 3: ";
    printArray(arr3, size3);

    return 0;
}