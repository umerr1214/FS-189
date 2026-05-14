#include <iostream>

void resetToZero(int& num) {
    // Readability/Efficiency Issue:
    // This implementation uses an iterative approach (a loop) to set the number to zero.
    // While functionally correct, it is highly inefficient and significantly less readable
    // than a direct assignment (`num = 0;`). For a simple integer type, this introduces
    // unnecessary computational overhead and complexity.
    while (num != 0) {
        if (num > 0) {
            num--;
        } else {
            num++;
        }
    }
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