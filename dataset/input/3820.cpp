#include <iostream>

int main() {
    // Dynamically allocate memory for an array of 5 integers
    int* arr = new int[5] // Syntax Error: Missing semicolon here

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
    delete[] arr;

    return 0;
}