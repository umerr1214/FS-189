#include <iostream>

int main() {
    int arr[10]; // Array of size 10, valid indices 0-9
    int max_val;

    std::cout << "Enter 10 integer values:" << std::endl;

    // Semantic error: Loop condition i <= 10 attempts to access arr[10],
    // which is out of bounds for an array of size 10 (indices 0-9).
    // This leads to undefined behavior.
    for (int i = 0; i <= 10; i++) { 
        std::cout << "Enter value " << i + 1 << ": ";
        std::cin >> arr[i]; // Out-of-bounds write when i is 10
    }

    // Assuming the program doesn't crash before this point, 
    // the max finding logic might also be affected by corrupted memory.
    max_val = arr[0]; 

    for (int i = 1; i < 10; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    std::cout << "The largest element in the array is: " << max_val << std::endl;

    return 0;
}