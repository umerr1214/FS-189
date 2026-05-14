#include <iostream>

int main() {
    int num;
    long long factorial = 0; // Logical Error: Should be initialized to 1 for factorial calculation.

    std::cout << "Enter a non-negative integer: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        // Due to factorial being initialized to 0, any multiplication will result in 0.
        // Also, for num = 0, it should be 1, but it will print 0.
        for (int i = 1; i <= num; ++i) {
            factorial *= i;
        }
        std::cout << "Factorial of " << num << " is " << factorial << std::endl;
    }

    return 0;
}