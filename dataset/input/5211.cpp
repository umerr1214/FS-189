#include <iostream>
#include <vector> // Not strictly needed for the function, but useful for main's output

// Correct and robust function
void doubleArrayElements(int* arr, int size) {
    // Robustness: Handle invalid inputs gracefully.
    // If arr is nullptr or size is non-positive, there's nothing to double.
    // Returning immediately prevents dereferencing a nullptr or iterating unnecessarily.
    if (arr == nullptr || size <= 0) {
        return;
    }

    // Efficient and readable pointer arithmetic iteration
    // Initialize a pointer to the start of the array
    int* currentPtr = arr;
    // Calculate the end boundary of the array (one past the last element)
    int* endPtr = arr + size;

    // Iterate using pointer arithmetic:
    // Loop continues as long as currentPtr is before endPtr.
    // In each iteration, dereference currentPtr to access the element, double its value,
    // then increment currentPtr to move to the next element.
    while (currentPtr < endPtr) {
        *currentPtr *= 2; // Double the value at the current pointer
        currentPtr++;     // Move to the next integer in memory
    }
}

// Helper function to print an array (safe for nullptr)
void printArray(const char* label, int* arr, int size) {
    std::cout << label;
    if (arr == nullptr) {
        std::cout << "(nullptr array)";
    } else if (size <= 0) {
        std::cout << "(empty or invalid size array)";
    } else {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    // Test Case 1: Standard array
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printArray("Original array 1: ", arr1, size1);
    doubleArrayElements(arr1, size1);
    printArray("Doubled array 1: ", arr1, size1);
    std::cout << std::endl;

    // Test Case 2: Empty array (size = 0)
    int arr2[] = {};
    int size2 = 0;
    printArray("Original array 2 (empty): ", arr2, size2);
    doubleArrayElements(arr2, size2);
    printArray("Doubled array 2 (empty): ", arr2, size2);
    std::cout << std::endl;

    // Test Case 3: Array with one element
    int arr3[] = {10};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    printArray("Original array 3: ", arr3, size3);
    doubleArrayElements(arr3, size3);
    printArray("Doubled array 3: ", arr3, size3);
    std::cout << std::endl;

    // Test Case 4: Larger array
    int arr4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    printArray("Original array 4: ", arr4, size4);
    doubleArrayElements(arr4, size4);
    printArray("Doubled array 4: ", arr4, size4);
    std::cout << std::endl;

    // Test Case 5: nullptr array pointer
    // The function should handle this gracefully without crashing.
    std::cout << "Calling with nullptr array and size 5 (expected no crash):" << std::endl;
    printArray("Original nullptr array: ", nullptr, 5);
    doubleArrayElements(nullptr, 5);
    printArray("Doubled nullptr array: ", nullptr, 5); // Still nullptr
    std::cout << std::endl;

    // Test Case 6: Negative size
    std::cout << "Calling with valid array and negative size -2 (expected no change):" << std::endl;
    int arr5[] = {1, 2, 3};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    printArray("Original array 5: ", arr5, size5);
    doubleArrayElements(arr5, -2);
    printArray("Doubled array 5: ", arr5, size5); // Should remain unchanged
    std::cout << std::endl;

    return 0;
}