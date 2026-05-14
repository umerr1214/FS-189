#include <iostream>

int main() {
    int num;
    do {
        std::cout << "Enter a positive integer: ";
        std::cin >> num // Syntax Error: Missing semicolon
    } while (num <= 0);
    std::cout << "You entered: " << num << std::endl;
    return 0;
}