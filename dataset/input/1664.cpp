#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    double balance;

public:
    // Constructor with verbose initialization
    BankAccount(double initialBalance = 0.0) {
        if (initialBalance >= 0.0) {
            this->balance = initialBalance; // Unnecessary use of 'this->'
        } else {
            this->balance = 0.0; // If negative initial balance, start with 0.0
            std::cout << "Warning: Initial balance cannot be negative. Setting to 0.0." << std::endl; // Printing warnings from constructor is not ideal
        }
    }

    // Public method to deposit money with verbose checks and output
    void deposit(double amount) {
        if (amount > 0.0) {
            this->balance = this->balance + amount; // Redundant 'this->' and verbose assignment
            std::cout << "Deposit successful. Current balance is now: " << this->balance << std::endl; // Printing success messages from method
        } else if (amount == 0.0) {
            std::cout << "Deposit amount cannot be zero. No action taken." << std::endl; // Redundant check for zero
        } else {
            std::cout << "Deposit amount must be positive. No action taken." << std::endl; // Printing error messages from method
        }
    }

    // Public method to withdraw money with verbose checks and output
    void withdraw(double amount) {
        if (amount > 0.0) {
            if (this->balance >= amount) {
                this->balance = this->balance - amount; // Redundant 'this->' and verbose assignment
                std::cout << "Withdrawal successful. Current balance is now: " << this->balance << std::endl; // Printing success messages from method
            } else {
                std::cout << "Insufficient balance for withdrawal. Balance: " << this->balance << ". Attempted: " << amount << ". No action taken." << std::endl; // Verbose error message
            }
        } else if (amount == 0.0) {
            std::cout << "Withdrawal amount cannot be zero. No action taken." << std::endl; // Redundant check for zero
        } else {
            std::cout << "Withdrawal amount must be positive. No action taken." << std::endl; // Printing error messages from method
        }
    }

    // Public method to get the current balance with unnecessary temporary variable
    double getBalance() const {
        double currentBalanceValue = this->balance; // Unnecessary temporary variable and 'this->'
        return currentBalanceValue;
    }
};

int main() {
    // Set precision for output
    std::cout << std::fixed << std::setprecision(2);

    BankAccount account(100.0);
    std::cout << "Initial balance: " << account.getBalance() << std::endl;

    // Valid deposit
    std::cout << "--- Deposit 50.0 ---" << std::endl;
    account.deposit(50.0); // Expected: Deposit successful. Current balance is now: 150.00

    // Valid withdrawal
    std::cout << "--- Withdraw 20.0 ---" << std::endl;
    account.withdraw(20.0); // Expected: Withdrawal successful. Current balance is now: 130.00

    // Invalid deposit (negative)
    std::cout << "--- Deposit -10.0 ---" << std::endl;
    account.deposit(-10.0); // Expected: Deposit amount must be positive. No action taken.

    // Invalid withdrawal (insufficient funds)
    std::cout << "--- Withdraw 200.0 ---" << std::endl;
    account.withdraw(200.0); // Expected: Insufficient balance for withdrawal...

    // Invalid deposit (zero)
    std::cout << "--- Deposit 0.0 ---" << std::endl;
    account.deposit(0.0); // Expected: Deposit amount cannot be zero...

    // Invalid withdrawal (zero)
    std::cout << "--- Withdraw 0.0 ---" << std::endl;
    account.withdraw(0.0); // Expected: Withdrawal amount cannot be zero...

    std::cout << "Final balance: " << account.getBalance() << std::endl; // Expected: 130.00

    return 0;
}