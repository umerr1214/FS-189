#include <iostream> // Required for std::cout, std::endl

// Function to print the array (helper)
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i == size - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

// Function to rotate an array one position to the right
void rotateArrayRight(int arr[], int size) {
    if (size <= 1) {
        return; // No rotation needed for 0 or 1 element
    }
    int lastElement = arr[size - 1]; // Store the last element

    // SEMANTIC ERROR: Out-of-bounds array write.
    // The loop iterates from 'size - 1' down to '0' (inclusive).
    // In the first iteration (i = size - 1), 'arr[i + 1]' attempts to access 'arr[size]',
    // which is beyond the allocated bounds of the array. This leads to undefined behavior,
    // potentially causing a crash or memory corruption.
    for (int i = size - 1; i >= 0; --i) { 
        arr[i + 1] = arr[i]; // Accesses arr[size] when i is size-1
    }
    arr[0] = lastElement;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    std::cout << "Original array: ";
    printArray(arr1, size1);

    rotateArrayRight(arr1, size1); // This call will likely cause a crash or corrupt memory

    std::cout << "Rotated array: ";
    printArray(arr1, size1);

    int arr2[] = {10, 20};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Original array: ";
    printArray(arr2, size2);
    rotateArrayRight(arr2, size2);
    std::cout << "Rotated array: ";
    printArray(arr2, size2);

    return 0;
}