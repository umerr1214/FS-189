#include <iostream>

int main() {
    // Dynamically allocate memory for an array of 5 integers
    int* arr = new int[5];

    // Prompt user to enter values for these integers
    std::cout << "Enter 5 integers:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Enter value for element " << i << ": ";
        std::cin >> arr[i];
    }

    // Print the values
    std::cout << "\nThe entered values are:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Element " << i << ": " << arr[i] << "\n";
    }

    // Deallocate the memory
    // Semantic Error: 'delete arr' is used instead of 'delete[] arr' for an array allocated with 'new int[5]'.
    // This leads to undefined behavior, often a memory leak or heap corruption.
    delete arr; 

    return 0;
}