#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision
#include <limits>  // Required for std::numeric_limits

// Function to encapsulate calculator logic for testing
void solve() {
    double num1, num2;
    char operation;
    double result = 0.0; // Initialize result to 0.0

    // Prompt user for input
    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    // Check for input stream errors for numbers
    if (std::cin.fail()) {
        std::cout << "Error: Invalid numeric input.\n";
        // Clear error flags and ignore remaining input for robustness
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return; // Exit if input is invalid
    }

    // Use a switch statement to perform the operation
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
                std::cout << "Error: Division by zero is not allowed.\n";
                return; // Exit if division by zero
            }
            result = num1 / num2;
            break;
        default:
            // Robustness Issue: Prints an error but then proceeds to print the initialized result (0.0)
            std::cout << "Error: Invalid operator.\n";
            // No return here, so it falls through to print the result, which is misleading for an invalid operation.
            break;
    }

    // Print the result with 2 decimal places
    std::cout << "Result: " << std::fixed << std::setprecision(2) << result << '\n';
}

int main() {
    // Call the solve function which contains the main logic
    solve();
    return 0;
}