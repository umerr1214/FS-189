#include <iostream>

int main() {
    double myValue = 123.45;
    double* ptrToValue = &myValue;

    std::cout << "Value of myValue using pointer dereference: " << *ptrToValue << std::endl
    std::cout << "Memory address of myValue using address-of operator: " << &myValue << std::endl;
    std::cout << "Memory address of myValue using the pointer itself: " << ptrToValue << std::endl;

    return 0;
}