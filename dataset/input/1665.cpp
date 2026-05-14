#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    double balance;

public:
    // Constructor: Ensures initial balance is non-negative
    BankAccount(double initialBalance = 0.0) : balance(initialBalance > 0.0 ? initialBalance : 0.0) {}

    // Public method to deposit money
    // Returns true if deposit was successful, false otherwise (e.g., amount <= 0)
    bool deposit(double amount) {
        if (amount > 0.0) {
            balance += amount;
            return true;
        }
        return false; // Cannot deposit zero or negative amounts
    }

    // Public method to withdraw money
    // Returns true if withdrawal was successful, false otherwise (e.g., amount <= 0 or insufficient funds)
    bool withdraw(double amount) {
        if (amount > 0.0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false; // Cannot withdraw zero/negative amounts or if insufficient balance
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
    std::cout << "Initial balance: " << account.getBalance() << std::endl;

    // Test valid deposit
    std::cout << "Attempting deposit of 50.00: ";
    if (account.deposit(50.0)) {
        std::cout << "Success. New balance: " << account.getBalance() << std::endl;
    } else {
        std::cout << "Failed. Balance: " << account.getBalance() << std::endl;
    }

    // Test valid withdrawal
    std::cout << "Attempting withdraw of 20.00: ";
    if (account.withdraw(20.0)) {
        std::cout << "Success. New balance: " << account.getBalance() << std::endl;
    } else {
        std::cout << "Failed. Balance: " << account.getBalance() << std::endl;
    }

    // Test invalid deposit (negative amount)
    std::cout << "Attempting deposit of -10.00: ";
    if (account.deposit(-10.0)) {
        std::cout << "Success. New balance: " << account.getBalance() << std::endl;
    } else {
        std::cout << "Failed (negative amount). Balance: " << account.getBalance() << std::endl;
    }

    // Test invalid withdrawal (insufficient funds)
    std::cout << "Attempting withdraw of 200.00: ";
    if (account.withdraw(200.0)) {
        std::cout << "Success. New balance: " << account.getBalance() << std::endl;
    } else {
        std::cout << "Failed (insufficient funds). Balance: " << account.getBalance() << std::endl;
    }

    // Test invalid withdrawal (zero amount)
    std::cout << "Attempting withdraw of 0.00: ";
    if (account.withdraw(0.0)) {
        std::cout << "Success. New balance: " << account.getBalance() << std::endl;
    } else {
        std::cout << "Failed (zero amount). Balance: " << account.getBalance() << std::endl;
    }

    // Test another valid withdrawal
    std::cout << "Attempting withdraw of 30.00: ";
    if (account.withdraw(30.0)) {
        std::cout << "Success. New balance: " << account.getBalance() << std::endl;
    } else {
        std::cout << "Failed. Balance: " << account.getBalance() << std::endl;
    }
    
    std::cout << "Final balance: " << account.getBalance() << std::endl;

    return 0;
}