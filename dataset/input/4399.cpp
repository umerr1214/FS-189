#include <iostream>

int main() {
    // Declare an array of 4 integers and initialize it
    int numbers[4] = {10, 20, 30, 40};

    // Use a pointer to the first element
    int* ptr = numbers;

    // Iterate through the array using pointer arithmetic and print each element
    // This loop condition is intentionally incorrect to demonstrate a robustness issue (out-of-bounds read)
    for (int i = 0; i <= 4; ++i) { // Loop goes one element too far
        // Attempt to access an element potentially out of bounds
        // On the last iteration (i=4), ptr + 4 is numbers[4], which is out of bounds.
        std::cout << "Value: " << *(ptr + i) << std::endl;
    }

    return 0;
}