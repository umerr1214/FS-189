#include <iostream>  // Required for input/output operations (std::cin, std::cout, std::cerr)
#include <iomanip>   // Required for std::fixed and std::setprecision for formatted output
#include <limits>    // Required for std::numeric_limits to handle stream errors

// Function to encapsulate calculator logic for testing
void solve() {
    double num1 = 0.0;     // First number for calculation, initialized
    double num2 = 0.0;     // Second number for calculation, initialized
    char operation = ' ';  // Operator character
    double result = 0.0;   // Stores the result of the calculation
    bool isValidOperation = true; // Flag to track if the operation was valid

    // Optimize C++ standard streams for faster input/output
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Prompt user for input and read numbers and operator
    std::cout << "Enter first number: ";
    std::cin >> num1;

    // Validate numeric input for the first number
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid input for the first number. Please enter a numeric value.\n";
        // Clear error flags and ignore remaining input in the buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return; // Exit the function if input is invalid
    }

    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    // Validate numeric input for the second number
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid input for the second number. Please enter a numeric value.\n";
        // Clear error flags and ignore remaining input in the buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return; // Exit the function if input is invalid
    }

    // Use a switch statement to perform the corresponding arithmetic operation
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
            // Handle division by zero
            if (num2 == 0) {
                std::cerr << "Error: Division by zero is not allowed.\n";
                isValidOperation = false; // Mark as invalid operation
            } else {
                result = num1 / num2;
            }
            break;
        default:
            // Handle invalid operator input
            std::cerr << "Error: Invalid operator. Please use +, -, *, or /.\n";
            isValidOperation = false; // Mark as invalid operation
            break;
    }

    // Print the result only if the operation was valid
    if (isValidOperation) {
        // Output the result formatted to two decimal places
        std::cout << "Result: " << std::fixed << std::setprecision(2) << result << '\n';
    }
}

int main() {
    // Call the solve function which contains the main calculator logic
    solve();
    return 0; // Indicate successful execution
}