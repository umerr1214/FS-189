#include <iostream>

template <typename T>
void printArray(const T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " " // Syntax Error: Missing semicolon here
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

    return 0;
}