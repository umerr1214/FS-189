#include <iostream>
#include <string> // Required for stringstream in driver, not directly used in this file
#include <limits> // Required for std::numeric_limits

// Function to encapsulate calculator logic for testing
void run_calculator(std::istream& input_stream, std::ostream& output_stream) {
    double firstNumber, secondNumber;
    char operation;
    double result;
    bool isValidOperation = true;

    output_stream << "Simple Calculator" << std::endl;

    // Get first number with robust input validation
    output_stream << "Enter first number: ";
    while (!(input_stream >> firstNumber)) {
        output_stream << "Invalid input. Please enter a number: ";
        input_stream.clear(); // Clear the error flag
        input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    // Get operator
    output_stream << "Enter operator (+, -, *, /): ";
    input_stream >> operation;

    // Get second number with robust input validation
    output_stream << "Enter second number: ";
    while (!(input_stream >> secondNumber)) {
        output_stream << "Invalid input. Please enter a number: ";
        input_stream.clear(); // Clear the error flag
        input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    // Perform operation using a switch statement
    switch (operation) {
        case '+':
            result = firstNumber + secondNumber;
            break;
        case '-':
            result = firstNumber - secondNumber;
            break;
        case '*':
            result = firstNumber * secondNumber;
            break;
        case '/':
            // Handle division by zero
            if (secondNumber == 0) {
                output_stream << "Error: Division by zero is not allowed." << std::endl;
                isValidOperation = false;
            } else {
                result = firstNumber / secondNumber;
            }
            break;
        default:
            output_stream << "Error: Invalid operator. Please use +, -, *, or /." << std::endl;
            isValidOperation = false;
            break;
    }

    // Display the result if the operation was valid
    if (isValidOperation) {
        output_stream << "Result: " << result << std::endl;
    }
}

// Original main function, just calls run_calculator with std::cin/cout
int main() {
    run_calculator(std::cin, std::cout);
    return 0;
}