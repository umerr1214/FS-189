#include <iostream>

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Function to reverse an array in-place (with a logical error)
void reverseArray(int arr[], int size) {
    int left = 0;
    // Logical Error: Instead of swapping with 'right', it swaps with the next element
    // and only for half the array, resulting in elements shifting, not reversing.
    while (left < size / 2) {
        // This will swap adjacent elements in the first half of the array
        // For example, {1,2,3,4,5} -> {2,1,4,3,5}
        int temp = arr[left];
        arr[left] = arr[left + 1]; // Swaps with next element
        arr[left + 1] = temp;
        left++;
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