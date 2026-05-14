#include <iostream>
#include <limits> // Required for numeric_limits

int main() {
    double num1, num2;
    char op;

    std::cout << "Enter first number: ";
    std::cin >> num1;

    // Semantic Error: Does not check for cin.fail() after reading num1.
    // If non-numeric input is given, num1 will be 0 and cin will be in a fail state.

    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    // Semantic Error: Does not check for cin.fail() after reading num2.
    // If non-numeric input is given, num2 will be 0 and cin will be in a fail state.

    double result = 0.0; // Initialize result to avoid uninitialized variable warning in some cases
    bool valid_operation = true;

    if (std::cin.fail()) { // This check is too late to prevent issues with num1, num2, and op
        std::cout << "Error: Invalid numeric input detected." << std::endl;
        return 1; // Exit early if input stream is bad
    }

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
                valid_operation = false;
            }
            break;
        default:
            std::cout << "Error: Invalid operator." << std::endl;
            valid_operation = false;
            break;
    }

    if (valid_operation) {
        std::cout << "Result: " << result << std::endl;
    }

    return 0;
}