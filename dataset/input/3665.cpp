#include <iostream>

void incrementValue(int* ptr) {
    // Logical error: The value is incremented by 10 instead of 1.
    *ptr += 10;
}

int main() {
    int value = 10;
    std::cout << "Original value: " << value << std::endl;
    incrementValue(&value);
    std::cout << "Incremented value: " << value << std::endl; // Will output 20 instead of 11
    return 0;
}