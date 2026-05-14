#include <iostream>
#include <limits> // Required for std::numeric_limits

void analyzeArray(int arr[], int size, int& minVal, int& maxVal) {
    if (size <= 0) {
        // For an empty array, minVal and maxVal remain unchanged (or can be set to sentinel values)
        return;
    }

    minVal = arr[0];
    maxVal = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
}

int main() {
    int arr1[] = {10, 4, 20, 5, 15};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int min_val1 = 0;
    int max_val1 = 0;

    std::cout << "Array 1: ";
    for (int i = 0; i < size1; ++i) {
        std::cout << arr1[i] << (i == size1 - 1 ? "" : ", ");
    }
    std::cout << std::endl;

    analyzeArray(arr1, size1, min_val1, max_val1);
    std::cout << "Min: " << min_val1 << ", Max: " << max_val1 << std::end; // Syntax Error: std::end instead of std::endl

    int arr2[] = {-1, -5, -10, 0, 3};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int min_val2 = 0;
    int max_val2 = 0;

    std::cout << "\nArray 2: ";
    for (int i = 0; i < size2; ++i) {
        std::cout << arr2[i] << (i == size2 - 1 ? "" : ", ");
    }
    std::cout << std::endl;

    analyzeArray(arr2, size2, min_val2, max_val2);
    std::cout << "Min: " << min_val2 << ", Max: " << max_val2 << std::endl;

    int arr3[] = {7};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int min_val3 = 0;
    int max_val3 = 0;

    std::cout << "\nArray 3: ";
    for (int i = 0; i < size3; ++i) {
        std::cout << arr3[i] << (i == size3 - 1 ? "" : ", ");
    }
    std::cout << std::endl;

    analyzeArray(arr3, size3, min_val3, max_val3);
    std::cout << "Min: " << min_val3 << ", Max: " << max_val3 << std::endl;

    return 0;
}