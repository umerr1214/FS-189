#include <iostream>
#include <vector>     // For std::vector
#include <algorithm>  // For std::min_element
#include <iterator>   // For std::distance

// Function to find the minimum element's pointer
const int* findMinPointer(const int* arr, int size) {
    if (size <= 0) {
        return nullptr; // Handles empty or invalid array gracefully (robust).
    }

    // Readability/Efficiency Issue:
    // This implementation unnecessarily copies the input array into a std::vector.
    // This involves dynamic memory allocation for the vector and extra processing
    // to find the minimum and then determine its original position, making it less
    // efficient and more complex than a direct iterative approach using pointers
    // on the original array.

    // 1. Copy array to a vector (inefficient and unnecessary memory allocation)
    std::vector<int> tempVec(arr, arr + size); 

    // 2. Use std::min_element on the vector
    auto it = std::min_element(tempVec.begin(), tempVec.end()); 

    // 3. Calculate the index in the original array
    // This requires another iteration or calculation, adding to complexity.
    int minIndex = std::distance(tempVec.begin(), it);

    // 4. Return pointer to the element in the original array
    return &arr[minIndex]; 
}

int main() {
    std::cout << "--- Testing findMinPointer ---" << std::endl;

    // Demonstrate with a user-defined array
    int myArray[] = {5, 2, 9, 1, 7, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    const int* minValPtr = findMinPointer(myArray, size);
    if (minValPtr != nullptr) {
        std::cout << "Array: {5, 2, 9, 1, 7, 3}, Min value: " << *minValPtr << std::endl; // Expected: 1
    } else {
        std::cout << "Array: {5, 2, 9, 1, 7, 3}, Error: Returned nullptr." << std::endl;
    }

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

    return 0;
}