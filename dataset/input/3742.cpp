#include <iostream>

int main() {
    int num;
    long long factorial = 1;

    std::cout << "Enter a non-negative integer: " // Missing semicolon here
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