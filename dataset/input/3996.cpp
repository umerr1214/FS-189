#include <iostream>

// Function to find the maximum element using pointer arithmetic
int* findMaxPointer(int* arr, int size) {
    if (size <= 0) {
        return nullptr; // Handle empty or invalid array
    }

    int* maxPtr = arr; // Initialize maxPtr to the first element
    // Semantic Error: The loop condition `i <= size` causes an out-of-bounds access
    // when `i` becomes equal to `size`. This attempts to read `arr[size]`,
    // which is beyond the allocated array boundary, leading to undefined behavior.
    for (int i = 0; i <= size; ++i) { // Should be i < size
        if (*(arr + i) > *maxPtr) {
            maxPtr = (arr + i);
        }
    }
    return maxPtr;
}

int main() {
    int arr1[] = {10, 5, 20, 15, 30, 25};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int* maxElementPtr1 = findMaxPointer(arr1, size1);
    std::cout << "Array 1: {10, 5, 20, 15, 30, 25}" << std::endl;
    if (maxElementPtr1 != nullptr) {
        std::cout << "Max element (semantic error, potentially incorrect/crash): " << *maxElementPtr1 << std::endl;
    } else {
        std::cout << "Array 1 is empty or invalid." << std::endl;
    }

    int arr2[] = {1, 2, 3};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int* maxElementPtr2 = findMaxPointer(arr2, size2);
    std::cout << "Array 2: {1, 2, 3}" << std::endl;
    if (maxElementPtr2 != nullptr) {
        std::cout << "Max element (semantic error, potentially incorrect/crash): " << *maxElementPtr2 << std::endl;
    } else {
        std::cout << "Array 2 is empty or invalid." << std::endl;
    }

    int arr3[] = {7};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int* maxElementPtr3 = findMaxPointer(arr3, size3);
    std::cout << "Array 3: {7}" << std::endl;
    if (maxElementPtr3 != nullptr) {
        std::cout << "Max element (semantic error, potentially incorrect/crash): " << *maxElementPtr3 << std::endl;
    } else {
        std::cout << "Array 3 is empty or invalid." << std::endl;
    }

    int arr4_data[] = {};
    int size4 = 0;
    int* maxElementPtr4 = findMaxPointer(arr4_data, size4);
    std::cout << "Array 4: {}" << std::endl;
    if (maxElementPtr4 != nullptr) {
        std::cout << "Max element (semantic error): " << *maxElementPtr4 << std::endl;
    } else {
        std::cout << "Array 4 is empty or invalid (correctly handled)." << std::endl;
    }

    return 0;
}