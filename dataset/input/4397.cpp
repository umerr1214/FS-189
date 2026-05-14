#include <iostream>

int main() {
    int arr[4] = {10, 20, 30, 40};
    int* ptr = arr; // Pointer to the first element

    for (int i = 0; i < 4; ++i) {
        // Logical Error: Always printing the value pointed to by the initial 'ptr'
        // instead of advancing the pointer using pointer arithmetic (ptr + i).
        std::cout << *ptr << std::endl;
    }

    return 0;
}