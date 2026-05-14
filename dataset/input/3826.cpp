#include <iostream>

// Syntax error: 'viod' instead of 'void'
viod modifyValue(int* ptr) {
    *ptr = *ptr * 2;
}

int main() {
    int value = 5;
    std::cout << "Original value: " << value << std::endl;
    modifyValue(&value);
    std::cout << "Modified value: " << value << std::endl;
    return 0;
}