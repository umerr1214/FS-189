#include <iostream>
#include <algorithm> // Required for std::max

class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    // Constructor initializes members, ensuring initial balance is not negative.
    // Uses member initializer list and std::max for concise and correct initialization.
    BankAccount(int accNum, double initialBalance)
        : accountNumber(accNum), balance(std::max(0.0, initialBalance)) {
        // No output from constructor, adhering to separation of concerns.
    }

    // Deposit method: accepts only positive amounts, returns true on success, false otherwise.
    bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            return true;
        }
        return false; // Indicate failure for non-positive deposit amount.
    }

    // Withdraw method: accepts only positive amounts, checks for sufficient funds,
    // returns true on success, false otherwise.
    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            return true;
        }
        return false; // Indicate failure for non-positive withdrawal amount or insufficient funds.
    }

    // Getter for balance, provides direct access to the value without side effects.
    double getBalance() const {
        return balance;
    }

    // Getter for account number.
    int getAccountNumber() const {
        return accountNumber;
    }
};

int main() {
    // Demonstrate the correct BankAccount class functionality
    BankAccount acc1(2001, 1000.0);
    std::cout << "Account " << acc1.getAccountNumber() << " created with balance: " << acc1.getBalance() << std::endl;

    // Test valid deposit
    if (acc1.deposit(200.0)) {
        std::cout << "Deposited 200. New balance: " << acc1.getBalance() << std::endl;
    } else {
        std::cout << "Deposit failed." << std::endl;
    }

    // Test invalid deposit (negative amount)
    if (acc1.deposit(-50.0)) {
        std::cout << "Deposited -50. New balance: " << acc1.getBalance() << std::endl;
    } else {
        std::cout << "Failed to deposit -50 (as expected). Current balance: " << acc1.getBalance() << std::endl;
    }

    // Test valid withdrawal
    if (acc1.withdraw(150.0)) {
        std::cout << "Withdrew 150. New balance: " << acc1.getBalance() << std::endl;
    } else {
        std::cout << "Withdrawal failed." << std::endl;
    }

    // Test invalid withdrawal (insufficient funds)
    if (acc1.withdraw(2000.0)) {
        std::cout << "Withdrew 2000. New balance: " << acc1.getBalance() << std::endl;
    } else {
        std::cout << "Failed to withdraw 2000 (insufficient funds, as expected). Current balance: " << acc1.getBalance() << std::endl;
    }

    // Test invalid withdrawal (negative amount)
    if (acc1.withdraw(-100.0)) {
        std::cout << "Withdrew -100. New balance: " << acc1.getBalance() << std::endl;
    } else {
        std::cout << "Failed to withdraw -100 (as expected). Current balance: " << acc1.getBalance() << std::endl;
    }

    std::cout << "\n--- Testing constructor with negative initial balance ---\n";
    BankAccount acc2(2002, -500.0); // Should be initialized to 0.0
    std::cout << "Account " << acc2.getAccountNumber() << " created with balance: " << acc2.getBalance() << std::endl;
    acc2.deposit(100.0);
    std::cout << "Deposited 100. New balance: " << acc2.getBalance() << std::endl;
    acc2.withdraw(50.0);
    std::cout << "Withdrew 50. New balance: " << acc2.getBalance() << std::endl;

    return 0;
}