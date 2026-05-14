#include <iostream>
#include <cctype> // For toupper
#include <limits> // For numeric_limits (though not used in the erroneous version)

int main() {
    char choice;
    double num1, num2;

    do {
        std::cout << "Menu:\n";
        std::cout << "A - Add\n";
        std::cout << "S - Subtract\n";
        std::cout << "Q - Quit\n";
        std::cout << "Enter your choice (A/S/Q): ";
        std::cin >> choice;
        // Semantic error: No input validation or error handling for std::cin.
        // If the user enters non-character input (e.g., "hello"),
        // cin will enter a fail state. Subsequent cin operations will fail
        // without extracting new input, leading to an infinite loop.
        // The 'choice' variable will retain its previous value (or be uninitialized if first input fails).

        choice = std::toupper(choice); // Convert to uppercase for consistent comparison

        switch (choice) {
            case 'A':
                std::cout << "Enter two numbers to add: ";
                std::cin >> num1 >> num2;
                // Similar semantic error for num1, num2 input if non-numeric
                std::cout << "Result: " << num1 + num2 << std::endl;
                break;
            case 'S':
                std::cout << "Enter two numbers to subtract: ";
                std::cin >> num1 >> num2;
                // Similar semantic error for num1, num2 input if non-numeric
                std::cout << "Result: " << num1 - num2 << std::endl;
                break;
            case 'Q':
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
        std::cout << std::endl; // Newline for better readability
    } while (choice != 'Q');

    return 0;
}