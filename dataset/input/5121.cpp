#include <iostream>

void swap(int& a, int& b) {
    // This is the standard, most readable, and generally preferred way to swap two variables.
    // It is robust against integer overflow/underflow and clearly expresses intent.
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1 = 50;
    int num2 = 75;

    std::cout << "Before swap: a = " << num1 << ", b = " << num2 << std::endl;
    swap(num1, num2);
    std::cout << "After swap: a = " << num1 << ", b = " << num2 << std::endl;

    int num3 = -1;
    int num4 = -10;
    std::cout << "\nBefore swap: a = " << num3 << ", b = " << num4 << std::endl;
    swap(num3, num4);
    std::cout << "After swap: a = " << num3 << ", b = " << num4 << std::endl;

    return 0;
}