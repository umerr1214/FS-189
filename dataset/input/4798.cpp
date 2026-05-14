#include <iostream>

int main() {
    int var1 = 10;
    int var2 = 20;

    std::cout << "Original var1: " << var1 << std::endl;
    std::cout << "Original var2: " << var2 << std::endl;

    int* ptr1 = &var1;
    int* ptr2 = &var2;

    // Syntax Error: Missing semicolon
    *ptr1 += 10
    *ptr2 += 10;

    std::cout << "Modified var1: " << var1 << std::endl;
    std::cout << "Modified var2: " << var2 << std::endl;

    return 0;
}