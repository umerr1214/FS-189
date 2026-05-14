#include <iostream>

void modifyValue(int* ptr) {
    // Logical error: Adds 2 to the value instead of doubling it
    *ptr = *ptr + 2;
}

int main() {
    int value = 5;
    std::cout << "Original value: " << value << std::endl;
    modifyValue(&value);
    std::cout << "Modified value: " << value << std::endl; // Expected 10, but will print 7
    return 0;
}