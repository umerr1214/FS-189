#include <iostream>

int main() {
    int N;
    std::cout << "Enter the size of the array (N): ";
    std::cin >> N;

    if (N <= 0) {
        std::cout << "Array size must be positive." << std::endl;
        return 1;
    }

    int* arr = new int[N];

    // Populate
    for (int i = 0; i < N; ++i) {
        arr[i] = i + 1;
    }

    // Print
    std::cout << "Array contents: ";
    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << (i == N - 1 ? "" : " ");
    }
    std::cout << std::endl;

    // Deallocate - SEMANTIC ERROR: Memory leak, 'delete[] arr;' is missing
    // delete[] arr; // This line is intentionally omitted, causing a memory leak
    // arr = nullptr;

    return 0;
}