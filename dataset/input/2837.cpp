#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    BankAccount(std::string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        // Logical Error: Allows withdrawal even if balance is insufficient
        if (amount > 0) { // Should be: if (amount > 0 && balance >= amount)
            balance -= amount;
        }
    }

    double getBalance() const {
        return balance;
    }

    std::string getAccountNumber() const {
        return accountNumber;
    }
};

int main() {
    BankAccount myAccount("67890", 100.0); // Initial balance 100
    myAccount.deposit(50.0); // Balance becomes 150
    myAccount.withdraw(200.0); // Logical error allows this, balance becomes -50
    std::cout << "Account " << myAccount.getAccountNumber() << " balance: " << myAccount.getBalance() << std::endl;
    return 0;
}