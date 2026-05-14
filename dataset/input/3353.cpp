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

    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        } else { // Logical Error: This 'else' condition is incorrect.
                 // If arr[i] is not less than minVal, it doesn't automatically mean it's the new max.
                 // It might be between minVal and maxVal, or equal to minVal/maxVal.
                 // This logic prevents maxVal from being updated correctly if a new max
                 // appears after a new min has been found.
            maxVal = arr[i];
        }
    }
}

int main() {
    // This main function is minimal as the comprehensive test driver is provided in JSON.
    // However, it demonstrates basic usage.
    int arr[] = {5, 2, 9, 1, 7}; // Expected: Min: 1, Max: 9. Actual with error: Min: 1, Max: 7
    int size = sizeof(arr) / sizeof(arr[0]);
    int minVal, maxVal;
    findMinMax(arr, size, minVal, maxVal);
    std::cout << "Min: " << minVal << ", Max: " << maxVal << std::endl;
    return 0;
}