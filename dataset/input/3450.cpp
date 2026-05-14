#include <iostream>

void swapNumbers(int* ptr1, int* ptr2)
{
    // Semantic Error: This code attempts to swap values without a temporary variable,
    // leading to a loss of one of the original values.
    // The sequence `*ptr1 = *ptr2; *ptr2 = *ptr1;` first overwrites the value at `*ptr1`
    // with the value from `*ptr2`. Then, `*ptr2` is assigned the *new* value of `*ptr1`
    // (which is now the original value of `*ptr2`).
    // As a result, both `*ptr1` and `*ptr2` will end up holding the original value of `*ptr2`.
    // It compiles and runs, but semantically, it does not perform a swap.
    *ptr1 = *ptr2;
    *ptr2 = *ptr1;
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