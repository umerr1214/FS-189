#include <iostream>

class BankAccount {
private:
    double balance;

public:
    BankAccount() : balance(0.0) {}

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
        // Semantic Error: Attempting to modify 'balance' (a non-mutable member)
        // in a const member function. This will cause a compilation error.
        // balance = 0.0; 
        return balance;
    }
};

int main() {
    BankAccount account;
    account.deposit(100.0);
    account.withdraw(30.0);
    std::cout << account.getBalance() << std::endl;
    return 0;
}