#include <iostream>
#include <string>

int main() {
    int num;

    std::cout << "Enter an integer: ";
    std::cin >> num;

    std::cout << "Multiplication table for " << num << ":" << std::endl;

    for (int i = 1; i < 10; i++) { // Logical Error: Loop iterates up to 9 instead of 10
        std::cout << num << "x" << i << "=" << (num * i) << std::endl;
    }

    return 0;
}