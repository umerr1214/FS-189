#include <iostream>
#include <algorithm> // For std::swap

// Function with an Efficiency Issue: O(N^2) complexity
void reverseArray(int arr[], int size) {
    if (size <= 1) {
        return; // Nothing to reverse or invalid size
    }

    // This implementation repeatedly takes the last element and inserts it at the current front,
    // shifting all intermediate elements one position to the right.
    // This results in O(N^2) time complexity.
    for (int i = 0; i < size; ++i) {
        int last_element = arr[size - 1]; // Store the last element
        // Shift elements from size-1 down to i+1 one position to the right
        for (int j = size - 1; j > i; --j) {
            arr[j] = arr[j - 1];
        }
        arr[i] = last_element; // Place the stored last element at the current front
    }
}

// Helper function to print the array
void printArray(const int arr[], int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i == size - 1 ? "" : ", ");
    }
    std::cout << "]";
}

int main() {
    // Test case 1 (odd size)
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Original array 1: ";
    printArray(arr1, size1);
    std::cout << std::endl;
    reverseArray(arr1, size1);
    std::cout << "Reversed array 1: ";
    printArray(arr1, size1);
    std::cout << std::endl << std::endl;

    // Test case 2 (even size)
    int arr2[] = {10, 20, 30, 40};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Original array 2: ";
    printArray(arr2, size2);
    std::cout << std::endl;
    reverseArray(arr2, size2);
    std::cout << "Reversed array 2: ";
    printArray(arr2, size2);
    std::cout << std::endl << std::endl;

    // Test case 3 (single element)
    int arr3[] = {100};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Original array 3: ";
    printArray(arr3, size3);
    std::cout << std::endl;
    reverseArray(arr3, size3);
    std::cout << "Reversed array 3: ";
    printArray(arr3, size3);
    std::cout << std::endl << std::endl;

    // Test case 4 (empty array)
    int arr4[] = {};
    int size4 = 0;
    std::cout << "Original array 4: ";
    printArray(arr4, size4);
    std::cout << std::endl;
    reverseArray(arr4, size4);
    std::cout << "Reversed array 4: ";
    printArray(arr4, size4);
    std::cout << std::endl << std::endl;

    return 0;
}