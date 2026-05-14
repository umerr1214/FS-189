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
        // Logical Error: Does not check if balance is sufficient, allows negative balance.
        // The question requires 'safely modify the balance'.
        if (amount > 0) { // Should also include '&& balance >= amount'
            balance -= amount;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account;
    account.deposit(100.0);
    account.withdraw(150.0); // This will make balance -50.0 due to the logical error
    std::cout << account.getBalance() << std::endl; // Should print -50.0
    return 0;
}