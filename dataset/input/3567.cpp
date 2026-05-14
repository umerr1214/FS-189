#include <iostream>
#include <string> // Included for general C++ program, not strictly used by printArray

// Function template to print elements of a 1D array
template <typename T>
void printArray(const T arr[], int size) {
    std::cout << "Array elements: [";
    // Handle empty array gracefully, avoiding unnecessary iteration
    // The loop condition 'i < size' correctly handles size <= 0 as well,
    // but this explicit check can improve clarity for empty arrays.
    if (size > 0) {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i];
            // Add a comma and space for all elements except the last one
            if (i < size - 1) {
                std::cout << ", ";
            }
        }
    }
    // Use '\n' for efficiency instead of std::endl, as it doesn't force a buffer flush.
    std::cout << "]\n";
}

int main() {
    // Test case 1: int array
    int myIntArray[] = {5, 10, 15, 20};
    int myIntArraySize = sizeof(myIntArray) / sizeof(myIntArray[0]);
    std::cout << "Testing int array:\n";
    printArray(myIntArray, myIntArraySize);

    std::cout << "\n";

    // Test case 2: char array
    char myCharArray[] = {'E', 'x', 'a', 'm', 'p', 'l', 'e'};
    int myCharArraySize = sizeof(myCharArray) / sizeof(myCharArray[0]);
    std::cout << "Testing char array:\n";
    printArray(myCharArray, myCharArraySize);

    std::cout << "\n";

    // Test case 3: Empty array (size 0)
    int anotherEmptyArray[] = {};
    int anotherEmptyArraySize = 0;
    std::cout << "Testing empty array:\n";
    printArray(anotherEmptyArray, anotherEmptyArraySize);

    return 0;
}