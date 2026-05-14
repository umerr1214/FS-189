#include <iostream>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i // Syntax Error: Missing semicolon here
        }
    }
    return -1;
}

int main() {
    int arr1[] = {10, 20, 30, 40, 50};
    int size1 = 5;
    std::cout << linearSearch(arr1, size1, 30) << std::endl;
    std::cout << linearSearch(arr1, size1, 10) << std::endl;
    std::cout << linearSearch(arr1, size1, 50) << std::endl;
    std::cout << linearSearch(arr1, size1, 100) << std::endl;

    int arr2[] = {5};
    int size2 = 1;
    std::cout << linearSearch(arr2, size2, 5) << std::endl;
    std::cout << linearSearch(arr2, size2, 10) << std::endl;

    int arr3_data[] = {1, 2, 3}; // A dummy array to pass when size is 0
    int size3 = 0;
    std::cout << linearSearch(arr3_data, size3, 10) << std::endl;

    return 0;
}