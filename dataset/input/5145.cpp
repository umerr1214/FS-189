#include <iostream>

int main() {
    int arraySize; // Descriptive variable name
    std::cout << "Enter array size: ";
    std::cin >> arraySize;

    // Robustness: Validate user input for array size
    if (std::cin.fail() || arraySize < 0) {
        std::cout << "Invalid array size. Please enter a non-negative integer.\n"; // Informative error message
        return 1; // Indicate error
    }

    // Handle the edge case of an empty array
    if (arraySize == 0) {
        std::cout << "Array elements: (empty array)\n";
        return 0;
    }

    // Dynamically allocate memory
    int* dynamicArray = new int[arraySize]; // Descriptive variable name

    // Populate and print the array elements
    std::cout << "Array elements: ";
    for (int i = 0; i < arraySize; ++i) {
        dynamicArray[i] = i;
        std::cout << dynamicArray[i] << " "; // Efficient printing using space separator
    }
    std::cout << "\n"; // Efficient newline character instead of std::endl

    // Deallocate the dynamically allocated memory
    delete[] dynamicArray;

    return 0;
}