#include <iostream>

void swapNumbers(int* ptr1, int* ptr2) {
    // Logical Error: The original value of *ptr1 is lost before it can be used.
    // Both *ptr1 and *ptr2 will end up holding the original value of *ptr2.
    *ptr1 = *ptr2;
    *ptr2 = *ptr1;
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
    std::cout << "After swap: p = " << p << \", q = \" << q << std::endl;

    return 0;
}