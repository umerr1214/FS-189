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

    // Populate - LOGICAL ERROR: Populating with values from 0 to N-1 instead of 1 to N
    for (int i = 0; i < N; ++i) {
        arr[i] = i; // Should be i + 1 to get values from 1 to N
    }

    // Print
    std::cout << "Array contents: ";
    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << (i == N - 1 ? "" : " ");
    }
    std::cout << std::endl;

    // Deallocate
    delete[] arr;
    arr = nullptr;

    return 0;
}