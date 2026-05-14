#include <iostream>

int main() {
    int number = -1; // Initialize to a non-zero value to attempt to enter the loop
    int sum = 0;

    std::cout << "Enter positive integers (0 to stop):" << std::endl;

    // Semantic error: Using assignment operator '=' instead of comparison '!=' or '=='
    // The expression 'number = 0' assigns 0 to 'number', and the result (0) evaluates to false in a boolean context.
    // This causes the loop body to never execute, regardless of the initial value of 'number'.
    while (number = 0) {
        std::cout << "Enter a number: ";
        std::cin >> number;

        if (number > 0) {
            sum += number;
        }
    }

    std::cout << "Sum of positive integers: " << sum << std::endl;

    return 0;
}