#include <iostream>
#include <vector> // Not strictly needed for the function, but useful for main's output

// Function with a readability/efficiency issue
void doubleArrayElements(int* arr, int size) {
    // Implicitly handles size <= 0 by not entering the loop.
    // Assumes arr is not nullptr, which is a robustness issue if not guaranteed by caller.

    // Readability/Efficiency Issue:
    // Using `*(arr + i)` in each iteration means the address `arr + i`
    // is recalculated (potentially involving a multiplication for `i * sizeof(int)`
    // and an addition) in every loop cycle.
    // While compilers can optimize this for simple cases, it's generally less
    // efficient than using a separate pointer that is simply incremented (`currentPtr++`).
    // It also might be considered slightly less readable/idiomatic for direct
    // pointer iteration compared to incrementing a dedicated pointer.
    for (int i = 0; i < size; ++i) {
        *(arr + i) *= 2;
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

    return 0;
}