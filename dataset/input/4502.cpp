#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    double bal = 500.0; // Poor variable name: 'bal' instead of 'currentBalance'
    int opt; // Poor variable name: 'opt' instead of 'menuChoice'
    double amt; // Poor variable name: 'amt' instead of 'transactionAmount'

    do {
        // No comments explaining the code sections or logic, hindering readability.
        std::cout << "\n--- ATM SYSTEM ---\n"; // Repetitive menu printing, could be a function
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Balance Inquiry\n";
        std::cout << "4. Exit\n";
        std::cout << "------------------\n";
        std::cout << "Enter option: ";
        std::cin >> opt;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opt = 0; // Reset option to re-display menu
            continue;
        }

        switch (opt) {
            case 1:
                std::cout << "Enter amount to deposit: ";
                std::cin >> amt;
                if (std::cin.fail() || amt <= 0) { // Basic validation for positive amount
                    std::cout << "Invalid deposit amount.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else {
                    bal += amt;
                    std::cout << "Deposited " << amt << ". New balance: " << bal << "\n"; // No output formatting (e.g., setprecision)
                }
                break;
            case 2:
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amt;
                if (std::cin.fail() || amt <= 0) { // Basic validation for positive amount
                    std::cout << "Invalid withdrawal amount.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else if (amt > bal) {
                    std::cout << "Insufficient funds!\n";
                } else {
                    bal -= amt;
                    std::cout << "Withdrew " << amt << ". New balance: " << bal << "\n"; // No output formatting
                }
                break;
            case 3:
                std::cout << "Current balance: " << bal << "\n"; // No output formatting
                break;
            case 4:
                std::cout << "Exiting ATM. Thank you!\n";
                break;
            default:
                std::cout << "Invalid option. Try again.\n";
                break;
        }
        // Readability/Efficiency Issue: This pause requires an extra Enter press from the user,
        // which is inefficient for automated testing and can be disruptive for user experience.
        std::cout << "Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get(); // Waits for a character input
    } while (opt != 4);

    return 0;
}