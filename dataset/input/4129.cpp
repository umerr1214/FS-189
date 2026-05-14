#include <iostream>

// Function to find the minimum element's pointer
const int* findMinPointer(const int* arr, int size) {
    // Robustness issue: This implementation does not handle size == 0 gracefully.
    // If size is 0, attempting to access arr[0] for initialization
    // will lead to undefined behavior or a crash.
    // A robust solution would check if size > 0 and return nullptr otherwise.

    // This line specifically causes the issue if size is 0.
    // It tries to access the first element of an array that has no elements.
    const int* minPtr = &arr[0]; 

    for (int i = 1; i < size; ++i) {
        if (arr[i] < *minPtr) {
            minPtr = &arr[i];
        }
    }
    return minPtr;
}

int main() {
    std::cout << "--- Testing findMinPointer ---" << std::endl;

    // Case 1: Normal array
    int arr1[] = {5, 2, 9, 1, 7, 3};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    const int* minPtr1 = findMinPointer(arr1, size1);
    if (minPtr1 != nullptr) {
        std::cout << "Array: {5, 2, 9, 1, 7, 3}, Min value: " << *minPtr1 << std::endl; // Expected: 1
    } else {
        std::cout << "Array: {5, 2, 9, 1, 7, 3}, Error: Returned nullptr." << std::endl;
    }

    std::cout << "\n--- Demonstrating Robustness Issue (Empty Array) ---" << std::endl;
    // Case 2: Empty array - This should cause a crash due to accessing arr[0] when size is 0.
    int arr2[] = {}; 
    int size2 = 0;
    std::cout << "Attempting to find min in an empty array {}. This should lead to a crash or undefined behavior." << std::endl;
    // The call below is expected to crash the program.
    const int* minPtr2 = findMinPointer(arr2, size2); 

    // The following lines might not be reached if a crash occurs.
    if (minPtr2 != nullptr) {
        std::cout << "Min value in empty array: " << *minPtr2 << std::endl;
    } else {
        std::cout << "Empty array handled (incorrectly by function logic for size=0, should crash)." << std::endl;
    }

    return 0;
}