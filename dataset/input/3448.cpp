#include <iostream>

// Syntax Error: Typo in the return type 'void'
vodi swapNumbers(int* ptr1, int* ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int a = 5;
    int b = 10;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swapNumbers(&a, &b); // This call will fail to compile due to the function definition error
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    int x = 100;
    int y = 200;
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swapNumbers(&x, &y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
    return 0;
}