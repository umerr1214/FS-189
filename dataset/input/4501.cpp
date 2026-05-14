#include <iostream>
#include <iomanip> // For std::fixed, std::setprecision
#include <limits>  // For std::numeric_limits

int main() {
    double balance = 500.00; // Initial balance
    int choice = 0; // Initialize choice to ensure loop starts
    double amount;

    // Set output format for currency
    std::cout << std::fixed << std::setprecision(2);

    do {
        // Display ATM menu options
        std::cout << "\nATM Menu:\n";
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Check Balance\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice; // No robust input validation here

        // Robustness Issue: If cin fails (e.g., non-numeric input), it enters a fail state.
        // std::cin.clear() resets the error flag, but std::cin.ignore() is missing.
        // This means the bad input remains in the buffer, causing an infinite loop
        // as std::cin >> choice; will repeatedly fail on the same bad input.
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear the error flag
            // Missing: std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = 0; // Reset choice to a non-exit value to keep the loop going
            continue; // Skip the switch statement for this iteration
        }

        switch (choice) {
            case 1: // Deposit
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount; // No robust input validation for non-numeric amount

                if (std::cin.fail()) {
                    std::cout << "Invalid amount entered. Please try again.\n";
                    std::cin.clear();
                    // Missing: std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    amount = 0; // Reset amount to prevent unintended operations
                    continue; // Skip balance update
                }
                // Robustness Issue: Allows negative deposit amounts
                balance += amount;
                std::cout << "Deposit successful. Current Balance: $" << balance << "\n";
                break;
            case 2: // Withdraw
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount; // No robust input validation for non-numeric amount

                if (std::cin.fail()) {
                    std::cout << "Invalid amount entered. Please try again.\n";
                    std::cin.clear();
                    // Missing: std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    amount = 0; // Reset amount
                    continue; // Skip balance update
                }
                // Robustness Issue: Allows withdrawal to exceed current balance, leading to a negative balance
                balance -= amount;
                std::cout << "Withdrawal successful. Current Balance: $" << balance << "\n";
                break;
            case 3: // Check Balance
                std::cout << "Current Balance: $" << balance << "\n";
                break;
            case 4: // Exit
                std::cout << "Exiting ATM. Goodbye!\n";
                break;
            default: // Invalid menu choice (numeric but out of range)
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}