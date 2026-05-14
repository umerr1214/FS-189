#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    double balance;

public:
    // Constructor
    BankAccount(double initialBalance = 0.0) : balance(initialBalance) {}

    // Public method to deposit money
    void deposit(double amount) {
        // Robustness issue: Does not validate if amount is positive.
        // A negative amount will reduce the balance, acting like an undocumented withdrawal.
        balance += amount;
    }

    // Public method to withdraw money
    void withdraw(double amount) {
        // Robustness issue: Does not validate if amount is positive.
        // A negative amount will increase the balance, acting like an undocumented deposit.
        // Also, does not check for sufficient balance, allowing overdrafts.
        balance -= amount;
    }

    // Public method to get the current balance
    double getBalance() const {
        return balance;
    }
};

int main() {
    // Set precision for output
    std::cout << std::fixed << std::setprecision(2);

    BankAccount account(100.0);
    std::cout << "Initial balance: " << account.getBalance() << std::endl; // Expected: 100.00

    // Demonstrate robustness issue: negative deposit
    std::cout << "Attempting deposit of -50.00..." << std::endl;
    account.deposit(-50.0); // This should ideally be rejected or handled as an error
    std::cout << "Balance after negative deposit: " << account.getBalance() << std::endl; // Expected: 50.00 (incorrect behavior)

    // Demonstrate robustness issue: withdrawal exceeding balance
    std::cout << "Attempting withdraw of 100.00..." << std::endl;
    account.withdraw(100.0); // This should ideally be rejected due to insufficient funds
    std::cout << "Balance after over-withdrawal: " << account.getBalance() << std::endl; // Expected: -50.00 (incorrect behavior)

    // Demonstrate robustness issue: negative withdrawal
    std::cout << "Attempting withdraw of -20.00..." << std::endl;
    account.withdraw(-20.0); // This should ideally be rejected or handled as an error
    std::cout << "Balance after negative withdrawal: " << account.getBalance() << std::endl; // Expected: -30.00 (incorrect behavior)

    std::cout << "Final balance: " << account.getBalance() << std::endl; // Expected: -30.00

    return 0;
}