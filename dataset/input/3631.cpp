#include <iostream>
#include <algorithm> // Not strictly needed for manual min/max, but often included

int main() {
    int arr[10] = {5, 2, 9, 1, 7, 3, 8, 4, 10, 6}; // Initialize array

    // Robustness Issue: Off-by-one error in loop condition
    // This loop will attempt to access arr[10], which is out of bounds,
    // leading to undefined behavior or a program crash.
    int min_val = arr[0];
    int max_val = arr[0];

    // Loop from the second element, but with an incorrect upper bound
    for (int i = 1; i <= 10; ++i) { // ERROR: Should be i < 10
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    std::cout << "Minimum value: " << min_val << std::endl;
    std::cout << "Maximum value: " << max_val << std::endl;

    return 0;
}