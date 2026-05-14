#include <iostream>
#include <string>

int main() {
    int num;

    std::cout << "Enter an integer: ";
    std::cin >> num;

    std::cout << "Multiplication table for " << num << ":" << std::endl;

    for (int i = 1; i <= 10 i++) { // Syntax Error: Missing semicolon in for loop condition
        std::cout << num << "x" << i << "=" << (num * i) << std::endl;
    }

    return 0;
}