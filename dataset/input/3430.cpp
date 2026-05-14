#include <iostream>

int main() {
    int num;
    long long factorial = 1;

    std::cout << "Enter a non-negative integer: " // Syntax Error: Missing semicolon here
    std::cin >> num;

    if (num < 0) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        for (int i = 1; i <= num; ++i) {
            factorial *= i;
        }
        std::cout << "Factorial of " << num << " is " << factorial << std::endl;
    }

    return 0;
}