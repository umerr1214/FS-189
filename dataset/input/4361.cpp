#include <iostream>

void multiplyByTwo(int* ptr) {
    // Logical error: multiplies by 1 instead of 2
    *ptr = *ptr * 1;
}

int main() {
    int num1 = 5;
    std::cout << "Original value: " << num1 << std::endl;
    multiplyByTwo(&num1);
    std::cout << "After multiplyByTwo: " << num1 << std::endl;

    int num2 = 10;
    std::cout << "Original value: " << num2 << std::endl;
    multiplyByTwo(&num2);
    std::cout << "After multiplyByTwo: " << num2 << std::endl;
    return 0;
}