#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    const std::string accountNumber;
    double balance;

public:
    // Constructor - accountNumber set only here
    BankAccount(std::string accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {
        // No validation for account number or initial balance in this version
    }

    // Public method to deposit funds
    // Robustness issue: Allows depositing negative amounts, effectively a withdrawal without validation.
    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposit of " << std::fixed << std::setprecision(2) << amount
                  << " successful. New balance: " << balance << std::endl;
    }

    // Public method to withdraw funds
    // Robustness issue: Does not validate if amount > 0. A negative withdrawal would increase balance.
    bool withdraw(double amount) {
        if (balance >= amount) { // Only checks if sufficient funds
            balance -= amount;
            std::cout << "Withdrawal of " << std::fixed << std::setprecision(2) << amount
                      << " successful. New balance: " << balance << std::endl;
            return true;
        } else {
            std::cout << "Withdrawal of " << std::fixed << std::setprecision(2) << amount
                      << " failed. Insufficient funds. Current balance: " << balance << std::endl;
            return false;
        }
    }

    // Read-only access to accountNumber
    const std::string& getAccountNumber() const {
        return accountNumber;
    }

    // Read-only access to balance
    double getBalance() const {
        return balance;
    }
};

int main() {
    std::cout << "--- Testing BankAccount (Robustness Issue) ---" << std::endl;

    // Create an account
    BankAccount acc1("ACC001", 1000.00);
    std::cout << "Account " << acc1.getAccountNumber() << " created with balance: "
              << std::fixed << std::setprecision(2) << acc1.getBalance() << std::endl;

    // Test case 1: Normal deposit
    acc1.deposit(200.00); // Expected: Balance 1200.00

    // Test case 2: Normal withdrawal
    acc1.withdraw(300.00); // Expected: Balance 900.00

    // Test case 3: Withdrawal exceeding balance
    acc1.withdraw(1000.00); // Expected: Failed, Balance 900.00

    // Test case 4: Robustness Issue - Deposit negative amount (should act as withdrawal)
    std::cout << "\n--- Robustness Issue: Depositing negative amount ---" << std::endl;
    acc1.deposit(-150.00); // Expected: Balance 750.00 (reduces balance)

    // Test case 5: Robustness Issue - Withdraw negative amount (should act as deposit)
    std::cout << "\n--- Robustness Issue: Withdrawing negative amount ---" << std::endl;
    acc1.withdraw(-50.00); // Expected: Balance 800.00 (increases balance)

    // Test case 6: Robustness Issue - Withdraw zero amount (should succeed, no change)
    std::cout << "\n--- Robustness Issue: Withdrawing zero amount ---" << std::endl;
    acc1.withdraw(0.00); // Expected: Balance 800.00 (no change)

    std::cout << "\nFinal balance for " << acc1.getAccountNumber() << ": "
              << std::fixed << std::setprecision(2) << acc1.getBalance() << std::endl;

    return 0;
}