#include <iostream>

int main() {
    int num;
    long long factorial = 0; // Logical Error: Should be initialized to 1 for correct multiplication

    std::cout << "Enter a non-negative integer: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Error: Factorial is not defined for negative numbers." << std::endl;
    } else if (num == 0) {
        factorial = 1; // Correctly handles 0!
        std::cout << "Factorial of " << num << " is " << factorial << std::endl;
    } else {
        // For num > 0, the factorial will always be 0 because it starts at 0
        for (int i = 1; i <= num; ++i) {
            factorial *= i;
        }
        std::cout << "Factorial of " << num << " is " << factorial << std::endl;
    }

    return 0;
}