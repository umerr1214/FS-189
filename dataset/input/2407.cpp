#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance = 0.0) : balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
        // Robustness Issue: No feedback or action for non-positive deposit amount.
        // It just silently fails to add.
    }

    void withdraw(double amount) {
        // Robustness Issue: Allows overdrafts
        // No check for balance >= amount
        if (amount > 0) {
            balance -= amount;
        }
        // Robustness Issue: No feedback or action for non-positive withdrawal amount.
        // It just silently fails to subtract.
    }

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