#include <iostream>

int main() {
    int size;
    std::cout << "Enter the desired size of the array: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Array size must be positive." << std::endl;
        return 1;
    }

    int* arr = new int[size];

    // Logical Error: Populating the array with i + 1 instead of i,
    // so elements start from 1 instead of 0.
    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1; // Should be arr[i] = i;
    }

    std::cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}