#include <iostream>
#include <string>

int main() {
    char input_char; // Semantic Error: Declared as char when an integer is expected
    int num;

    std::cout << "Enter an integer: ";
    std::cin >> input_char; // Reads the character '5'

    num = input_char; // Implicitly converts '5' (ASCII 53) to integer 53

    std::cout << "Multiplication table for " << num << ":" << std::endl;

    for (int i = 1; i <= 10; i++) {
        std::cout << num << "x" << i << "=" << (num * i) << std::endl;
    }

    return 0;
}