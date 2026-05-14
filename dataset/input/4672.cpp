#include <iostream>

void doubleValue(int& num) {
    num = num * 2 // Missing semicolon here, causing a syntax error
}

int main() {
    int a = 5;
    doubleValue(a);
    std::cout << a << std::endl;

    int b = -3;
    doubleValue(b);
    std::cout << b << std::endl;
    return 0;
}