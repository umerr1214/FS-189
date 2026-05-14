#include <iostream>

int main() {
    double balance = 0.0;
    int choice;
    double amount;

    do {
        std::cout << "\nATM Menu:" << std::endl;
        std::cout << "1. Deposit" << std::endl;
        std::cout << "2. Withdraw" << std::endl;
        std::cout << "3. Check Balance" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: " // SYNTAX ERROR: Missing semicolon here
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                if (amount > 0) {
                    balance += amount;
                    std::cout << "Deposit successful. New balance: $" << balance << std::endl;
                } else {
                    std::cout << "Invalid deposit amount." << std::endl;
                }
                break;
            case 2:
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    std::cout << "Withdrawal successful. New balance: $" << balance << std::endl;
                } else if (amount > balance) {
                    std::cout << "Insufficient balance." << std::endl;
                } else {
                    std::cout << "Invalid withdrawal amount." << std::endl;
                }
                break;
            case 3:
                std::cout << "Current Balance: $" << balance << std::endl;
                break;
            case 4:
                std::cout << "Exiting ATM. Thank you!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}