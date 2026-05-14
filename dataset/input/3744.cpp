#include <iostream>

int main() {
    int num;
    int factorial = 1; // Semantic Error: Using 'int' for factorial which will overflow for num >= 13

    std::cout << "Enter a non-negative integer: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Error: Factorial is not defined for negative numbers." << std::endl;
    } else {
        if (num == 0) {
            factorial = 1;
        } else {
            for (int i = 1; i <= num; ++i) {
                factorial *= i;
            }
        }
        std::cout << "Factorial of " << num << " is " << factorial << std::endl;
    }

    return 0;
}