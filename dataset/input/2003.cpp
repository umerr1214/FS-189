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
        if (amount > 0) {
            // Logical error: Does not check for sufficient funds.
            // This allows the balance to become negative.
            balance -= amount;
            std::cout << "Withdrew " << amount << ". New balance: " << balance << std::endl;
        } else {
            std::cout << "Withdrawal amount must be positive." << std::endl;
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount myAccount(100.0);
    myAccount.deposit(50.0); // Balance is 150.0
    myAccount.withdraw(200.0); // This should fail due to insufficient funds, but will succeed. Balance becomes -50.0
    std::cout << "Final balance: " << myAccount.getBalance() << std::endl;
    return 0;
}