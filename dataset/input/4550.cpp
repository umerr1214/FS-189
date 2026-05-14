#include <iostream>
#include <vector>
#include <numeric>

// Readability / Efficiency Issue:
// 1. Poor variable names (x for arr, s for size).
// 2. Employs an arithmetic swap (`a = a + b; b = a - b; a = a - b;`) which is less readable,
//    can lead to integer overflow (undefined behavior in C++ for signed integers) for large values,
//    and is generally less safe/clear than a temporary variable swap or `std::swap`.
// 3. The loop iterates `s` times with a conditional check (`if (i < j)`) instead of the more efficient `s / 2` iterations,
//    performing redundant checks.
void reverseArray(int x[], int s) { // Poor variable names: x for arr, s for size
    for (int i = 0; i < s; ++i) { // Loop runs 's' times, twice as many iterations as needed for swaps
        int j = s - 1 - i;
        if (i < j) { // Only swap if we haven't crossed the middle
            // Arithmetic swap (less readable, potential for overflow leading to undefined behavior)
            x[i] = x[i] + x[j];
            x[j] = x[i] - x[j];
            x[i] = x[i] - x[j];
        }
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i == size - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Demonstrating reverseArray function (Readability/Efficiency Issue):" << std::endl;

    // Test case 1: Normal array
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Original array 1: ";
    printArray(arr1, size1);
    reverseArray(arr1, size1);
    std::cout << "Reversed array 1: ";
    printArray(arr1, size1);
    std::cout << std::endl;

    // Test case 2: Empty array (size = 0)
    int arr2[] = {};
    int size2 = 0;
    std::cout << "Original array 2 (empty): ";
    printArray(arr2, size2);
    reverseArray(arr2, size2);
    std::cout << "Reversed array 2 (empty): ";
    printArray(arr2, size2);
    std::cout << std::endl;

    // Test case 3: Single element array (size = 1)
    int arr3[] = {100};
    int size3 = 1;
    std::cout << "Original array 3 (single element): ";
    printArray(arr3, size3);
    reverseArray(arr3, size3);
    std::cout << "Reversed array 3 (single element): ";
    printArray(arr3, size3);
    std::cout << std::endl;

    // Test case 4: Array with large numbers (potential overflow with arithmetic swap)
    // The sum 1500000000 + 1500000000 = 3000000000, which overflows a 32-bit signed int.
    // While the arithmetic swap might produce correct results on some systems due to two's complement behavior,
    // it's officially undefined behavior according to the C++ standard.
    int arr4[] = {1500000000, 1, 2, 3, 1500000000}; 
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    std::cout << "Original array 4 (large numbers): ";
    printArray(arr4, size4);
    reverseArray(arr4, size4);
    std::cout << "Reversed array 4 (large numbers): ";
    printArray(arr4, size4);
    std::cout << "(Note: Arithmetic swap involves intermediate sums that can overflow signed integers, leading to undefined behavior)" << std::endl;
    std::cout << std::endl;

    return 0;
}