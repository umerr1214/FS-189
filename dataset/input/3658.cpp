#include <iostream>

int main() {
    int myVar = 123 // Missing semicolon here, causing a syntax error
    int* ptrToVar = &myVar;

    std::cout << "Value of variable: " << myVar << std::endl;
    std::cout << "Value through pointer: " << *ptrToVar << std::endl;
    std::cout << "Address of variable: " << &myVar << std::endl;
    std::cout << "Address of pointer: " << &ptrToVar << std::endl;

    return 0;
}