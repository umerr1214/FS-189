#include <iostream>

// Semantic Error: This function attempts to determine the array's size
// from a decayed pointer argument, leading to an incorrect size calculation
// and potential out-of-bounds access (undefined behavior).
int calculateSumWithSemanticError(int* arrayPtr) {
    int sum = 0;
    // INCORRECT: sizeof(arrayPtr) here gives the size of a pointer (e.g., 8 bytes on a 64-bit system),
    // not the total size of the array in bytes. sizeof(arrayPtr[0]) gives sizeof(int) (e.g., 4 bytes).
    // This results in 'size_attempted' being incorrect (e.g., 8/4 = 2).
    int size_attempted = sizeof(arrayPtr) / sizeof(arrayPtr[0]);

    int* currentPtr = arrayPtr;
    for (int i = 0; i < size_attempted; ++i) {
        sum += *currentPtr;
        currentPtr++;
    }
    return sum;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50}; // Array of 5 elements, correct sum = 150

    // Pass array to the function, it decays to a pointer.
    // The function will incorrectly calculate its size.
    int sum_calculated = calculateSumWithSemanticError(arr);

    std::cout << "Original array: {10, 20, 30, 40, 50}" << std::endl;
    std::cout << "Sum calculated by function (with semantic error): " << sum_calculated << std::endl;
    // Expected output for the buggy code (e.g., if sizeof(int*) is 8 and sizeof(int) is 4): 30 (10+20)
    // Correct output should be 150.

    return 0;
}