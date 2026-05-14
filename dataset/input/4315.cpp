#include <iostream>
#include <vector> // Not strictly needed for the function, but common in C++ demos

// Function with a robustness issue: does not handle nullptr for arr.
// Passing nullptr will lead to a segmentation fault or undefined behavior.
void fill_array_sequential(int* arr, int size) {
    // CRITICAL ROBUSTNESS ISSUE: No check for arr == nullptr.
    // If arr is nullptr, dereferencing arr[i] will cause a crash.
    // Also, no check for size < 0, though the loop handles it gracefully by not iterating.
    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1;
    }
}

int main() {
    // Test Case 1: Valid input
    int arr1[5];
    fill_array_sequential(arr1, 5);
    std::cout << "Array 1 (size 5): ";
    for (int i = 0; i < 5; ++i) {
        std::cout << arr1[i] << (i == 4 ? "" : " ");
    }
    std::cout << std::endl;

    // Test Case 2: Robustness issue - passing nullptr
    // This call is expected to cause a segmentation fault or access violation.
    std::cout << "Attempting to call with nullptr and size 3..." << std::endl;
    fill_array_sequential(nullptr, 3);
    std::cout << "This line should not be reached if crash occurs." << std::endl; // This line will likely not be printed

    return 0;
}