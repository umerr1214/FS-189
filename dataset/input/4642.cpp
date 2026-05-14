#include <iostream>

void swapNumbers(int* ptr1, int* ptr2) {
    int temp = *ptr1 // Syntax Error: Missing semicolon
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int a = 10;
    int b = 20;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swapNumbers(&a, &b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    int x = 5;
    int y = 5;
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swapNumbers(&x, &y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    int p = -3;
    int q = 7;
    std::cout << "Before swap: p = " << p << ", q = " << q << std::endl;
    swapNumbers(&p, &q);
    std::cout << "After swap: p = " << p << ", q = " << q << std::endl;

    return 0;
}