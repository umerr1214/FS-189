#include <iostream>

// Function to find the maximum element using pointer arithmetic
int* findMaxPointer(int* arr, int size) {
    if (size <= 0) {
        return nullptr; // Handle empty or invalid array
    }

    int* maxPtr = arr; // Initialize maxPtr to the first element
    for (int i = 1; i < size; ++i) {
        if (*(arr + i) > *maxPtr) { // Compare current element with element pointed by maxPtr
            maxPtr = (arr + i); // Update maxPtr if a larger element is found
        }
    }
    return maxPtr;
}

int main() {
    int arr[] = {10, 5, 20, 15, 30, 25};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Syntax Error: Missing semicolon after the function call
    int* maxElementPtr = findMaxPointer(arr, size) 

    if (maxElementPtr != nullptr) {
        std::cout << "The maximum element is: " << *maxElementPtr << std::endl;
    } else {
        std::cout << "Array is empty or invalid." << std::endl;
    }

    return 0;
}