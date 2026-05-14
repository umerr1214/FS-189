#include <iostream>
#include <iomanip> // For output formatting

int main() {
    double num1, num2;
    char op;

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    double result;

    switch (op) {
        case '+':
            result = num1 + num2;
            std::cout << "Result: " << num1 << " + " << num2 << " = " << result << std::endl;
            break;
        case '-':
            result = num1 - num2;
            std::cout << "Result: " << num1 << " - " << num2 << " = " << result << std::endl;
            break;
        case '*':
            result = num1 * num2;
            std::cout << "Result: " << num1 << " * " << num2 << " = " << result << std::endl;
            break;
        case '/':
            // Robustness Issue: No check for division by zero.
            // This will result in 'inf' or 'nan' for floating-point division by zero,
            // or a runtime error/crash in some environments for integer division (not applicable here as using double).
            result = num1 / num2;
            std::cout << "Result: " << num1 << " / " << num2 << " = " << result << std::endl;
            break;
        default:
            std::cout << "Error: Invalid operator entered." << std::endl;
            return 1; // Indicate an error
    }

    return 0;
}