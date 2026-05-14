#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(std::string accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {
        if (balance < 0) {
            balance = 0; // Ensure balance starts non-negative
        }
    }

    // Read-only getter for accountNumber
    const std::string& getAccountNumber() const {
        return accountNumber;
    }

    // Getter for balance
    double getBalance() const {
        return balance;
    }

    // Deposit method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: " << std::fixed << std::setprecision(2) << amount
                      << ". New balance: " << balance << std::endl;
        } else {
            std::cout << "Deposit amount must be positive." << std::endl;
        }
    }

    // Withdraw method with logical error: no validation for insufficient funds
    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Withdrawal amount must be positive." << std::endl;
        } else {
            // Logical Error: No check if 'amount' is greater than 'balance'.
            // This allows the balance to go negative, violating "basic validation".
            balance -= amount;
            std::cout << "Withdrew: " << std::fixed << std::setprecision(2) << amount
                      << ". New balance: " << balance << std::endl;
        }
    }
};

int main() {
    BankAccount account1("ACC12345", 1000.00);
    std::cout << "Account Number: " << account1.getAccountNumber()
              << ", Initial Balance: " << std::fixed << std::setprecision(2) << account1.getBalance() << std::endl;

    account1.deposit(200.50);
    account1.withdraw(150.75);
    account1.withdraw(1500.00); // This should fail due to insufficient funds but will succeed here
    account1.deposit(-50.00);   // Should fail
    account1.withdraw(0.00);    // Should fail

    std::cout << "Final Balance for " << account1.getAccountNumber() << ": "
              << std::fixed << std::setprecision(2) << account1.getBalance() << std::endl;

    BankAccount account2("ACC67890", 500.00);
    account2.deposit(100.00);
    account2.withdraw(700.00); // This should fail due to insufficient funds but will succeed here

    std::cout << "Final Balance for " << account2.getAccountNumber() << ": "
              << std::fixed << std::setprecision(2) << account2.getBalance() << std::endl;

    return 0;
}