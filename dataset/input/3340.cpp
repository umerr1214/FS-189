#include <iostream>
#include <vector> // Not strictly necessary for this implementation, but common

// Function signature: double calculate_average(const int arr[], int size)
double calculate_average(const int arr[], int size) {
    if (size <= 0) {
        return 0.0;
    }
    double total = 0.0;
    for (int i = 0; i < size; ++i) {
        total += arr[i];
    }
    // Syntax Error: Missing semicolon after the return statement
    return total / static_cast<double>(size) 
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = 5;
    std::cout << "Average of {1, 2, 3, 4, 5}: " << calculate_average(arr1, size1) << std::endl;

    int arr2[] = {10};
    int size2 = 1;
    std::cout << "Average of {10}: " << calculate_average(arr2, size2) << std::endl;

    // Note: For size = 0, passing an empty array literal directly to a C-style array parameter
    // might lead to warnings or undefined behavior depending on the compiler and context.
    // A safer way would be to pass nullptr and 0, or use std::vector.
    // However, for this problem, we assume the caller handles valid array pointers for size > 0.
    // The if (size <= 0) check handles the logic for an empty array.
    int arr3[] = {}; // This is technically an array of size 0, but often compilers treat it as size 1 with no elements.
    int size3 = 0;   // Explicitly set size to 0
    std::cout << "Average of {}: " << calculate_average(arr3, size3) << std::endl;

    int arr4[] = {1, 2, 4};
    int size4 = 3;
    std::cout << "Average of {1, 2, 4}: " << calculate_average(arr4, size4) << std::endl;

    return 0;
}