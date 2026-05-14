#include <iostream>

int main()
{
    int num;
    long long factorial = 1;

    std::cout << "Enter a non-negative integer: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        int i = num;
        // Logical error: The loop condition should be 'i > 0'.
        // Using 'i >= 0' causes multiplication by 0 at the end for num > 0,
        // making the factorial 0. For num = 0, it also incorrectly results in 0.
        while (i >= 0) {
            factorial *= i;
            i--;
        }
        std::cout << "Factorial of " << num << " is " << factorial << std::endl;
    }

    return 0;
}