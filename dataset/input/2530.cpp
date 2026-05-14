#include <iostream>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance = 0.0) : balance(initialBalance) {}

    bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            return true;
        }
        return false;
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const {
        return balance;
    }
} // SYNTAX ERROR: Missing semicolon here

int main() {
    // This main function is part of the file with the error.
    // It will not compile due to the missing semicolon above.
    BankAccount account(100.0);
    std::cout << "Initial balance: " << account.getBalance() << std::endl;
    return 0;
}