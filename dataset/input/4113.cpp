#include <iostream>
#include <algorithm> // For std::swap

// Correct and efficient in-place array reversal function
void reverseArray(int arr[], int size) {
    int left = 0;
    int right = size - 1;

    // Use two pointers, one from the beginning and one from the end,
    // swapping elements until they meet or cross.
    while (left < right) {
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