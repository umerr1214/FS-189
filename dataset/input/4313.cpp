#include <iostream>
#include <vector>

void fill_array_sequential(int* arr, int size) {
    // Logical Error: Fills array with values starting from 0 instead of 1.
    // arr[i] should be i + 1 for sequential values starting from 1.
    for (int i = 0; i < size; ++i) {
        arr[i] = i; 
    }
}

int main() {
    // Test Case 1
    int size1 = 5;
    std::vector<int> vec1(size1);
    fill_array_sequential(vec1.data(), size1);
    for (int i = 0; i < size1; ++i) {
        std::cout << vec1[i] << (i == size1 - 1 ? "" : " ");
    }
    std::cout << std::endl; // Expected: 1 2 3 4 5, Actual: 0 1 2 3 4

    // Test Case 2
    int size2 = 3;
    std::vector<int> vec2(size2);
    fill_array_sequential(vec2.data(), size2);
    for (int i = 0; i < size2; ++i) {
        std::cout << vec2[i] << (i == size2 - 1 ? "" : " ");
    }
    std::cout << std::endl; // Expected: 1 2 3, Actual: 0 1 2

    return 0;
}