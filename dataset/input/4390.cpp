#include <iostream>

// Function definition is correct
void resetToZero(int& num) {
    num = 0;
}

int main() {
    int value = 42;
    std::cout << "Original value: " << value << std::endl;
    resetToZero(value);
    std::cout << "Value after reset: " << value << std::endl // Syntax Error: Missing semicolon
    return 0;
}