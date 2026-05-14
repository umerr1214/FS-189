#include <iostream>
#include <string> // Unnecessary include for this simple program

int main() {
    double n1, n2, res; // Poor variable names, 'res' for result
    int c; // Poor variable name, 'c' for choice

    start_menu: // Readability Issue: Unnecessary goto label for a simple loop
    std::cout << "Menu:\n";
    std::cout << "1. Add\n";
    std::cout << "2. Subtract\n";
    std::cout << "3. Multiply\n";
    std::cout << "4. Divide\n";
    std::cout << "Enter your choice: ";
    std::cin >> c;

    if (std::cin.fail()) { // Basic input failure check, but not robust or efficient
        std::cin.clear();
        std::cin.ignore(1000, '\n'); // Readability Issue: Arbitrary large number for ignore
        std::cout << "Invalid input for choice. Please try again.\n"; // Verbose message
        goto start_menu; // Readability Issue: Use of goto for looping
    }

    // Readability Issue: Repetitive prompts and error handling for numbers
    std::cout << "Enter first number: ";
    std::cin >> n1;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid number input. Returning to menu.\n";
        goto start_menu;
    }

    std::cout << "Enter second number: ";
    std::cin >> n2;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid number input. Returning to menu.\n";
        goto start_menu;
    }

    switch (c) {
        case 1: { // Readability Issue: Unnecessary block for single statement
            res = n1 + n2;
            std::cout << "The result of addition is: " << res << "\n"; // Slightly verbose output
            break;
        }
        case 2: {
            res = n1 - n2;
            std::cout << "The result of subtraction is: " << res << "\n";
            break;
        }
        case 3: {
            res = n1 * n2;
            std::cout << "The result of multiplication is: " << res << "\n";
            break;
        }
        case 4: {
            if (n2 == 0) {
                std::cout << "Error: Division by zero is not allowed.\n"; // Correctly handles division by zero
            } else {
                res = n1 / n2;
                std::cout << "The result of division is: " << res << "\n";
            }
            break;
        }
        default:
            std::cout << "Invalid option selected. Please choose between 1 and 4.\n"; // Verbose, but functionally correct
            break;
    }
    std::cout << "\n"; // Readability Issue: Extra newline
    goto start_menu; // Readability Issue: Loop back using goto
    return 0; // Readability Issue: Unreachable code
}