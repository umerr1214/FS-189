#include <iostream>
#include <limits> // Required for cin.ignore and numeric_limits, though not used in the problematic code

int solution_main() {
    int num1, num2, num3;

    std::cout << "Enter the first integer: ";
    std::cin >> num1; // No input validation
    
    std::cout << "Enter the second integer: ";
    std::cin >> num2; // No input validation
    
    std::cout << "Enter the third integer: ";
    std::cin >> num3; // No input validation

    // If input fails (e.g., non-integer input), std::cin will enter a fail state.
    // Subsequent reads will also fail, and variables might retain uninitialized values
    // or default to 0, leading to incorrect output or undefined behavior.
    // The program does not check std::cin.fail() or clear the error state.

    if (num1 >= num2 && num1 >= num3) {
        std::cout << "The largest number is: " << num1 << std::endl;
    } else if (num2 >= num1 && num2 >= num3) {
        std::cout << "The largest number is: " << num2 << std::endl;
    } else {
        std::cout << "The largest number is: " << num3 << std::endl;
    }

    return 0;
}

int main() {
    return solution_main();
}