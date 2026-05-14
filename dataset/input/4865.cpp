#include <iostream>

void printArrayElements(int* arr, int size) {
    for (int i = 0; i <= size; ++i) { // Logical Error: Loop condition 'i <= size' causes out-of-bounds access
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int myArray[] = {10, 20, 30, 40, 50};
    int size = sizeof(myArray) / sizeof(myArray[0]); // size is 5
    printArrayElements(myArray, size);
    return 0;
}