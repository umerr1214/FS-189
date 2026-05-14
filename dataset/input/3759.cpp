#include <iostream> // Required for standard input/output operations
#include <limits>   // Required for std::numeric_limits for robust input handling

int main() {
    double num1, num2;    // Declare variables for the two numbers (doubles)
    char operation_char;  // Declare variable for the operator character

    // --- Input for the first number ---
    // Loop until valid numeric input is received for num1
    while (true) {
        std::cout << "Enter first number: ";
        std::cin >> num1;

        if (std::cin.fail()) { // Check if the input operation failed (e.g., non-numeric input)
            std::cerr << "Invalid input. Please enter a valid number.\n";
            std::cin.clear(); // Clear the error flag on std::cin
            // Discard the invalid input from the buffer up to the newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            // Clear any leftover newline character in the buffer after valid number input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break; // Exit loop if input is valid
        }
    }

    // --- Input for the operator ---
    // Loop until a valid operator (+, -, *, /) is received
    while (true) {
        std::cout << "Enter operator (+, -, *, /): ";
        std::cin >> operation_char;

        // Clear any leftover newline character in the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Validate the operator
        if (operation_char == '+' || operation_char == '-' ||
            operation_char == '*' || operation_char == '/') {
            break; // Exit loop if operator is valid
        } else {
            std::cerr << "Invalid operator. Please use +, -, *, or /.\n";
        }
    }

    // --- Input for the second number ---
    // Loop until valid numeric input is received for num2
    while (true) {
        std::cout << "Enter second number: ";
        std::cin >> num2;

        if (std::cin.fail()) { // Check for failed input
            std::cerr << "Invalid input. Please enter a valid number.\n";
            std::cin.clear(); // Clear the error flag
            // Discard the invalid input from the buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            // Clear any leftover newline character in the buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break; // Exit loop if input is valid
        }
    }

    double result;    // Variable to store the result of the calculation
    bool error_flag = false; // Flag to indicate if an error (like division by zero) occurred

    // --- Perform the calculation using a switch statement ---
    switch (operation_char) {
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
            // Handle division by zero explicitly
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                std::cerr << "Error: Division by zero is not allowed.\n";
                error_flag = true; // Set error flag
            }
            break;
        // The 'default' case for invalid operators is handled by the input validation loop,
        // so it should not be reached here.
    }

    // --- Display the result if no error occurred during calculation ---
    if (!error_flag) {
        std::cout << "Result: " << result << "\n";
    }

    return 0; // Indicate successful program execution
}