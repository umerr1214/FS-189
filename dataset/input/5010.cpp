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
        if (arr[i] < *minVal) {
            minVal = arr[i]; // SEMANTIC ERROR: Assigning int (arr[i]) to int* (minVal) without dereferencing
        }
        if (arr[i] > *maxVal) {
            maxVal = arr[i]; // SEMANTIC ERROR: Assigning int (arr[i]) to int* (maxVal) without dereferencing
        }
    }
}

int main() {
    std::vector<int> arr1 = {10, 2, 5, 8, 1};
    int min1, max1;
    // This line will cause a compilation error due to the semantic errors inside findMinMax
    // findMinMax(arr1.data(), arr1.size(), &min1, &max1);
    // std::cout << "Input: {10, 2, 5, 8, 1}, Output: Min: " << min1 << ", Max: " << max1 << std::endl;

    std::vector<int> arr2 = {7};
    int min2, max2;
    // findMinMax(arr2.data(), arr2.size(), &min2, &max2);
    // std::cout << "Input: {7}, Output: Min: " << min2 << ", Max: " << max2 << std::endl;

    // The program will not compile due to the semantic error.
    return 0;
}