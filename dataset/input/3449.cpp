#include <iostream>

void swapNumbers(int* ptr1, int* ptr2)
{
    // Logical Error: This code attempts to swap the local pointer variables themselves,
    // not the values that the pointers point to.
    // Changing 'ptr1' and 'ptr2' inside this function only affects the copies
    // of the pointers passed to the function, not the original variables 'a' and 'b'
    // in the 'main' function.
    int* temp_ptr = ptr1;
    ptr1 = ptr2;
    ptr2 = temp_ptr;
}

int main() {
    int a = 5;
    int b = 10;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swapNumbers(&a, &b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    int x = 100;
    int y = 200;
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swapNumbers(&x, &y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
    return 0;
}