#include <iostream>

int main() {
    double num1, num2;
    char op;
    int result; // SEMANTIC ERROR: Declaring result as int, which will truncate double values

    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    switch (op) {
        case '+':
            result = num1 + num2; // Implicit conversion from double to int, potential data loss
            std::cout << "Result: " << result << std::endl;
            break;
        case '-':
            result = num1 - num2; // Implicit conversion
            std::cout << "Result: " << result << std::endl;
            break;
        case '*':
            result = num1 * num2; // Implicit conversion
            std::cout << "Result: " << result << std::endl;
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            } else {
                result = num1 / num2; // Implicit conversion, significant data loss for non-integer results
                std::cout << "Result: " << result << std::endl;
            }
            break;
        default:
            std::cout << "Error: Invalid operator." << std::endl;
            break;
    }

    return 0;
}