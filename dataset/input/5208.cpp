#include <iostream>

void doubleArrayElements(int* arr, int size) {
    // Semantic error: Loop iterates size+1 times, accessing out-of-bounds memory
    for (int i = 0; i <= size; ++i) { // Should be i < size
        *(arr + i) = *(arr + i) * 2;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Array of size 5
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i == size - 1 ? "" : ", ");
    }
    std::cout << std::endl;

    doubleArrayElements(arr, size);

    std::cout << "Modified array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i == size - 1 ? "" : ", ");
    }
    std::cout << std::endl;

    return 0;
}