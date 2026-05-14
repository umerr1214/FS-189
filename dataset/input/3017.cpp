#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string ownerName;
    double balance;

public:
    BankAccount(std::string accNum, std::string owner, double initialBalance) {
        accountNumber = accNum;
        ownerName = owner;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // LOGICAL ERROR: Does not prevent balance from going negative
    void withdraw(double amount) {
        if (amount > 0) { // Should also check '&& balance >= amount'
            balance -= amount; // This will make balance negative if amount > current balance
        }
    }

    double getBalance() {
        return balance;
    }

    std::string getAccountNumber() {
        return accountNumber;
    }

    std::string getOwnerName() {
        return ownerName;
    }
};

int main() {
    BankAccount account1("12345", "Alice Smith", 1000.0);
    std::cout << "Account " << account1.getAccountNumber() << " owner: " << account1.getOwnerName() << std::endl;
    std::cout << "Initial balance: " << account1.getBalance() << std::endl;

    account1.deposit(200.0);
    std::cout << "Balance after deposit: " << account1.getBalance() << std::endl;

    account1.withdraw(300.0);
    std::cout << "Balance after withdrawal: " << account1.getBalance() << std::endl;

    account1.withdraw(1500.0); // Attempt to overdraw
    std::cout << "Balance after attempted overdraw: " << account1.getBalance() << std::endl; // Expected: 900.0, Actual: -600.0

    return 0;
}