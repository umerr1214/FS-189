#include <iostream>
#include <string> // Included for general C++ program, not strictly used by printArray

// Function template to print elements of a 1D array
template <typename T>
void printArray(const T arr[], int size) {
    std::cout << "Array elements: [";
    // Robustness Issue: This loop condition 'i < size' does not
    // explicitly handle negative 'size' values. If 'size' is negative,
    // the loop condition '0 < negative_size' will immediately be false,
    // causing it to print "Array elements: []" as if the array was empty.
    // A robust function should validate 'size' (e.g., throw an exception,
    // return an error, or log a warning) for invalid inputs like negative size.
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

int main() {
    // Test case 1: int array
    int intArray[] = {10, 20, 30, 40, 50};
    int intArraySize = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Testing int array:\n";
    printArray(intArray, intArraySize); // Expected: Array elements: [10, 20, 30, 40, 50]

    std::cout << "\n";

    // Test case 2: char array
    char charArray[] = {'C', '+', '+', ' ', 'F', 'u', 'n'};
    int charArraySize = sizeof(charArray) / sizeof(charArray[0]);
    std::cout << "Testing char array:\n";
    printArray(charArray, charArraySize); // Expected: Array elements: [C, +, +,  , F, u, n]

    std::cout << "\n";

    // Test case 3: Empty array (size 0)
    int emptyArray[] = {}; // C++11 allows this
    int emptyArraySize = 0;
    std::cout << "Testing empty array:\n";
    printArray(emptyArray, emptyArraySize); // Expected: Array elements: []

    std::cout << "\n";

    // Test case 4: Negative size - Robustness issue demonstration
    // The function will treat negativeSize as 0 and print "Array elements: []"
    // instead of reporting an error or handling it explicitly.
    int smallArray[] = {1, 2}; // Array content doesn't matter for this test
    int negativeSize = -3;
    std::cout << "Testing array with negative size (" << negativeSize << "):\n";
    printArray(smallArray, negativeSize); // Expected: Array elements: [] (but should ideally error)

    return 0;
}