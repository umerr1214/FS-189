#include <iostream>
// No need for <limits> if initializing with arr[0]

int student_main() {
    int arr[10] = {5, 2, 9, 1, 7, 3, 8, 4, 6, 10}; // Min=1, Max=10
    int minVal = arr[0]; // Initialize minVal with the first element (5)
    int maxVal = arr[0]; // Initialize maxVal with the first element (5)

    // Logical error: The comparison operators are swapped for min and max.
    // Also, the loop starts from index 0, re-evaluating arr[0] which is redundant after initialization.
    for (int i = 0; i < 10; ++i) {
        if (arr[i] > minVal) { // Incorrect: Should be '<' to find the minimum
            minVal = arr[i];
        }
        if (arr[i] < maxVal) { // Incorrect: Should be '>' to find the maximum
            maxVal = arr[i];
        }
    }

    std::cout << "Minimum value: " << minVal << std::endl;
    std::cout << "Maximum value: " << maxVal << std::endl;
    return 0;
}