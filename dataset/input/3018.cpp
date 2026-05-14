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

    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
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

    // SEMANTIC ERROR: Attempting to access private member 'balance' directly
    // This line will cause a compiler error: 'double BankAccount::balance' is private
    std::cout << "Directly accessing balance (ERROR): " << account1.balance << std::endl;

    account1.withdraw(1500.0); // Attempt to overdraw
    std::cout << "Balance after attempted overdraw: " << account1.getBalance() << std::endl;

    return 0;
}