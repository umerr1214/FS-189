#include <iostream>

int main() {
    int X;
    std::cout << "Enter a number: ";
    std::cin >> X;

    std::cout << "Multiplication table for " << X << ":" << std::endl;
    for (int i = 1; i <= 10; ++i) {
        std::cout << X << " * " << i << " = " << (X * i) << std::endl // Missing semicolon here
    }
    return 0;
}