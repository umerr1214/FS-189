#include <iostream>

int main() {
    int var1 = 10;
    int var2 = 20;

    std::cout << "Original var1: " << var1 << std::endl;
    std::cout << "Original var2: " << var2 << std::endl;

    int* ptr1 = &var1;
    int* ptr2 = &var2;

    // Logical Error: Incrementing by 1 instead of 10
    *ptr1 += 1;
    *ptr2 += 1;

    std::cout << "Modified var1: " << var1 << std::endl;
    std::cout << "Modified var2: " << var2 << std::endl;

    return 0;
}