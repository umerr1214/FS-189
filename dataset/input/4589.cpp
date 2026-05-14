#include <iostream>

int main() {
    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;

    if (size <= 0) {
        std::cerr << "Array size must be positive." << std::endl;
        return 1;
    }

    int* arr = new int[size];

    std::cout << "Enter " << size << " integer values:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter value for element " << i << ": ";
        std::cin >> arr[i];
    }

    // Logical Error: Prints one less element than allocated/entered
    std::cout << "Array elements: ";
    for (int i = 0; i < size - 1; ++i) { // Loop iterates up to size-2, missing the last element
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}