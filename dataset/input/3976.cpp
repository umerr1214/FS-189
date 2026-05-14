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
    // SYNTAX ERROR: Missing semicolon after variable declaration
    int lastElement = arr[size - 1] 
    for (int i = size - 1; i > 0; --i) {
        arr[i] = arr[i - 1]; // Shift elements to the right
    }
    arr[0] = lastElement; // Place the stored last element at the first position
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    std::cout << "Original array: ";
    printArray(arr1, size1);

    rotateArrayRight(arr1, size1);

    std::cout << "Rotated array: ";
    printArray(arr1, size1); // Expected: 5 1 2 3 4

    int arr2[] = {10};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Original array: ";
    printArray(arr2, size2);
    rotateArrayRight(arr2, size2);
    std::cout << "Rotated array: ";
    printArray(arr2, size2); // Expected: 10

    int arr3[] = {1, 2};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Original array: ";
    printArray(arr3, size3);
    rotateArrayRight(arr3, size3);
    std::cout << "Rotated array: ";
    printArray(arr3, size3); // Expected: 2 1

    return 0;
}