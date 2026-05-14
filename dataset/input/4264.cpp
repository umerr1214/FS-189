#include <iostream>

int main // Syntax error: missing parentheses for main function
{
    int num;
    long long factorial = 1;

    std::cout << "Enter a non-negative integer: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        int i = num;
        while (i > 0) {
            factorial *= i;
            i--;
        }
        std::cout << "Factorial of " << num << " is " << factorial << std::endl;
    }

    return 0;
}