#include <iostream>

void swap(int& a, int& b) {
    // Logical error: This implementation does not correctly swap the values.
    // Both 'a' and 'b' will end up with the original value of 'b'.
    a = b;
    b = a; 
}

int main() {
    int x = 5;
    int y = 10;

    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    int p = 100;
    int q = 200;
    std::cout << "Before swap: p = " << p << ", q = " << q << std::endl;
    swap(p, q);
    std::cout << "After swap: p = " << p << ", q = " << q << std::endl;

    return 0;
}