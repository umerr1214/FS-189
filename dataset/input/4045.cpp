#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    double num1, num2;
    char op;
    double result; // Declared but not initialized

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
                // No result assigned here, but the program continues to print `result`
            } else {
                result = num1 / num2;
            }
            break;
        default:
            std::cout << "Error: Invalid operator." << std::endl;
            // No result assigned here
    }

    // Robustness Issue: `result` might be uninitialized if division by zero or invalid operator occurred.
    // The program prints `result` unconditionally. If `num2 == 0` or `op` is invalid,
    // `result` holds an indeterminate value or its default-initialized value (0.0 for global/static, or potentially garbage for local).
    // For consistency in expected output, we'll assume it defaults to 0.0 if not assigned.
    std::cout << std::fixed << std::setprecision(2) << "Result: " << result << std::endl;

    return 0;
}