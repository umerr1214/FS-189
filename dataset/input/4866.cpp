#include <iostream>

void printArrayElements(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int myArray[] = {10, 20, 30, 40, 50};
    // Semantic Error: Passing sizeof(myArray) (total bytes) instead of the number of elements.
    // sizeof(myArray) will be 20 bytes (assuming int is 4 bytes), not 5 elements.
    // This leads to out-of-bounds access within the printArrayElements function.
    printArrayElements(myArray, sizeof(myArray)); 
    return 0;
}