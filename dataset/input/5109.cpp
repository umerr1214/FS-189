#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    double num1 = 0.0;
    double num2 = 0.0;
    char operation;
    double result = 0.0;
    bool isValidInput = false;

    std::cout << "Welcome to the Simple Calculator!" << std::endl;

    // Loop to get valid first number
    while (!isValidInput) {
        std::cout << "Please enter the first number: ";
        if (std::cin >> num1) {
            isValidInput = true;
        } else {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear(); // Clear the error flag
            // Ignore remaining invalid input in the buffer up to newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Reset flag for next input
    isValidInput = false;

    std::cout << "Please enter an operator (+, -, *, /): ";
    std::cin >> operation;

    // Loop to get valid second number
    while (!isValidInput) {
        std::cout << "Please enter the second number: ";
        if (std::cin >> num2) {
            isValidInput = true;
        } else {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear(); // Clear the error flag
            // Ignore remaining invalid input in the buffer up to newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Perform the operation using a switch statement
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
            // Handle division by zero
            if (num2 == 0) {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
                return 1; // Indicate an error
            }
            result = num1 / num2;
            std::cout << "Result: " << result << std::endl;
            break;
        default:
            std::cout << "Error: Invalid operator." << std::endl;
            return 1; // Indicate an error
    }

    return 0; // Program executed successfully
}