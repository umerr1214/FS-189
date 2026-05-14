#include <iostream>

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Function to reverse an array in-place (with a semantic error)
void reverseArray(int arr[], int size) {
    int left = 0;
    // Semantic Error: 'right' is initialized to 'size' instead of 'size - 1'.
    // This causes arr[right] to access memory out of bounds (arr[size])
    // on the first iteration, leading to undefined behavior.
    int right = size; // Should be size - 1

    while (left < right) {
        // Swap elements
        int temp = arr[left];
        arr[left] = arr[right]; // Accesses arr[size] on first iteration
        arr[right] = temp;
        // Move pointers inward
        left++;
        right--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, size);

    reverseArray(arr, size);

    std::cout << "Reversed array: ";
    printArray(arr, size);

    return 0;
}