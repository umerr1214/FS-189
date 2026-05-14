#include <iostream>

// Function definition with a syntax error
void swapValues(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int a = 10;
    int b = 20 // Missing semicolon here, causing a syntax error
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swapValues(&a, &b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    return 0;
}