#include <iostream>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance = 0.0) : balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            std::cout << "Deposit amount must be positive." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                // Semantic error: Funds are sufficient, but the balance is NOT updated.
                // The 'withdraw' operation semantically fails to change the account state.
                // balance -= amount; // This crucial line is missing.
                std::cout << "Attempted to withdraw " << amount << ". Funds were sufficient. Balance remains: " << balance << std::endl;
            } else {
                std::cout << "Insufficient funds to withdraw " << amount << ". Current balance: " << balance << std::endl;
            }
        } else {
            std::cout << "Withdrawal amount must be positive." << std::endl;
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount myAccount(100.0);
    myAccount.deposit(50.0); // Balance becomes 150.0
    myAccount.withdraw(30.0); // Funds sufficient, but balance remains 150.0
    std::cout << "Final balance: " << myAccount.getBalance() << std::endl; // Expected 120.0, actual 150.0
    myAccount.withdraw(200.0); // Funds insufficient, prints message. Balance remains 150.0
    std::cout << "Final balance after another withdraw: " << myAccount.getBalance() << std::endl; // Expected 150.0, actual 150.0
    return 0;
}