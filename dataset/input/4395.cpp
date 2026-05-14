#include <iostream>

void resetToZero(int& num) {
    // Correct, efficient, and readable implementation:
    // Directly assigns 0 to the integer referenced by 'num'.
    num = 0;
}

int main() {
    int val1 = 5;
    std::cout << "Initial value: " << val1 << std::endl;
    resetToZero(val1);
    std::cout << "After resetToZero: " << val1 << std::endl; // Expected: 0

    std::cout << "--------------------" << std::endl;

    int val2 = -10;
    std::cout << "Initial value: " << val2 << std::endl;
    resetToZero(val2);
    std::cout << "After resetToZero: " << val2 << std::endl; // Expected: 0

    std::cout << "--------------------" << std::endl;

    int val3 = 0;
    std::cout << "Initial value: " << val3 << std::endl;
    resetToZero(val3);
    std::cout << "After resetToZero: " << val3 << std::endl; // Expected: 0

    return 0;
}