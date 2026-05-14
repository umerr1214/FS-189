#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    double balance;

public:
    // Robustness Issue: Constructor allows negative initial balance but silently corrects it
    // and prints to cerr, which is not a robust error handling strategy (e.g., throwing exception).
    BankAccount(double initialBalance = 0.0) : balance(initialBalance) {
        if (balance < 0) {
            balance = 0;
            std::cerr << "Warning: Initial balance cannot be negative. Setting to 0." << std::endl;
        }
    }

    // Robustness Issue: Allows negative deposits, effectively a withdrawal without proper checks.
    // A robust system would validate 'amount > 0' before proceeding.
    void deposit(double amount) {
        balance += amount; // This should ideally be 'if (amount > 0) balance += amount;'
        std::cout << "Deposited: " << std::fixed << std::setprecision(2) << amount << ". New balance: " << balance << std::endl;
    }

    // Robustness Issue: Does not explicitly check if amount <= 0.
    // If 'amount' is negative, 'balance >= amount' will likely be true if balance is positive,
    // leading to 'balance -= amount' which effectively becomes 'balance += |amount|' (a deposit),
    // but without the proper deposit logic or checks.
    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrew: " << std::fixed << std::setprecision(2) << amount << ". New balance: " << balance << std::endl;
            return true;
        } else {
            std::cout << "Insufficient funds for withdrawal of " << std::fixed << std::setprecision(2) << amount << ". Current balance: " << balance << std::endl;
            return false;
        }
    }

    double getBalance() const {
        return balance;
    }
};