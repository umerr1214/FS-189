#include <iostream>

int main() {
    int arr[5]; // Array of size 5, valid indices 0-4
    int size = 5;

    std::cout << "Enter 5 integer values:\n";
    // Semantic error: Loop condition allows access to arr[size] (arr[5])
    // when i becomes equal to size. This is an out-of-bounds write,
    // leading to undefined behavior (e.g., crash, memory corruption).
    for (int i = 0; i <= size; ++i) { // Should be i < size
        std::cout << "Enter value for element " << i << ": ";
        std::cin >> arr[i]; // When i=5, this accesses arr[5], which is out of bounds
    }

    // Subsequent operations might be affected by the corrupted memory
    // or the program might have already crashed.
    int maxVal = arr[0]; 
    int minVal = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }

    std::cout << "Largest element: " << maxVal << std::endl;
    std::cout << "Smallest element: " << minVal << std::endl;

    return 0;
}