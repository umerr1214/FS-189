#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    double balance;

public:
    // Constructor ensures initial balance is non-negative
    BankAccount(double initialBalance = 0.0) : balance(initialBalance) {
        if (balance < 0) {
            balance = 0.0; // Correctly initializes negative initial balances to zero
        }
    }

    // Safely deposits money, returning true on success, false otherwise
    bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            return true;
        }
        // Feedback is provided by the return value, allowing the caller to handle it.
        return false;
    }

    // Safely withdraws money, preventing overdrafts and negative amounts, returning true on success, false otherwise
    bool withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) { // Checks for sufficient funds
                balance -= amount;
                return true;
            } else {
                // Feedback is provided by the return value for insufficient funds.
                return false;
            }
        }
        // Feedback is provided by the return value for non-positive withdrawal amount.
        return false;
    }

    // Provides the current balance, marked const as it does not modify the object's state
    double getBalance() const {
        return balance;
    }
};

int main() {
    // This main function is just a placeholder for compilation.
    // The actual test driver is in the JSON file.
    BankAccount account(0.0);
    account.deposit(100.0);
    account.withdraw(50.0);
    std::cout << std::fixed << std::setprecision(2) << account.getBalance() << std::endl;
    return 0;
}