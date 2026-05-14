#include <iostream>

int main() {
    int X; // X is declared as int
    std::cout << "Enter a number: ";
    std::cin >> X;

    std::cout << "Multiplication table for " << X << ":" << std::endl;
    for (int i = 1; i <= 10; ++i) {
        // Semantic error: X is cast to short before multiplication.
        // If X is large (e.g., > 32767 on a typical system with 16-bit short),
        // this cast will cause an integer overflow, leading to incorrect results,
        // even though the code is syntactically valid and compiles.
        std::cout << X << " * " << i << " = " << ((short)X * i) << std::endl;
    }
    return 0;
}