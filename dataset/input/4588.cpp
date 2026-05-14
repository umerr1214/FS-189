#include <iostream>

int main() {
    int size;
    std::cout << "Enter array size: " // Syntax Error: Missing semicolon
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

    std::cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i == size - 1 ? "" : " ");
    }
    std::cout << std::endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}