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

    std::cout << "Enter " << size << " integers:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    std::cout << "\nArray contents:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Semantic error: Forgetting to deallocate the dynamically allocated memory
    // delete[] arr; // This line is missing, leading to a memory leak
    // arr = nullptr;

    return 0;
}