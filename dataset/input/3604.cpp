#include <iostream>
#include <cctype> // For toupper

int main() {
    char choice;
    double num1, num2;

    do {
        std::cout << "Menu:\n";
        std::cout << "A - Add\n";
        std::cout << "S - Subtract\n";
        std::cout << "Q - Quit\n";
        std::cout << "Enter your choice (A/S/Q): " // Syntax Error: Missing semicolon
        std::cin >> choice;
        choice = std::toupper(choice); // Convert to uppercase for consistent comparison

        switch (choice) {
            case 'A':
                std::cout << "Enter two numbers to add: ";
                std::cin >> num1 >> num2;
                std::cout << "Result: " << num1 + num2 << std::endl;
                break;
            case 'S':
                std::cout << "Enter two numbers to subtract: ";
                std::cin >> num1 >> num2;
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