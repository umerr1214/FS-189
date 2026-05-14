#include <iostream>
#include <algorithm> // Not strictly needed for manual min/max, but often included

int main() {
    int arr[10] = {5, 2, 9, 1, 7, 3, 8, 4, 10, 6}; // Initialize array

    // Readability / Efficiency Issue: Uses two separate loops instead of a single pass
    // This approach iterates through the array twice, making it less efficient.

    int min_val;
    int max_val;

    // First loop to find the minimum value
    min_val = arr[0];
    for (int i = 1; i < 10; ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    // Second loop to find the maximum value
    max_val = arr[0];
    for (int i = 1; i < 10; ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    std::cout << "Minimum value: " << min_val << std::endl;
    std::cout << "Maximum value: " << max_val << std::endl;

    return 0;
}