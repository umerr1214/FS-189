#include <iostream>

template <typename T>
void printArray(const T arr[], int size) {
    // Logical error: The loop iterates 'size - 1' times, missing the last element.
    for (int i = 0; i < size - 1; ++i) { // Should be i < size
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Integer array: ";
    printArray(intArray, intSize);

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    std::cout << "Double array: ";
    printArray(doubleArray, doubleSize);

    // Test with a single element array, which will print nothing due to the error
    char charArray[] = {'a'};
    int charSize = sizeof(charArray) / sizeof(charArray[0]);
    std::cout << "Char array: ";
    printArray(charArray, charSize);

    return 0;
}