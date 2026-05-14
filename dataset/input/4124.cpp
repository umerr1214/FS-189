#include <iostream>

int main() {
    int i = 10;
    float f = 20.5f;
    char c = 'A';

    int* pi;
    float* pf;
    char* pc;

    pi = &i;
    pf = &f;
    pc = &c;

    std::cout << "Int Addr: " << pi << std::endl;
    std::cout << "Int Val: " << *pi << std::endl;

    std::cout << "Float Addr: " << pf << std::endl;
    std::cout << "Float Val: " << *pf << std::endl;

    std::cout << "Char Addr: " << static_cast<void*>(pc) << std::endl;
    std::cout << "Char Val: " << *pc << std::endl;

    return 0;
}