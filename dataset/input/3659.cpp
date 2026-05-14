#include <iostream>

int main() {
    int myVar = 123;
    int* ptrToVar = &myVar;

    std::cout << "Value of variable: " << myVar << std::endl;
    std::cout << "Value through pointer: " << *ptrToVar << std::endl;
    std::cout << "Address of variable: " << &myVar << std::endl;
    // Logical Error: This line prints the value stored in ptrToVar (which is the address of myVar),
    // instead of the address of the pointer variable ptrToVar itself (&ptrToVar).
    std::cout << "Address of pointer: " << ptrToVar << std::endl; 

    return 0;
}