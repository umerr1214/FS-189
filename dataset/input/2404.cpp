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

    // Syntax Error: Missing return type 'double'
    getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account;
    account.deposit(100.0);
    account.withdraw(30.0);
    // This line will not compile due to the error in getBalance()
    // std::cout << account.getBalance() << std::endl;
    return 0;
}