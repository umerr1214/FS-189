#include <iostream>
#include <cctype>   // For std::toupper
#include <limits>   // For std::numeric_limits

int main() {
    char choice;
    int num1, num2;

    do {
        std::cout << "\n--- Menu ---\n";
        std::cout << "A: Add\n";
        std::cout << "S: Subtract\n";
        std::cout << "Q: Quit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        // Convert choice to uppercase to handle 'a', 's', 'q' as well
        choice = std::toupper(static_cast<unsigned char>(choice));

        // Handle potential input errors and clear the input buffer
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flags (e.g., failbit, badbit)
            choice = 'I'; // Set choice to an invalid character to trigger default case
        }
        // Discard the rest of the line, up to the newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 'A':
                std::cout << "Enter two numbers to add: ";
                std::cin >> num1 >> num2;
                std::cout << "Result: " << num1 + num2 << std::endl;
                // Clear buffer after reading numbers to prevent issues with subsequent char input
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            case 'S':
                std::cout << "Enter two numbers to subtract: ";
                std::cin >> num1 >> num2;
                std::cout << "Result: " << num1 - num2 << std::endl;
                // Clear buffer after reading numbers
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            case 'Q':
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 'Q');

    return 0;
}