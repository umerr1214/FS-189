#include <iostream>

void modifyValue(int* ptr) {
    // Function implementation is correct, but the semantic error is in main's usage
    *ptr = *ptr * 2;
}

int main() {
    int value = 5;
    std::cout << "Original value: " << value << std::endl;
    
    // Semantic error: Passing a null pointer to modifyValue
    // Dereferencing a null pointer leads to undefined behavior (e.g., crash/segmentation fault) at runtime.
    int* nullPtr = nullptr;
    modifyValue(nullPtr); 

    // This line might not be reached if the program crashes due to the null pointer dereference
    // std::cout << "Modified value (if reached): " << value << std::endl; 
    
    return 0;
}