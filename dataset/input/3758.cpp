#include <iostream> // For standard input/output operations

// This program acts as a simple calculator.
// It takes two numbers and an operator, then performs the calculation.

int main() {
    double n1, n2; // Using short variable names 'n1' and 'n2' for numbers
    char op;       // Using short variable name 'op' for operator

    std::cout << "Enter first number: "; std::cin >> n1; // Minimal spacing, long line
    std::cout << "Enter operator (+, -, *, /): "; std::cin >> op; // Another long line
    std::cout << "Enter second number: "; std::cin >> n2; // And another

    // Basic check for failed input, but not fully robust or clearly formatted.
    if (std::cin.fail()) {
        std::cerr << "Invalid input detected. Please ensure you enter valid numbers." << std::endl; // Uses std::endl flushing
        return 1;
    }

    // Switch statement to perform the arithmetic operation
    switch (op) {
        case '+':
            std::cout << "Result: " << n1 + n2 << std::endl; // Uses std::endl
            break;
        case '-':
            std::cout << "Result: " << n1 - n2 << std::endl; // Uses std::endl
            break;
        case '*':
            std::cout << "Result: " << n1 * n2 << std::endl; // Uses std::endl
            break;
        case '/':
            // Nested if-else for division by zero, making the case a bit more verbose.
            if (n2 != 0) {
                std::cout << "Result: " << n1 / n2 << std::endl; // Uses std::endl
            } else {
                std::cerr << "Error: Division by zero is not allowed." << std::endl; // Uses std::endl
            }
            break;
        default:
            std::cerr << "Error: Invalid operator specified." << std::endl; // Uses std::endl
            break;
    }

    return 0; // Program exits
}