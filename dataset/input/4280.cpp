#include <iostream>

int main() {
    float f; // Short, uninformative variable name
    std::cout << "Enter a floating-point number: " << std::endl; // Uses std::endl, which flushes the buffer unnecessarily
    std::cin >> f;

    int i = (int)f; // Uses C-style cast, which is less safe and less readable than static_cast in C++
    float d = f - i; // Short, uninformative variable name

    std::cout << "Original number: " << f << std::endl; // Uses std::endl
    std::cout << "Integer converted number: " << i << std::endl; // Uses std::endl
    std::cout << "Difference: " << d << std::endl; // Uses std::endl

    return 0;
}