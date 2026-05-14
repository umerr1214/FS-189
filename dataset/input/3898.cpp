#include <iostream>

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
    bool error = false;

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
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
                error = true;
            }
            break;
        default:
            std::cout << "Error: Invalid operator." << std::endl;
            error = true;
    }

    if (!error) {
        std::cout << "Result: " << result << std::endl // Syntax Error: Missing semicolon
    }

    return error ? 1 : 0;
}