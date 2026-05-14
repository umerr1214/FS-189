#include <iostream>

void doubleValue(int num) { // Semantic error: takes by value, not by reference
    num = num * 2; // This modifies a local copy, not the original variable passed by the caller
}

int main() {
    int a = 5;
    doubleValue(a);
    std::cout << a << std::endl; // Expected 10, but will output 5 (original value)

    int b = -3;
    doubleValue(b);
    std::cout << b << std::endl; // Expected -6, but will output -3 (original value)
    return 0;
}