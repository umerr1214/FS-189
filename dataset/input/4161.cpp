#include <iostream>
#include <iomanip> // Included for potential future formatting needs, good practice

// Function template to print array elements
template <typename T>
void printArray(const T arr[], int size) {
    std::cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        if (i > 0) {
            std::cout << " "; // Print a space before each element except the first
        }
        std::cout << arr[i];
    }
    std::cout << '\n'; // Use '\n' for efficiency, as it typically doesn't force a buffer flush
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