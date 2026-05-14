#include <iostream>
#include <limits> // For INT_MAX, INT_MIN
#include <vector> // For driver test cases

void findMinMax(int arr[], int size, int* minVal, int* maxVal) {
    if (size <= 0) {
        if (minVal) *minVal = 0;
        if (maxVal) *maxVal = 0;
        return;
    }

    *minVal = arr[0];
    *maxVal = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] > *minVal) { // LOGICAL ERROR: Should be '<' to find the minimum value
            *minVal = arr[i];
        }
        if (arr[i] < *maxVal) { // LOGICAL ERROR: Should be '>' to find the maximum value
            *maxVal = arr[i];
        }
    }
}

int main() {
    std::vector<int> arr1 = {10, 2, 5, 8, 1};
    int min1, max1;
    findMinMax(arr1.data(), arr1.size(), &min1, &max1);
    std::cout << "Input: {10, 2, 5, 8, 1}, Output: Min: " << min1 << ", Max: " << max1 << std::endl; // Expected: Min: 1, Max: 10. Actual: Min: 10, Max: 1

    std::vector<int> arr2 = {7};
    int min2, max2;
    findMinMax(arr2.data(), arr2.size(), &min2, &max2);
    std::cout << "Input: {7}, Output: Min: " << min2 << ", Max: " << max2 << std::endl; // Expected: Min: 7, Max: 7. Actual: Min: 7, Max: 7

    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    int min3, max3;
    findMinMax(arr3.data(), arr3.size(), &min3, &max3);
    std::cout << "Input: {1, 2, 3, 4, 5}, Output: Min: " << min3 << ", Max: " << max3 << std::endl; // Expected: Min: 1, Max: 5. Actual: Min: 5, Max: 1
    
    return 0;
}