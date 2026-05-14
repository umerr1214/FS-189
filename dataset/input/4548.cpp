#include <iostream>
#include <algorithm> // Not used for actual swap, but could be for copying
#include <vector> // Potentially for temporary storage

void reverseArray(int arr[], int size) {
    // Semantic Error: The function attempts to reverse the array by creating a new
    // temporary array, copying reversed elements into it, and then reassigning
    // the local 'arr' pointer to point to this new array. This reassignment
    // only affects the local pointer within this function's scope and does not
    // modify the original array in the calling function (main).
    // This violates the 'in-place' and 'pass-by-reference' semantics.
    // Additionally, the dynamically allocated 'tempArr' is leaked as it's never deleted.
    if (size <= 1) {
        return;
    }

    int* tempArr = new int[size];
    for (int i = 0; i < size; ++i) {
        tempArr[i] = arr[size - 1 - i];
    }
    
    // This line is the semantic error. It reassigns the local 'arr' pointer.
    // The array pointed to by 'arr' in main remains unchanged.
    arr = tempArr; 
    
    // Memory leak: 'tempArr' is never deleted, and the original array in 'main'
    // is not updated.
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    std::cout << "Original array 1: ";
    for (int i = 0; i < size1; ++i) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    reverseArray(arr1, size1);

    std::cout << "Reversed array 1: "; // This will still print the original arr1
    for (int i = 0; i < size1; ++i) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    int arr2[] = {10, 20, 30, 40};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << "Original array 2: ";
    for (int i = 0; i < size2; ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    reverseArray(arr2, size2);

    std::cout << "Reversed array 2: "; // This will still print the original arr2
    for (int i = 0; i < size2; ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}