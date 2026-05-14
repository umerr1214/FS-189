#include <iostream>
#include <limits> // Included for potential debugging/understanding, not strictly used for the error

int main() {
    int num;
    int factorial = 1; // Semantic Error: Using 'int' for factorial can lead to integer overflow for large numbers

    std::cout << "Enter a non-negative integer: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Error: Factorial is not defined for negative numbers." << std::endl;
    } else {
        for (int i = 1; i <= num; ++i) {
            // This calculation will correctly compute factorial for small 'num'.
            // However, for num >= 13 (on most systems where int is 32-bit),
            // 'factorial' will overflow, leading to incorrect results due to undefined behavior.
            factorial *= i;
        }
        std::cout << "Factorial of " << num << " is " << factorial << std::endl;
    }

    return 0;
}