#include <iostream>
#include <vector>
#include <numeric> // For std::iota, though not strictly used in final concatenation logic

int main() {
    int size1, size2;

    std::cout << "Enter the size of the first array: ";
    std::cin >> size1; // Robustness issue: No check for non-integer input or negative size
    // If size1 is negative, new int[size1] is undefined behavior.
    // If input is non-integer, cin fails, subsequent reads will fail.

    int* arr1 = new int[size1]; // Potential UB if size1 is negative

    std::cout << "Enter " << size1 << " elements for the first array:" << std::endl;
    for (int i = 0; i < size1; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arr1[i]; // Robustness issue: No check for non-integer input
    }

    std::cout << "Enter the size of the second array: ";
    std::cin >> size2; // Robustness issue: No check for non-integer input or negative size
    // If size2 is negative, new int[size2] is undefined behavior.

    int* arr2 = new int[size2]; // Potential UB if size2 is negative

    std::cout << "Enter " << size2 << " elements for the second array:" << std::endl;
    for (int i = 0; i < size2; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arr2[i]; // Robustness issue: No check for non-integer input
    }

    int total_size = size1 + size2;
    int* concatenated_arr = new int[total_size];

    // Copy elements from arr1
    for (int i = 0; i < size1; ++i) {
        concatenated_arr[i] = arr1[i];
    }

    // Copy elements from arr2
    for (int i = 0; i < size2; ++i) {
        concatenated_arr[size1 + i] = arr2[i];
    }

    std::cout << "Concatenated array: ";
    for (int i = 0; i < total_size; ++i) {
        std::cout << concatenated_arr[i] << (i == total_size - 1 ? "" : " ");
    }
    std::cout << std::endl;

    // Clean up dynamically allocated memory
    delete[] arr1;
    delete[] arr2;
    delete[] concatenated_arr;

    return 0;
}