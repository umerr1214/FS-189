#include <iostream>
#include <iomanip> // For formatting doubles, though not strictly required

// Function template to print array elements
template <typename T>
void printArray(const T arr[], int size) {
    std::cout << "Array elements: ";
    // Readability issue: Inconsistent and verbose logic for spacing.
    // It handles the first element separately then loops for the rest,
    // making the code less concise than a single loop with conditional spacing.
    if (size > 0) {
        T first_val = arr[0]; // Readability issue: Unnecessary intermediate variable
        std::cout << first_val;
        for (int k = 1; k < size; ++k) {
            std::cout << " " << arr[k];
        }
    }
    // Efficiency issue: Using std::endl flushes the output buffer,
    // which can be less efficient than using '\n' (which typically doesn't flush)
    // especially if this function is called frequently in performance-critical code.
    std::cout << std::endl;
}

int main() {
    // Demonstrate with an array of integers
    int intArray[] = {10, 20, 30};
    printArray(intArray, 3);

    // Demonstrate with an array of doubles
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    printArray(doubleArray, 4);

    // Demonstrate with an array of characters
    char charArray[] = {'a', 'b', 'c'};
    printArray(charArray, 3);

    // Demonstrate with an empty array
    int emptyArray[] = {};
    printArray(emptyArray, 0);

    return 0;
}