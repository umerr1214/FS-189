#include <iostream>

int main() {
    char userChoice;
    int num1, num2;

    do {
        std::cout << "\n--- Menu ---\n";
        std::cout << "A: Add\n";
        std::cout << "S: Subtract\n";
        std::cout << "Q: Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> userChoice; // Robustness Issue: Does not handle non-character input or buffer issues well.
                                // If `std::cin` fails (e.g., non-char input), it enters a failed state
                                // and will not read further input, leading to an infinite loop.
                                // Also, does not convert input to uppercase, making it case-sensitive.

        switch (userChoice) { // Case-sensitive comparison
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
                // If std::cin failed earlier, this loop will repeat indefinitely
                // without prompting for new input or clearing the error state.
                break;
        }
    } while (userChoice != 'Q');

    return 0;
}