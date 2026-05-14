#include <iostream>
#include <vector>

void fill_array_sequential(int* arr, int size) {
    // Semantic Error: Loop condition `i <= size` causes an out-of-bounds write.
    // When `i` equals `size`, `arr[size]` is accessed, which is past the end of a 0-indexed array of `size` elements.
    // This leads to undefined behavior, potentially a crash or memory corruption.
    for (int i = 0; i <= size; ++i) { // Should be i < size
        arr[i] = i + 1;
    }
}

int main() {
    // Test Case 1
    int size1 = 5;
    std::vector<int> vec1(size1); // Allocates elements from vec1[0] to vec1[4]
    fill_array_sequential(vec1.data(), size1); // Will attempt to write to vec1[5]
    for (int i = 0; i < size1; ++i) {
        std::cout << vec1[i] << (i == size1 - 1 ? "" : " ");
    }
    std::cout << std::endl;

    // Test Case 2
    int size2 = 3;
    std::vector<int> vec2(size2); // Allocates elements from vec2[0] to vec2[2]
    fill_array_sequential(vec2.data(), size2); // Will attempt to write to vec2[3]
    for (int i = 0; i < size2; ++i) {
        std::cout << vec2[i] << (i == size2 - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}