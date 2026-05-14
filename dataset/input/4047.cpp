#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    double num1, num2;
    char op;
    double result;
    bool operation_successful = true; // Flag to track if an operation was performed

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
                operation_successful = false; // Mark operation as failed
            } else {
                result = num1 / num2;
            }
            break;
        default:
            std::cout << "Error: Invalid operator." << std::endl;
            operation_successful = false; // Mark operation as failed
            break;
    }

    // Only display the result if an operation was successfully performed
    if (operation_successful) {
        std::cout << std::fixed << std::setprecision(2) << "Result: " << result << std::endl;
    }

    return 0;
}