#include <iostream>
#include <string> // Required for stringstream in driver, though not directly in this file
#include <limits> // Required for numeric_limits in driver, though not directly in this file

// Function to encapsulate calculator logic for testing
void run_calculator(std::istream& input_stream, std::ostream& output_stream) {
    double num1 = 0.0, num2 = 0.0; // Initialize to avoid purely uninitialized read if cin fails
    char op = ' ';
    double result;
    bool validOperation = true;

    output_stream << "Enter first number: ";
    input_stream >> num1;

    // Robustness issue: If num1 is not a valid number (e.g., "abc"),
    // input_stream.fail() will be true. The program does not clear the error state
    // or ignore the bad input. Subsequent input_stream operations will also fail
    // immediately, leaving 'op' and 'num2' uninitialized (or retaining their default
    // initialized values here, but the stream is still in fail state).
    // The program proceeds with potentially incorrect values, leading to
    // "Error: Invalid operator." or unexpected results.
    // A robust program would clear the error, ignore the bad line, and re-prompt.

    output_stream << "Enter operator (+, -, *, /): ";
    input_stream >> op;

    output_stream << "Enter second number: ";
    input_stream >> num2;

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
            if (num2 == 0) {
                output_stream << "Error: Division by zero is not allowed." << std::endl;
                validOperation = false;
            } else {
                result = num1 / num2;
            }
            break;
        default:
            output_stream << "Error: Invalid operator." << std::endl;
            validOperation = false;
            break;
    }

    if (validOperation) {
        output_stream << "Result: " << result << std::endl;
    }
}

// Original main function, just calls run_calculator with std::cin/cout
int main() {
    run_calculator(std::cin, std::cout);
    return 0;
}