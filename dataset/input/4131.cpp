#include <iostream>

// Function to find the minimum element's pointer
const int* findMinPointer(const int* arr, int size) {
    // Robustness: Handle empty or invalid array cases.
    // If size is 0 or less, there are no elements to compare, so return nullptr.
    if (size <= 0) {
        return nullptr; 
    }

    // Efficiency and Readability:
    // Initialize minPtr to point to the first element.
    // Iterate from the second element, comparing each element's value
    // with the value pointed to by minPtr. This is a single-pass,
    // optimal O(N) solution.
    const int* minPtr = arr; // Initialize minPtr to point to the first element

    for (int i = 1; i < size; ++i) {
        // If the current element's value is less than the value at minPtr,
        // update minPtr to point to the current element.
        if (arr[i] < *minPtr) {
            minPtr = &arr[i]; 
        }
    }

    return minPtr; // Return the pointer to the element with the minimum value.
}

int main() {
    std::cout << "--- Testing findMinPointer ---" << std::endl;

    // Demonstrate with a user-defined array
    int myArray[] = {5, 2, 9, 1, 7, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    const int* minValPtr = findMinPointer(myArray, size);
    if (minValPtr != nullptr) {
        std::cout << "Original array: {5, 2, 9, 1, 7, 3}" << std::endl;
        std::cout << "The minimum value in the array is: " << *minValPtr << std::endl; // Expected: 1
    } else {
        std::cout << "Original array: {5, 2, 9, 1, 7, 3}" << std::endl;
        std::cout << "Array is empty or invalid." << std::endl;
    }

    std::cout << "\n--- Testing Edge Cases ---" << std::endl;

    // Test with an empty array
    int emptyArray[] = {};
    int emptySize = 0;
    const int* minValPtrEmpty = findMinPointer(emptyArray, emptySize);
    if (minValPtrEmpty != nullptr) {
        std::cout << "Empty array {}: Min value: " << *minValPtrEmpty << std::endl;
    } else {
        std::cout << "Empty array {}: Correctly returned nullptr (Array is empty or invalid)." << std::endl; // Expected: Correct
    }

    // Test with a single element array
    int singleArray[] = {42};
    int singleSize = 1;
    const int* minValPtrSingle = findMinPointer(singleArray, singleSize);
    if (minValPtrSingle != nullptr) {
        std::cout << "Single element array {42}: Min value: " << *minValPtrSingle << std::endl; // Expected: 42
    } else {
        std::cout << "Single element array {42}: Handled incorrectly." << std::endl;
    }

    // Test with negative numbers and duplicates
    int negArray[] = {-10, -5, -20, -5};
    int negSize = sizeof(negArray) / sizeof(negArray[0]);
    const int* minValPtrNeg = findMinPointer(negArray, negSize);
    if (minValPtrNeg != nullptr) {
        std::cout << "Negative array {-10, -5, -20, -5}: Min value: " << *minValPtrNeg << std::endl; // Expected: -20
    } else {
        std::cout << "Negative array handled incorrectly." << std::endl;
    }

    return 0;
}