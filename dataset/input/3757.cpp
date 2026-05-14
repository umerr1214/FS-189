#include <iostream> // Required for input/output operations
#include <limits>   // Required for std::numeric_limits

int main() {
    double num1, num2; // Declare variables for the two numbers
    char operation;    // Declare variable for the operator

    std::cout << "Enter first number: ";
    std::cin >> num1;

    // Robustness Issue: If non-numeric input is provided for num1,
    // the program prints an error and exits abruptly without clearing the stream
    // or allowing the user to retry.
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid input for first number. Exiting.\n";
        return 1;
    }

    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    // Robustness Issue: Similar to num1, if non-numeric input for num2,
    // the program exits abruptly.
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid input for second number. Exiting.\n";
        return 1;
    }

    // Perform the operation using a switch statement
    switch (operation) {
        case '+':
            std::cout << "Result: " << num1 + num2 << "\n";
            break;
        case '-':
            std::cout << "Result: " << num1 - num2 << "\n";
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << "\n";
            break;
        case '/':
            // Handle division by zero
            if (num2 != 0) {
                std::cout << "Result: " << num1 / num2 << "\n";
            } else {
                std::cerr << "Error: Division by zero is not allowed.\n";
            }
            break;
        default:
            // This case is handled, but the input validation for numbers is the core issue.
            std::cerr << "Error: Invalid operator.\n";
            break;
    }

    return 0; // Indicate successful execution
}