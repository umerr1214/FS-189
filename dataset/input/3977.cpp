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
    // LOGICAL ERROR: The last element is not stored before being overwritten.
    // After the loop, arr[size-1] will contain the original arr[size-2].
    // Then arr[0] is incorrectly set to this value.
    for (int i = size - 1; i > 0; --i) {
        arr[i] = arr[i - 1]; // Shifts elements right, arr[size-1] gets overwritten
    }
    // The original last element is lost.
    // arr[0] is incorrectly assigned the value that was *just* shifted into arr[size-1] (original arr[size-2]).
    arr[0] = arr[size - 1]; 
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    std::cout << "Original array: ";
    printArray(arr1, size1);

    rotateArrayRight(arr1, size1);

    std::cout << "Rotated array: ";
    printArray(arr1, size1); // Expected: 5 1 2 3 4. Actual: 4 1 2 3 4

    int arr2[] = {10, 20};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Original array: ";
    printArray(arr2, size2);
    rotateArrayRight(arr2, size2);
    std::cout << "Rotated array: ";
    printArray(arr2, size2); // Expected: 20 10. Actual: 10 10

    int arr3[] = {1, 2, 3};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Original array: ";
    printArray(arr3, size3);
    rotateArrayRight(arr3, size3);
    std::cout << "Rotated array: ";
    printArray(arr3, size3); // Expected: 3 1 2. Actual: 2 1 2

    return 0;
}