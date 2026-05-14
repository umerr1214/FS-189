#include <iostream>

// Function to find the maximum and minimum elements in a 1D integer array
void findMinMax(const int arr[], int size, int& minVal, int& maxVal) {
    if (size <= 0) {
        // Handle empty array case by setting default values
        minVal = 0;
        maxVal = 0;
        return;
    }

    minVal = arr[0];
    maxVal = arr[0];

    // Semantic Error: Loop condition 'i <= size' causes array out-of-bounds access
    // when i becomes equal to 'size'. Valid indices are 0 to size-1.
    for (int i = 0; i <= size; ++i) { // Should be 'i < size'
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
}

int main() {
    // This main function is minimal as the comprehensive test driver is provided in JSON.
    // However, it demonstrates basic usage.
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6}; // Size is 8, valid indices 0-7. Loop will access arr[8].
    int size = sizeof(arr) / sizeof(arr[0]);
    int minVal, maxVal;
    findMinMax(arr, size, minVal, maxVal); // This call will result in undefined behavior.
    std::cout << "Min: " << minVal << ", Max: " << maxVal << std::endl;
    return 0;
}