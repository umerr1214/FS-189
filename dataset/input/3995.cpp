#include <iostream>

// Function intended to find the maximum element, but contains a logical error
int* findMaxPointer(int* arr, int size) {
    if (size <= 0) {
        return nullptr; // Handle empty or invalid array
    }

    int* maxPtr = arr; // Initialize maxPtr to the first element
    for (int i = 1; i < size; ++i) {
        // Logical Error: Compares if current element is LESS than *maxPtr,
        // effectively finding the minimum element instead of the maximum.
        if (*(arr + i) < *maxPtr) { // Should be > for finding maximum
            maxPtr = (arr + i); // Updates maxPtr to point to a smaller element
        }
    }
    return maxPtr; // Returns pointer to the minimum element found
}

int main() {
    int arr1[] = {10, 5, 20, 15, 30, 25};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int* maxElementPtr1 = findMaxPointer(arr1, size1);
    std::cout << "Array 1: {10, 5, 20, 15, 30, 25}" << std::endl;
    if (maxElementPtr1 != nullptr) {
        std::cout << "Expected max: 30, Found (logical error): " << *maxElementPtr1 << std::endl;
    } else {
        std::cout << "Array 1 is empty or invalid." << std::endl;
    }

    int arr2[] = {-5, -1, -10, -2};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int* maxElementPtr2 = findMaxPointer(arr2, size2);
    std::cout << "Array 2: {-5, -1, -10, -2}" << std::endl;
    if (maxElementPtr2 != nullptr) {
        std::cout << "Expected max: -1, Found (logical error): " << *maxElementPtr2 << std::endl;
    } else {
        std::cout << "Array 2 is empty or invalid." << std::endl;
    }

    int arr3[] = {7};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int* maxElementPtr3 = findMaxPointer(arr3, size3);
    std::cout << "Array 3: {7}" << std::endl;
    if (maxElementPtr3 != nullptr) {
        std::cout << "Expected max: 7, Found (correct by chance for single element): " << *maxElementPtr3 << std::endl;
    } else {
        std::cout << "Array 3 is empty or invalid." << std::endl;
    }

    int arr4_data[] = {};
    int size4 = 0;
    int* maxElementPtr4 = findMaxPointer(arr4_data, size4);
    std::cout << "Array 4: {}" << std::endl;
    if (maxElementPtr4 != nullptr) {
        std::cout << "Expected max: (nullptr), Found: " << *maxElementPtr4 << std::endl;
    } else {
        std::cout << "Array 4 is empty or invalid (correctly handled)." << std::endl;
    }

    return 0;
}