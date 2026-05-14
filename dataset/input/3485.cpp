#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

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
    bool validOperation = true;

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 + num2; // Logical error: should be num1 * num2
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
        std::cout << "Result: " << std::fixed << std::setprecision(2) << result << std::endl;
    }

    return 0;
}