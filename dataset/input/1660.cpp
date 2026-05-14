#include <iostream>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
        }
    }

    double getBalance() const {
        return balance;
    }
} // Syntax Error: Missing semicolon after class definition

int main() {
    BankAccount account(1000.0);
    account.deposit(200.0);
    account.withdraw(150.0);
    std::cout << "Final balance: " << account.getBalance() << std::endl;
    return 0;
}