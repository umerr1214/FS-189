#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    BankAccount(std::string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount) {
        // Logical Error: The deposit method does not validate that the deposit amount is positive.
        // This allows depositing negative amounts, effectively decreasing the balance without proper validation.
        balance += amount; 
        std::cout << "Transaction complete. New balance: " << balance << std::endl;
    }

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

    double getBalance() const {
        return balance;
    }

    std::string getAccountNumber() const {
        return accountNumber;
    }
};

int main() {
    BankAccount myAccount("67890", 1000.0);
    std::cout << "Initial balance: " << myAccount.getBalance() << std::endl; // Expected: 1000
    myAccount.deposit(500.0); // Balance: 1500
    myAccount.deposit(-200.0); // Logical error: allows negative deposit. Balance: 1300
    myAccount.withdraw(1500.0); // Insufficient funds, balance remains 1300
    myAccount.withdraw(300.0); // Balance: 1000
    std::cout << myAccount.getBalance() << std::endl; // Expected: 1000
    return 0;
}