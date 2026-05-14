#include <iostream>

const int* findMinPointer(const int* arr, int size) {
    if (arr == nullptr || size <= 0) {
        return nullptr;
    }
    const int* minPtr = arr; // Assume first element is min
    for (int i = 1; i < size; ++i) {
        if (arr[i] < *minPtr) {
            minPtr = &arr[i];
        }
    }
    // Logical Error: The function returns a pointer to the beginning of the array 'arr'
    // instead of the pointer to the actual minimum element 'minPtr'.
    return arr;
}

int main() {
    int myArray[] = {5, 2, 9, 1, 7}; // Minimum value is 1
    int size = sizeof(myArray) / sizeof(myArray[0]);

    const int* minValPtr = findMinPointer(myArray, size);

    if (minValPtr != nullptr) {
        std::cout << "Minimum value: " << *minValPtr << std::endl;
    } else {
        std::cout << "Array is empty or null." << std::endl;
    }

    // Another test case where the first element is the minimum
    int myArray2[] = {10, 2, 30}; // Minimum value is 2
    int size2 = sizeof(myArray2) / sizeof(myArray2[0]);
    const int* minValPtr2 = findMinPointer(myArray2, size2);
    if (minValPtr2 != nullptr) {
        std::cout << "Minimum value (array 2): " << *minValPtr2 << std::endl;
    } else {
        std::cout << "Array 2 is empty or null." << std::endl;
    }

    return 0;
}