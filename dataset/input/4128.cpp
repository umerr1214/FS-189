#include <iostream>

const int* findMinPointer(const int* arr, int size) {
    // Semantic Error: Initializes minPtr by dereferencing arr[0] without checking
    // if size is greater than 0 or if arr is a null pointer.
    // This will lead to undefined behavior (e.g., out-of-bounds access or null pointer dereference)
    // if an empty array or null array pointer is passed.
    const int* minPtr = &arr[0]; // Potential Undefined Behavior

    for (int i = 1; i < size; ++i) {
        if (arr[i] < *minPtr) {
            minPtr = &arr[i];
        }
    }
    return minPtr;
}

int main() {
    int myArray[] = {5, 2, 9, 1, 7};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    const int* minValPtr = findMinPointer(myArray, size);

    if (minValPtr != nullptr) {
        std::cout << "Minimum value: " << *minValPtr << std::endl; // Correctly prints 1
    } else {
        std::cout << "Array is empty or null." << std::endl;
    }

    std::cout << "--- Testing with empty array ---" << std::endl;
    int emptyArray[] = {};
    int emptySize = 0;
    // Calling findMinPointer with an empty array will cause UB at &arr[0]
    const int* minValPtrEmpty = findMinPointer(emptyArray, emptySize);

    // If the program hasn't crashed yet, attempting to print will also be UB
    if (minValPtrEmpty != nullptr) {
        std::cout << "Minimum value of empty array: " << *minValPtrEmpty << std::endl;
    } else {
        std::cout << "Empty array is null." << std::endl;
    }

    std::cout << "--- Testing with null array pointer ---" << std::endl;
    const int* nullArr = nullptr;
    int nullArrSize = 5; // Size is irrelevant if arr is null
    // Calling findMinPointer with a null pointer will cause UB at &arr[0]
    const int* minValPtrNull = findMinPointer(nullArr, nullArrSize);

    if (minValPtrNull != nullptr) {
        std::cout << "Minimum value of null array: " << *minValPtrNull << std::endl;
    } else {
        std::cout << "Null array is null." << std::endl; // This branch may or may not be taken depending on UB
    }

    return 0;
}