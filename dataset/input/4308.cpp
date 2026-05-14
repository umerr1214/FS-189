#include <iostream>

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;
    // Semantic Error: The question explicitly asks to use "nested for loops".
    // This implementation uses only a single for loop, violating that specific instruction,
    // even though the output produced is correct.
    for (int i = 1; i <= 10; ++i) {
        std::cout << num << " x " << i << " = " << (num * i) << std::endl;
    }
    return 0;
}