#include <iostream>

void printArrayElements(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " " // Syntax Error: Missing semicolon
    }
    std::cout << std::endl;
}

int main() {
    int myArray[] = {10, 20, 30, 40, 50};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    printArrayElements(myArray, size);
    return 0;
}