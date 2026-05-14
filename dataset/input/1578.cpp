#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    std::string accountNumber; // Not declared const
    double balance;

public:
    // Constructor
    BankAccount(std::string accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {
        if (balance < 0) {
            balance = 0; // Ensure balance starts non-negative
        }
    }

    // Read-only getter for accountNumber (correct)
    const std::string& getAccountNumber() const {
        return accountNumber;
    }

    // SEMANTIC ERROR: Provides a non-const reference to accountNumber, violating "read-only thereafter"
    std::string& getModifiableAccountNumber() {
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

    // Withdraw method with basic validation
    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Withdrawal amount must be positive." << std::endl;
        } else if (amount > balance) {
            std::cout << "Insufficient funds. Current balance: " << std::fixed << std::setprecision(2) << balance
                      << ". Attempted to withdraw: " << amount << std::endl;
        } else {
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

    // Demonstrate semantic error: Modifying accountNumber via the non-const getter
    std::string& accRef = account1.getModifiableAccountNumber();
    accRef = "MODIFIED_ACC_001"; // This compiles and runs, but violates the read-only constraint

    std::cout << "Account Number AFTER MODIFICATION: " << account1.getAccountNumber()
              << ", Balance: " << std::fixed << std::setprecision(2) << account1.getBalance() << std::endl;

    account1.deposit(200.50);
    account1.withdraw(150.75);
    account1.withdraw(1500.00); // Should fail
    account1.deposit(-50.00);   // Should fail
    account1.withdraw(0.00);    // Should fail

    std::cout << "Final Balance for " << account1.getAccountNumber() << ": "
              << std::fixed << std::setprecision(2) << account1.getBalance() << std::endl;

    return 0;
}