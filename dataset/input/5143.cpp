#include <iostream>

int main() {
    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;

    // Robustness issue: No validation for size.
    // If 'size' is negative, 'new int[size]' results in undefined behavior,
    // often leading to a crash or memory corruption.
    // If 'size' is non-integer (e.g., 'abc'), std::cin.fail() would be true,
    // but the program proceeds with an uninitialized 'size' or 0, leading to
    // further issues.

    int* arr = new int[size]; // Potential undefined behavior if size is negative

    std::cout << "Array elements: ";
    for (int i = 0; i < size; ++i) { // This loop might access invalid memory if size is negative
        arr[i] = i;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr; // Potential issue if allocation failed or was corrupted

    return 0;
}