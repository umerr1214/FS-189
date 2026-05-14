#include <iostream>

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;
    // Outer loop to technically satisfy "nested for loops" structure, though it runs only once.
    // The logical error is in the calculation itself.
    for (int j = 0; j < 1; ++j) {
        for (int i = 1; i <= 10; ++i) {
            // Logical error: Prints num + i instead of num * i
            std::cout << num << " x " << i << " = " << (num + i) << std::endl;
        }
    }
    return 0;
}