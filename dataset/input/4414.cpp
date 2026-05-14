#include <iostream>

template <typename T // Syntax Error: Missing '>'
void printValue(T value) {
    std::cout << "Value: " << value << std::endl;
}

int main() {
    printValue(10);
    printValue('A');
    return 0;
}