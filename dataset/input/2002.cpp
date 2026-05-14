#include <iostream>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance = 0.0) : balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            std::cout << "Deposit amount must be positive." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            std::cout << "Withdrew " << amount << ". New balance: " << balance << std::endl;
        } else if (amount <= 0) {
            std::cout << "Withdrawal amount must be positive." << std::endl;
        } else {
            std::cout << "Insufficient funds to withdraw " << amount << ". Current balance: " << balance << std::endl;
        }
    }

    double getBalance() {
        return balance;
    }
}; // Missing semicolon here, causing a syntax error.

int main() {
    BankAccount myAccount(100.0);
    myAccount.deposit(50.0);
    myAccount.withdraw(30.0);
    std::cout << "Final balance: " << myAccount.getBalance() << std::endl;
    return 0;
}