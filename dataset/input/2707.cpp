#include <iostream>
#include <string> // Not strictly needed, but often included
// #include <algorithm> // Not using std::max to demonstrate robustness flaw

class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    // Constructor allows negative initial balance directly, violating the requirement
    BankAccount(int accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {
        std::cout << "Account " << accountNumber << " created with initial balance: " << balance << std::endl;
    }

    // Deposit method allows negative amounts, which is a major robustness issue.
    // A robust deposit method should reject negative amounts.
    void deposit(double amount) {
        if (amount < 0) {
            std::cout << "Warning: Depositing a negative amount (" << amount << ") will decrease balance." << std::endl;
        }
        balance += amount;
        std::cout << "Deposited " << amount << ". New balance: " << balance << std::endl;
    }

    // Withdraw method checks for sufficient funds and prevents negative withdrawals.
    // The robustness issue here is primarily in the constructor and deposit method,
    // leading to potentially unexpected states for withdrawal logic.
    bool withdraw(double amount) {
        if (amount < 0) {
            std::cout << "Withdrawal amount cannot be negative. Attempted: " << amount << std::endl;
            return false;
        }
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrew " << amount << ". New balance: " << balance << std::endl;
            return true;
        } else {
            std::cout << "Insufficient funds to withdraw " << amount << ". Current balance: " << balance << std::endl;
            return false;
        }
    }

    double getBalance() const {
        return balance;
    }

    int getAccountNumber() const {
        return accountNumber;
    }
};

int main() {
    // Test cases for robustness issues
    BankAccount account1(101, 1000.0); // Normal operation
    account1.deposit(200.0);
    account1.withdraw(150.0);

    std::cout << "\n--- Testing Robustness Issues ---\n";

    // 1. Negative initial balance allowed by constructor
    BankAccount account2(102, -500.0); // Constructor should have clamped this to 0
    std::cout << "Account 2 balance after creation: " << account2.getBalance() << std::endl;

    // 2. Deposit a negative amount (major robustness flaw)
    account2.deposit(-100.0); // This should be rejected by a robust deposit method
    std::cout << "Account 2 balance after negative deposit: " << account2.getBalance() << std::endl;

    // 3. Attempt to withdraw more than current (potentially negative) balance
    account2.withdraw(200.0); // Should fail due to insufficient funds
    account2.withdraw(50.0);  // Should fail
    std::cout << "Account 2 final balance: " << account2.getBalance() << std::endl;

    BankAccount account3(103, 0.0); // Account starting at zero
    std::cout << "\nAccount 3 initial balance: " << account3.getBalance() << std::endl;
    account3.deposit(-50.0); // Another negative deposit
    account3.withdraw(10.0); // Should fail as balance is now negative
    std::cout << "Account 3 final balance: " << account3.getBalance() << std::endl;

    return 0;
}