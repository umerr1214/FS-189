#include <iostream>
#include <limits> // For std::numeric_limits

// Function to display the menu options
void displayMenu() {
    std::cout << "\n--- Calculator Menu ---\n";
    std::cout << "1. Add\n";
    std::cout << "2. Subtract\n";
    std::cout << "3. Multiply\n";
    std::cout << "4. Divide\n";
    std::cout << "5. Exit\n";
    std::cout << "-----------------------\n";
}

// Function to get a valid integer choice from the user
int getChoice() {
    int choice;
    while (true) {
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        } else if (choice < 1 || choice > 5) {
            std::cout << "Choice out of range. Please enter a number between 1 and 5.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard rest of line
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard rest of line
            return choice;
        }
    }
}

// Function to get a valid double number from the user
double getNumber(const std::string& prompt) {
    double number;
    while (true) {
        std::cout << prompt;
        std::cin >> number;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a valid number.\n";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard rest of line
            return number;
        }
    }
}

int main() {
    double num1, num2;
    int choice;

    do {
        displayMenu();
        choice = getChoice();

        if (choice == 5) {
            std::cout << "Exiting calculator. Goodbye!\n";
            break; // Exit the loop if user chooses to exit
        }

        num1 = getNumber("Enter first number: ");
        num2 = getNumber("Enter second number: ");

        switch (choice) {
            case 1:
                std::cout << "Result: " << num1 + num2 << "\n";
                break;
            case 2:
                std::cout << "Result: " << num1 - num2 << "\n";
                break;
            case 3:
                std::cout << "Result: " << num1 * num2 << "\n";
                break;
            case 4:
                if (num2 == 0) {
                    std::cout << "Error: Division by zero is not allowed.\n";
                } else {
                    std::cout << "Result: " << num1 / num2 << "\n";
                }
                break;
            default:
                // This case should ideally not be reached due to getChoice validation,
                // but included for completeness in case of unexpected flow.
                std::cout << "An unexpected error occurred. Please try again.\n";
                break;
        }
    } while (true); // Loop continues until 'break' is called for choice 5

    return 0;
}