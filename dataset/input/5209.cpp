#include <iostream>
#include <vector> // Not strictly needed for the function, but useful for main's output

// Function with a robustness issue: does not handle nullptr array pointer
void doubleArrayElements(int* arr, int size) {
    // Robustness Issue: No check for arr == nullptr or size <= 0.
    // If arr is nullptr and size > 0, dereferencing *currentPtr will lead to a crash.
    // If size is <= 0, the loop won't run, which is implicitly handled,
    // but an explicit check might be more robust in some contexts.

    // Using a for loop with pointer arithmetic
    for (int i = 0; i < size; ++i) {
        // Pointer arithmetic: arr + i gives the address of the i-th element
        // *(arr + i) dereferences it to get the value
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

    // Test Case 4: Robustness Issue Trigger - nullptr array pointer with positive size
    // This call is expected to cause a runtime error (e.g., segmentation fault)
    // because doubleArrayElements does not check for a nullptr arr.
    std::cout << "Attempting to double a nullptr array with size 5..." << std::endl;
    doubleArrayElements(nullptr, 5); // This line will likely crash the program
    std::cout << "This line should not be reached if the crash occurs." << std::endl;

    return 0;
}