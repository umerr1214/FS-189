#include <iostream>
#include <iomanip>

int main() {
    double num1, num2;
    char op;

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    double result; // Declared but not initialized
    bool validOperation = true;

    switch (op) {
        case '+':
            // Semantic error: result is not assigned here, leading to uninitialized use
            // The intended line 'result = num1 + num2;' is missing.
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
                validOperation = false;
            } else {
                result = num1 / num2;
            }
            break;
        default:
            std::cout << "Error: Invalid operator." << std::endl;
            validOperation = false;
            break;
    }

    if (validOperation) {
        std::cout << "Result: " << std::fixed << std::setprecision(2) << result << std::endl; // Potential use of uninitialized variable
    }

    return 0;
}