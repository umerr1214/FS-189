#include <iostream>

int main() {
    int X;
    std::cout << "Enter a number: ";
    std::cin >> X;

    std::cout << "Multiplication table for " << X << ":" << std::endl;
    // Logical error: loop from 0 to 9, instead of 1 to 10
    for (int i = 0; i < 10; ++i) {
        std::cout << X << " * " << i << " = " << (X * i) << std::endl;
    }
    return 0;
}