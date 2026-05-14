#include <iostream>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1 // Missing semicolon here
}

int main() {
    int arr1[] = {10, 20, 30, 40, 50};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Target 30 in arr1: " << linearSearch(arr1, size1, 30) << std::endl;

    int arr2[] = {5, 15, 25};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Target 5 in arr2: " << linearSearch(arr2, size2, 5) << std::endl;
    std::cout << "Target 10 in arr2: " << linearSearch(arr2, size2, 10) << std::endl;

    int arr3[] = {};
    int size3 = 0;
    std::cout << "Target 10 in empty arr3: " << linearSearch(arr3, size3, 10) << std::endl;

    return 0;
}