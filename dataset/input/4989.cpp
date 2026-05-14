#include <iostream>
#include <vector>
#include <algorithm> // Required for std::swap

// Correct and efficient implementation of reverseArray
// This function takes a one-dimensional integer array and its size,
// and reverses the order of its elements in-place.
void reverseArray(int* arr, int size) {
    // Handle edge cases: an empty array or a single-element array
    // do not require any reversal, so return immediately.
    if (size <= 1) {
        return;
    }

    // Initialize two pointers: 'left' starts at the beginning of the array,
    // and 'right' starts at the end.
    int left = 0;
    int right = size - 1;

    // Loop until the 'left' pointer meets or crosses the 'right' pointer.
    // This ensures that each pair of elements is swapped exactly once.
    while (left < right) {
        // Swap the elements pointed to by 'left' and 'right'.
        // std::swap is a clear and efficient way to perform the exchange.
        std::swap(arr[left], arr[right]);

        // Move the 'left' pointer one step to the right.
        left++;
        // Move the 'right' pointer one step to the left.
        right--;
    }
}

// Helper function to print the contents of a vector
void printArray(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Testing reverseArray (Correct Version):" << std::endl;

    // Test Case 1: Odd number of elements
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::cout << "Original: ";
    printArray(arr1);
    reverseArray(arr1.data(), arr1.size());
    std::cout << "Reversed: ";
    printArray(arr1);
    std::cout << std::endl;

    // Test Case 2: Even number of elements
    std::vector<int> arr2 = {10, 20, 30, 40};
    std::cout << "Original: ";
    printArray(arr2);
    reverseArray(arr2.data(), arr2.size());
    std::cout << "Reversed: ";
    printArray(arr2);
    std::cout << std::endl;

    // Test Case 3: Single element array
    std::vector<int> arr3 = {100};
    std::cout << "Original: ";
    printArray(arr3);
    reverseArray(arr3.data(), arr3.size());
    std::cout << "Reversed: ";
    printArray(arr3);
    std::cout << std::endl;

    // Test Case 4: Empty array
    std::vector<int> arr4;
    std::cout << "Original (empty): ";
    printArray(arr4);
    reverseArray(arr4.data(), arr4.size());
    std::cout << "Reversed (empty): ";
    printArray(arr4);
    std::cout << std::endl;

    // Test Case 5: Two elements
    std::vector<int> arr5 = {55, 66};
    std::cout << "Original: ";
    printArray(arr5);
    reverseArray(arr5.data(), arr5.size());
    std::cout << "Reversed: ";
    printArray(arr5);
    std::cout << std::endl;

    // Test Case 6: Larger array with various values
    std::vector<int> arr6 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    std::cout << "Original: ";
    printArray(arr6);
    reverseArray(arr6.data(), arr6.size());
    std::cout << "Reversed: ";
    printArray(arr6);
    std::cout << std::endl;

    return 0;
}