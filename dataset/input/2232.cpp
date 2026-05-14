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

    // Semantic Error: Provides a public setter for accountNumber,
    // violating the requirement that it should be "read-only after creation".
    void setAccountNumber(std::string newAccNum) {
        accountNumber = newAccNum;
        std::cout << "Account number changed to: " << accountNumber << std::endl;
    }

    // Public method to get balance
    double getBalance() const {
        return balance;
    }

    // Deposit method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited " << amount << ". New balance: " << balance << std::endl;
        } else {
            std::cout << "Deposit amount must be positive." << std::endl;
        }
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

    myAccount.deposit(200.0);
    myAccount.withdraw(500.0);
    myAccount.withdraw(800.0); // Should fail
    myAccount.deposit(-50.0);  // Should fail
    myAccount.withdraw(-100.0); // Should fail

    // Demonstrating the semantic error: modifying account number after creation
    myAccount.setAccountNumber("NEWACC9876"); 
    std::cout << "Account Number after change: " << myAccount.getAccountNumber() << std::endl;

    std::cout << "Final Balance: " << myAccount.getBalance() << std::endl;

    return 0;
}