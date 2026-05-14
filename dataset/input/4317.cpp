#include <iostream>
#include <vector>

// Correct, robust, and readable implementation of fill_array_sequential
void fill_array_sequential(int* arr, int size) {
    // Robustness check: Handle nullptr for arr and non-positive size gracefully.
    // If arr is nullptr or size is not positive, there's nothing valid to fill.
    // Returning early prevents crashes and handles invalid input elegantly.
    if (arr == nullptr || size <= 0) {
        return;
    }

    // Efficient and readable loop using a standard for-loop
    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1;
    }
}

int main() {
    // Test Case 1: Standard usage
    int arr1[5];
    fill_array_sequential(arr1, 5);
    std::cout << "Array 1 (size 5): ";
    for (int i = 0; i < 5; ++i) {
        std::cout << arr1[i] << (i == 4 ? "" : " ");
    }
    std::cout << std::endl;

    // Test Case 2: Zero size (handled gracefully)
    int arr2[1]; // Needs to be allocated even if size is 0
    fill_array_sequential(arr2, 0);
    std::cout << "Array 2 (size 0): (should be empty)" << std::endl;

    // Test Case 3: Larger size
    int arr3[10];
    fill_array_sequential(arr3, 10);
    std::cout << "Array 3 (size 10): ";
    for (int i = 0; i < 10; ++i) {
        std::cout << arr3[i] << (i == 9 ? "" : " ");
    }
    std::cout << std::endl;

    // Test Case 4: nullptr input (handled gracefully)
    std::cout << "Attempting to call with nullptr and size 3 (should do nothing)..." << std::endl;
    fill_array_sequential(nullptr, 3);
    std::cout << "Function called with nullptr, program continues as expected." << std::endl;

    // Test Case 5: Negative size input (handled gracefully)
    std::cout << "Attempting to call with negative size -5 (should do nothing)..." << std::endl;
    int arr4[5]; // Allocate memory for demonstration
    fill_array_sequential(arr4, -5);
    std::cout << "Function called with negative size, program continues as expected." << std::endl;

    return 0;
}