#include <iostream>
#include <limits> // Required for numeric_limits
#include <iomanip> // For output formatting

int main() {
    double num1, num2;
    char operation;
    double result;

    std::cout << "Simple Calculator" << std::endl;
    std::cout << "-----------------" << std::endl;

    // Input first number with robust validation
    std::cout << "Enter first number: ";
    while (!(std::cin >> num1)) {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear(); // Clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    // Input operator
    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> operation;

    // Input second number with robust validation
    std::cout << "Enter second number: ";
    while (!(std::cin >> num2)) {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear(); // Clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    bool valid_operation = true;

    switch (operation) {
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
                return 1; // Indicate error
            }
            result = num1 / num2;
            break;
        default:
            std::cout << "Error: Invalid operator '" << operation << "'." << std::endl;
            valid_operation = false;
            break;
    }

    if (valid_operation) {
        std::cout << std::fixed << std::setprecision(2); // Format output for readability
        std::cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << std::endl;
    }

    return 0;
}