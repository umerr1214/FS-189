#include <iostream>
#include <algorithm> // Not strictly needed for manual min/max, but often included

int main() {
    int arr[10] = {5, 2, 9, 1, 7, 3, 8, 4, 10, 6}; // Initialize array

    // Correct and efficient approach: Initialize min/max with the first element
    // then iterate from the second element in a single pass.
    int min_val = arr[0];
    int max_val = arr[0];

    for (int i = 1; i < 10; ++i) {
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