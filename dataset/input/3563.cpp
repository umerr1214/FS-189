#include <iostream>

template <typename T>
void printArray(const T arr[], int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        // LOGICAL ERROR: This condition causes a trailing comma for the last element
        if (i <= size - 1) { // Should be 'i < size - 1'
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