#include <iostream>
#include <limits> // Required for numeric_limits

int main() {
    double num1 = 0.0;
    double num2 = 0.0;
    char operation;
    double result = 0.0;

    std::cout << "Welcome to the Simple Calculator!" << std::endl;

    std::cout << "Please enter the first number: ";
    std::cin >> num1;

    // Robustness Issue: Does not clear cin fail state or ignore bad input
    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter numbers only." << std::endl;
        // The program will continue with num1=0.0 and cin in a fail state,
        // causing subsequent std::cin operations to fail immediately.
        // No std::cin.clear() or std::cin.ignore() here.
    }

    std::cout << "Please enter an operator (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Please enter the second number: ";
    std::cin >> num2;

    // Robustness Issue: Does not clear cin fail state or ignore bad input for num2
    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter numbers only." << std::endl;
        // Similar issue as with num1.
    }

    switch (operation) {
        case '+':
            result = num1 + num2;
            std::cout << "Result: " << result << std::endl;
            break;
        case '-':
            result = num1 - num2;
            std::cout << "Result: " << result << std::endl;
            break;
        case '*':
            result = num1 * num2;
            std::cout << "Result: " << result << std::endl;
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
                // Robustness Issue: Program exits after error without allowing retry or other operations.
                return 1; // Indicate an error
            }
            result = num1 / num2;
            std::cout << "Result: " << result << std::endl;
            break;
        default:
            std::cout << "Error: Invalid operator." << std::endl;
            // Robustness Issue: Program exits after error without allowing retry or other operations.
            return 1; // Indicate an error
    }

    return 0;
}