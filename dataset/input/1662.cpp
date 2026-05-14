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

    // Semantic error: Returns a non-const reference to the private balance,
    // breaking encapsulation by allowing external direct modification.
    double& getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account(1000.0);
    account.deposit(200.0);
    account.withdraw(150.0);
    std::cout << "Initial reported balance: " << account.getBalance() << std::endl;

    // Exploit the semantic error: modify balance directly through getBalance()
    account.getBalance() = 5000.0;
    std::cout << "Modified balance via getBalance(): " << account.getBalance() << std::endl;

    return 0;
}