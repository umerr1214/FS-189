#include <iostream> // Required for input/output operations

int main() {
    // Declare an array of 4 integers and initialize it with specified values
    int numbers[4] = {10, 20, 30, 40};

    // Declare a pointer and initialize it to point to the first element of the array
    int* currentPtr = numbers; // 'numbers' itself decays to a pointer to its first element

    // Iterate through the array using pointer arithmetic
    // The loop runs for 4 iterations, covering indices 0 to 3
    for (int i = 0; i < 4; ++i) {
        // Print the value at the current pointer position
        // currentPtr + i performs pointer arithmetic to access subsequent elements
        std::cout << "Element " << i + 1 << ": " << *(currentPtr + i) << std::endl;
    }

    return 0; // Indicate successful execution of the program
}