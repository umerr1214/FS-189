#include <iostream>
#include <algorithm> // For std::swap

// Function with a Robustness Issue: Potential out-of-bounds access for size=1
void reverseArray(int arr[], int size) {
    int left = 0;
    int right = size; // Incorrect initialization: should be size - 1

    while (left < right) {
        // For size=1, left=0, right=1. This will attempt to access arr[1] which is out-of-bounds.
        std::swap(arr[left], arr[right]);
        left++;
        right--;
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

    // Test case 3 (single element - triggers robustness issue)
    int arr3[] = {100};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Original array 3: ";
    printArray(arr3, size3);
    std::cout << std::endl;
    // This call might lead to a runtime error (e.g., segmentation fault) due to out-of-bounds access
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