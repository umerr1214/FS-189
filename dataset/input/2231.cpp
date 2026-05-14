#include <iostream>
#include <string>
#include <vector>

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(std::string accNum, double initialBalance) : 
        accountNumber(accNum), balance(initialBalance) {}

    // Public method to get account number (read-only)
    std::string getAccountNumber() const {
        return accountNumber;
    }

    // Public method to get balance
    double getBalance() const {
        return balance;
    }

    // Deposit method
    void deposit(double amount) {
        // Logical Error: Allows negative amounts to be 'deposited', effectively reducing balance.
        // The validation `amount > 0` is missing or incorrect.
        balance += amount; 
        std::cout << "Deposited " << amount << ". New balance: " << balance << std::endl;
    }

    // Withdraw method
    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                std::cout << "Withdrew " << amount << ". New balance: " << balance << std::endl;
            } else {
                std::cout << "Insufficient balance for withdrawal." << std::endl;
            }
        } else {
            std::cout << "Withdrawal amount must be positive." << std::endl;
        }
    }
};

int main() {
    BankAccount myAccount("ACC12345", 1000.0);

    std::cout << "Account Number: " << myAccount.getAccountNumber() << std::endl;
    std::cout << "Initial Balance: " << myAccount.getBalance() << std::endl;

    myAccount.deposit(200.0);  // Expected: 1200
    myAccount.withdraw(500.0); // Expected: 700
    myAccount.withdraw(800.0); // Should fail, current balance 700
    myAccount.deposit(-50.0);  // Logical error: this will incorrectly reduce balance to 650
    myAccount.withdraw(-100.0); // Should fail due to negative amount

    std::cout << "Final Balance: " << myAccount.getBalance() << std::endl;

    return 0;
}