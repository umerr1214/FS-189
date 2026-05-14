#include <iostream>

int main() {
    int arr[4] = {10, 20, 30, 40};
    int* ptr = arr; // Pointer to the first element

    // Semantic Error: Using sizeof(arr) which returns the size of the array in bytes (e.g., 16 bytes for 4 ints)
    // instead of the number of elements (4). This will cause the loop to iterate out of bounds,
    // leading to undefined behavior when accessing memory beyond the array.
    for (int i = 0; i < sizeof(arr); ++i) {
        std::cout << *(ptr + i) << std::endl;
    }

    return 0;
}