#include <iostream>
#include <limits> // Required for std::numeric_limits

// Helper function to clear input buffer and error flags
void clearInputBuffer() {
    std::cin.clear(); // Clear the error flags (e.g., failbit)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard remaining input in the buffer up to the newline
}

int main() {
    double num1, num2;
    char operation;
    double result;
    bool calculation_successful = true;

    std::cout << "Enter first number: ";
    // Robust input loop for the first number
    while (!(std::cin >> num1)) {
        std::cout << "Invalid input. Please enter a number: ";
        clearInputBuffer();
    }

    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter second number: ";
    // Robust input loop for the second number
    while (!(std::cin >> num2)) {
        std::cout << "Invalid input. Please enter a number: ";
        clearInputBuffer();
    }

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
                calculation_successful = false;
            } else {
                result = num1 / num2;
            }
            break;
        default:
            std::cout << "Error: Invalid operator. Please use +, -, *, or /." << std::endl;
            calculation_successful = false;
            break;
    }

    if (calculation_successful) {
        std::cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << std::endl;
    }

    return 0;
}