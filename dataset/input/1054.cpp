#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(std::string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    // Deposit method
    void deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Deposit amount must be positive." << std::endl;
        } else {
            balance += amount;
            std::cout << "Deposited " << amount << ". New balance: " << balance << std::endl;
        }
    }

    // Withdraw method
    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Withdrawal amount must be positive." << std::endl;
        } else if (amount > balance) {
            std::cout << "Insufficient funds. Current balance: " << balance << std::endl;
        } else {
            balance -= amount;
            std::cout << "Withdrew " << amount << ". New balance: " << balance << std::endl;
        }
    }

    // Get balance method
    double getBalance() const {
        return balance;
    }

    // Get account number (for testing/display)
    std::string getAccountNumber() const {
        return accountNumber;
    }
}; // Syntax Error: Missing semicolon after class definition

int main() {
    BankAccount myAccount("12345", 1000.0);
    myAccount.deposit(500.0);
    myAccount.withdraw(200.0);
    std::cout << myAccount.getBalance() << std::endl;
    return 0;
}