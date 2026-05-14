#include <iostream>

template <typename T>
void printArray(const T arr[], int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        // SEMANTIC ERROR: Explicitly casting all elements to int before printing.
        // This works for 'int' arrays, but for 'char' arrays, it prints their ASCII values
        // instead of the characters themselves, misinterpreting the data type's intended output.
        std::cout << static_cast<int>(arr[i]);
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    printArray(intArray, intSize);

    char charArray[] = {'H', 'e', 'l', 'l', 'o'};
    int charSize = sizeof(charArray) / sizeof(charArray[0]);
    printArray(charArray, charSize);

    return 0;
}