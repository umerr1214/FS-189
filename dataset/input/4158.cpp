#include <iostream>

template <typename T>
void printArray(const T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        // Semantic error: Attempting to modify a const array element.
        // The 'arr' parameter is declared as 'const T arr[]', meaning its elements cannot be changed.
        arr[i] = T(); // This line will cause a compilation error.
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Integer array: ";
    printArray(intArray, intSize); // This call will trigger the semantic error

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    std::cout << "Double array: ";
    printArray(doubleArray, doubleSize); // This call will also trigger the semantic error

    return 0;
}