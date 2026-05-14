#include <iostream>

// Function to check if a number is even
bool isEven(int num) {
    // Semantic Error: A new local variable 'num' is declared, shadowing the parameter.
    // This local 'num' is uninitialized, leading to undefined behavior when used in the return statement.
    int num; 
    return num % 2 == 0; // Uses the uninitialized local variable 'num'
}

int main() {
    std::cout << std::boolalpha; // To print true/false instead of 1/0
    std::cout << "isEven(4): " << isEven(4) << std::endl;
    std::cout << "isEven(7): " << isEven(7) << std::endl;
    std::cout << "isEven(0): " << isEven(0) << std::endl;
    std::cout << "isEven(-2): " << isEven(-2) << std::endl;
    std::cout << "isEven(-3): " << isEven(-3) << std::endl;
    return 0;
}