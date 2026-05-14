#include <iostream>
#include <vector>

// Function with a syntax error: missing semicolon
void initializeWithDefaults(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = -1 // Missing semicolon here
    }
}

int main() {
    // This main function is just to make it a complete C++ program.
    // It will not compile due to the syntax error in initializeWithDefaults.
    // If it compiled, a typical call would be:
    // int myArr[5];
    // initializeWithDefaults(myArr, 5);
    // for (int i = 0; i < 5; ++i) {
    //     std::cout << myArr[i] << " ";
    // }
    // std::cout << std::endl;
    return 0;
}