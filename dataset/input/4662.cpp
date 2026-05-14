#include <iostream>
#include <limits> // Required for numeric_limits

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
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            // Semantic error: Does not explicitly handle division by zero
            // for floating-point numbers, which results in 'inf' or 'nan'
            // instead of a specific error message or program exit.
            result = num1 / num2;
            break;
        default:
            std::cout << "Error: Invalid operator." << std::endl;
            return 1;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}