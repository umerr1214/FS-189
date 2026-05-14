#include <iostream>
#include <iomanip> // For std::fixed, std::setprecision
#include <limits>  // For std::numeric_limits

// Function to clear the input buffer after reading
void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to get a validated integer input within a specified range
int getValidatedIntInput(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) { // Check for non-numeric input
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear the error flag
            clearInputBuffer(); // Discard the invalid input from the buffer
        } else if (value < min || value > max) { // Check if input is within the valid range
            std::cout << "Choice must be between " << min << " and " << max << ".\n";
            clearInputBuffer(); // Clear buffer in case of extra input
        } else {
            clearInputBuffer(); // Clear buffer after successful valid input
            return value;
        }
    }
}

// Function to get a validated positive double input
double getValidatedDoubleInput(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) { // Check for non-numeric input
            std::cout << "Invalid input. Please enter a valid amount.\n";
            std::cin.clear(); // Clear the error flag
            clearInputBuffer(); // Discard the invalid input
        } else if (value <= 0) { // Check if amount is positive
            std::cout << "Amount must be positive.\n";
            clearInputBuffer(); // Clear buffer
        } else {
            clearInputBuffer(); // Clear buffer after successful valid input
            return value;
        }
    }
}

int main() {
    double currentBalance = 1000.00; // Initialize current balance
    int menuChoice;                   // User's menu selection
    double transactionAmount;         // Amount for deposit or withdrawal

    // Set output format for currency: fixed-point notation with 2 decimal places
    std::cout << std::fixed << std::setprecision(2);

    do {
        // Display ATM menu options clearly
        std::cout << "\n--- Welcome to the ATM ---\n";
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Check Balance\n";
        std::cout << "4. Exit\n";
        std::cout << "--------------------------\n";

        // Get user's menu choice with robust validation
        menuChoice = getValidatedIntInput("Enter your choice: ", 1, 4);

        switch (menuChoice) {
            case 1: // Deposit operation
                transactionAmount = getValidatedDoubleInput("Enter amount to deposit: ");
                currentBalance += transactionAmount;
                std::cout << "Deposit successful. New balance: $" << currentBalance << "\n";
                break;
            case 2: // Withdrawal operation
                transactionAmount = getValidatedDoubleInput("Enter amount to withdraw: ");
                if (transactionAmount > currentBalance) { // Check for sufficient funds
                    std::cout << "Insufficient balance! Current balance: $" << currentBalance << "\n";
                } else {
                    currentBalance -= transactionAmount;
                    std::cout << "Withdrawal successful. New balance: $" << currentBalance << "\n";
                }
                break;
            case 3: // Check Balance operation
                std::cout << "Current Balance: $" << currentBalance << "\n";
                break;
            case 4: // Exit the ATM program
                std::cout << "Thank you for using the ATM. Goodbye!\n";
                break;
            default:
                // This case should ideally not be reached due to getValidatedIntInput,
                // but included for defensive programming.
                std::cout << "An unexpected error occurred. Please restart the ATM.\n";
                break;
        }
    } while (menuChoice != 4); // Continue loop until 'Exit' is chosen

    return 0;
}