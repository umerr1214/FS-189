#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision
#include <stdexcept> // For std::invalid_argument

class BankAccount {
private:
    const std::string accountNumber; // accountNumber is set only in constructor and is read-only
    double balance;

public:
    // Constructor with validation and default initial balance
    BankAccount(const std::string& accNum, double initialBalance = 0.0)
        : accountNumber(accNum) {
        if (accountNumber.empty()) {
            throw std::invalid_argument("Account number cannot be empty.");
        }
        if (initialBalance < 0) {
            throw std::invalid_argument("Initial balance cannot be negative.");
        }
        balance = initialBalance;
    }

    // Public method to deposit funds with validation
    bool deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Deposit amount must be positive. No action taken. Current balance: "
                      << std::fixed << std::setprecision(2) << balance << std::endl;
            return false;
        }
        balance += amount;
        std::cout << "Deposit of " << std::fixed << std::setprecision(2) << amount
                  << " successful. New balance: " << balance << std::endl;
        return true;
    }

    // Public method to withdraw funds with comprehensive validation
    bool withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Withdrawal amount must be positive. No action taken. Current balance: "
                      << std::fixed << std::setprecision(2) << balance << std::endl;
            return false;
        }
        if (amount > balance) {
            std::cout << "Withdrawal of " << std::fixed << std::setprecision(2) << amount
                      << " failed. Insufficient funds. Current balance: " << balance << std::endl;
            return false;
        }
        balance -= amount;
        std::cout << "Withdrawal of " << std::fixed << std::setprecision(2) << amount
                  << " successful. New balance: " << balance << std::endl;
        return true;
    }

    // Read-only access to accountNumber (const method)
    const std::string& getAccountNumber() const {
        return accountNumber;
    }

    // Read-only access to balance (const method)
    double getBalance() const {
        return balance;
    }
};

int main() {
    std::cout << "--- Testing BankAccount (Correct Version) ---" << std::endl;

    // Test case 1: Create an account with valid initial balance
    BankAccount acc1("ACC003", 1000.00);
    std::cout << "Account " << acc1.getAccountNumber() << " created with balance: "
              << std::fixed << std::setprecision(2) << acc1.getBalance() << std::endl;

    // Test case 2: Valid deposit
    acc1.deposit(250.00); // Expected: Balance 1250.00

    // Test case 3: Valid withdrawal
    acc1.withdraw(100.00); // Expected: Balance 1150.00

    // Test case 4: Deposit zero amount (should fail)
    acc1.deposit(0.00); // Expected: Failed, Balance 1150.00

    // Test case 5: Deposit negative amount (should fail)
    acc1.deposit(-50.00); // Expected: Failed, Balance 1150.00

    // Test case 6: Withdrawal exceeding balance (should fail)
    acc1.withdraw(1200.00); // Expected: Failed, Balance 1150.00

    // Test case 7: Withdrawal zero amount (should fail)
    acc1.withdraw(0.00); // Expected: Failed, Balance 1150.00

    // Test case 8: Withdrawal negative amount (should fail)
    acc1.withdraw(-20.00); // Expected: Failed, Balance 1150.00

    // Test case 9: Another valid withdrawal
    acc1.withdraw(150.00); // Expected: Balance 1000.00

    // Test case 10: Create an account with default initial balance
    BankAccount acc2("ACC004");
    std::cout << "Account " << acc2.getAccountNumber() << " created with balance: "
              << std::fixed << std::setprecision(2) << acc2.getBalance() << std::endl;
    acc2.deposit(500.00); // Expected: Balance 500.00

    // Test case 11: Constructor validation - invalid account number (empty)
    try {
        BankAccount invalidAcc("", 100.00);
        std::cout << "ERROR: Created account with empty number." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught expected exception for empty account number: " << e.what() << std::endl;
    }

    // Test case 12: Constructor validation - negative initial balance
    try {
        BankAccount invalidAcc2("ACC005", -50.00);
        std::cout << "ERROR: Created account with negative initial balance." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught expected exception for negative initial balance: " << e.what() << std::endl;
    }

    std::cout << "\nFinal balance for " << acc1.getAccountNumber() << ": "
              << std::fixed << std::setprecision(2) << acc1.getBalance() << std::endl;
    std::cout << "Final balance for " << acc2.getAccountNumber() << ": "
              << std::fixed << std::setprecision(2) << acc2.getBalance() << std::endl;

    return 0;
}