#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision
// #include <stdexcept> // Optional: Could use for more explicit error handling (e.g., throwing exceptions)

class BankAccount {
private:
    double balance;

public:
    // Constructor initializes balance, ensures it's not negative.
    // Provides clear feedback for invalid initial balance.
    BankAccount(double initialBalance = 0.0) : balance(0.0) { // Initialize to 0 then set
        if (initialBalance >= 0.0) {
            balance = initialBalance;
        } else {
            // Informative message for invalid input, sets to a safe default.
            std::cout << "Warning: Initial balance cannot be negative. Setting to 0.00." << std::endl;
        }
    }

    // Deposits amount. Validates that the amount is positive.
    void deposit(double amount) {
        if (amount > 0.0) {
            balance += amount;
            std::cout << "Deposited: " << std::fixed << std::setprecision(2) << amount
                      << ". New balance: " << balance << std::endl;
        } else {
            // Provides clear feedback for invalid deposit amount.
            std::cout << "Deposit amount must be positive. No action taken." << std::endl;
        }
    }

    // Withdraws amount if sufficient funds. Validates that the amount is positive.
    // Returns true on success, false on failure (insufficient funds or invalid amount).
    bool withdraw(double amount) {
        if (amount <= 0.0) {
            // Provides clear feedback for invalid withdrawal amount.
            std::cout << "Withdrawal amount must be positive. No action taken." << std::endl;
            return false;
        }
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrew: " << std::fixed << std::setprecision(2) << amount
                      << ". New balance: " << balance << std::endl;
            return true;
        } else {
            // Provides clear feedback for insufficient funds.
            std::cout << "Insufficient funds for withdrawal of " << std::fixed << std::setprecision(2) << amount
                      << ". Current balance: " << balance << std::endl;
            return false;
        }
    }

    // Returns the current balance. Marked `const` as it does not modify the object's state,
    // adhering to best practices for accessor methods.
    double getBalance() const {
        return balance;
    }
};