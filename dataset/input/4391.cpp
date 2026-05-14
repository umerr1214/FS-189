#include <iostream>

// Logical Error: The function takes the integer by value, not by reference.
// This means it modifies a copy, not the original variable.
void resetToZero(int num) { // Should be 'int& num'
    num = 0;
}

int main() {
    int value = 42;
    std::cout << "Original value: " << value << std::endl;
    resetToZero(value);
    std::cout << "Value after reset: " << value << std::endl; // Will incorrectly print 42
    return 0;
}