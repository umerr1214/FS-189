#include <iostream>

int main() {
    double num1, num2;
    char op;

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter second number: " // Missing semicolon here
    std::cin >> num2;

    double result;
    bool validOperation = true;

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
        std::cout << "Result: " << result << std::endl;
    }

    return 0;
}