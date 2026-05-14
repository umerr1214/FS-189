#include <iostream>
#include <vector> // This include is not strictly needed for int arr[] but often used with vector

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Function to reverse an array in-place
void reverseArray(int arr[], int size) {
    int left = 0;
    int right = size - 1;
    while (left < right) {
        // Swap elements
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        // Move pointers inward
        left++;
        right--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: " // Missing semicolon here
    printArray(arr, size);

    reverseArray(arr, size);

    std::cout << "Reversed array: ";
    printArray(arr, size);

    return 0;
}