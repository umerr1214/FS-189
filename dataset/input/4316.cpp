#include <iostream>
#include <vector>

// Function with a readability/efficiency issue:
// Uses a while loop with manual index management and an unnecessary temporary variable,
// which is less concise and readable than a standard for loop for this pattern.
void fill_array_sequential(int* arr, int size) {
    // No robustness checks, assuming valid inputs as per typical readability/efficiency focus.
    // For this category, the code should still be functionally correct for valid inputs.
    int current_idx = 0; // Slightly less descriptive than 'i' for a loop counter
    while (current_idx < size) {
        int val_to_assign = current_idx + 1; // Unnecessary temporary variable
        arr[current_idx] = val_to_assign;
        current_idx++; // Manual increment, less compact than a for loop header
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

    // Test Case 2: Zero size
    int arr2[1]; // Needs to be allocated even if size is 0
    fill_array_sequential(arr2, 0);
    std::cout << "Array 2 (size 0): (should be empty)" << std::endl; // No actual output from loop

    // Test Case 3: Larger size
    int arr3[10];
    fill_array_sequential(arr3, 10);
    std::cout << "Array 3 (size 10): ";
    for (int i = 0; i < 10; ++i) {
        std::cout << arr3[i] << (i == 9 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}