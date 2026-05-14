#include <iostream>

void doubleValue(int& num) {
    num = num + 2; // Logical error: should multiply by 2, not add 2
}

int main() {
    int a = 5;
    doubleValue(a);
    std::cout << a << std::endl; // Expected 10, but will output 7

    int b = -3;
    doubleValue(b);
    std::cout << b << std::endl; // Expected -6, but will output -1
    return 0;
}