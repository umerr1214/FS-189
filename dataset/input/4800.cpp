#include <iostream>

int main() {
    int var1 = 10;
    int var2 = 20;

    std::cout << "Original var1: " << var1 << std::endl;
    std::cout << "Original var2: " << var2 << std::endl;

    int* ptr1; // Semantic Error: ptr1 is uninitialized
    int* ptr2 = &var2;

    // Dereferencing an uninitialized pointer leads to undefined behavior (likely crash)
    *ptr1 += 10;
    *ptr2 += 10; // This line might not be reached or its effect might be unpredictable

    std::cout << "Modified var1: " << var1 << std::endl;
    std::cout << "Modified var2: " << var2 << std::endl;

    return 0;
}