#include <iostream>

int main() {
    int size;
    std::cout << "Enter the desired size of the array: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Array size must be positive." << std::endl;
        return 1;
    }

    int* arr = new int[size]; // Memory allocated dynamically

    for (int i = 0; i < size; ++i) {
        arr[i] = i;
    }

    std::cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Semantic Error: The dynamically allocated memory is not deallocated.
    // The line 'delete[] arr;' is missing, leading to a memory leak.
    // delete[] arr; // This line should be here
    // arr = nullptr;

    return 0;
}