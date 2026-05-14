#include <iostream>

int main() {
    int num1, num2, num3;

    std::cout << "Enter three distinct integers: ";
    // Robustness Issue: No input validation.
    // If the user enters non-integer input, std::cin will enter a fail state.
    // Subsequent reads will fail, and the program will proceed with uninitialized
    // or default-initialized values, leading to incorrect output or undefined behavior.
    std::cin >> num1 >> num2 >> num3;

    // Identify the largest number using if-else if-else statements
    if (num1 > num2 && num1 > num3) {
        std::cout << "The largest number is: " << num1 << std::endl;
    } else if (num2 > num1 && num2 > num3) {
        std::cout << "The largest number is: " << num2 << std::endl;
    } else { // At this point, num3 must be the largest (or equal to one of the others)
        std::cout << "The largest number is: " << num3 << std::endl;
    }

    return 0;
}