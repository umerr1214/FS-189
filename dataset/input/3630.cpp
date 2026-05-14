#include <iostream>
#include <limits> // Required for std::numeric_limits

int student_main() {
    int arr[10] = {5, 2, 9, 1, 7, 3, 8, 4, 6, 10}; // Array of 10 elements, valid indices 0-9
    int minVal = std::numeric_limits<int>::max();
    int maxVal = std::numeric_limits<int>::min();

    // Semantic error: Loop condition allows access to arr[10], which is out of bounds.
    for (int i = 0; i <= 10; ++i) { // Should be i < 10
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    std::cout << "Minimum value: " << minVal << std::endl;
    std::cout << "Maximum value: " << maxVal << std::endl;
    return 0;
}