#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Required for std::fixed, std::setprecision

class BankAccount {
private:
    const std::string accountNumber; // Read-only after creation
    double balance;                  // Private

public:
    // Constructor: Initializes accountNumber and balance.
    // accountNumber is passed by const reference for efficiency.
    // Balance is initialized to 0.0.
    BankAccount(const std::string& accNum) : accountNumber(accNum), balance(0.0) {
        // No validation for empty account number is specified in question,
        // but a robust version might add it. Here, we stick to explicit requirements.
    }

    // Deposit method: Adds amount to balance with validation.
    // Returns true on success, false on failure.
    bool deposit(double amount) {
        if (amount <= 0.0) {
            // std::cout << "Deposit failed: Amount must be positive." << std::endl; // For testing, output in driver
            return false;
        }
        balance += amount;
        return true;
    }

    // Withdraw method: Subtracts amount from balance with validation.
    // Returns true on success, false on failure.
    bool withdraw(double amount) {
        if (amount <= 0.0) {
            // std::cout << "Withdrawal failed: Amount must be positive." << std::endl; // For testing, output in driver
            return false;
        }
        if (balance < amount) {
            // std::cout << "Withdrawal failed: Insufficient balance." << std::endl; // For testing, output in driver
            return false;
        }
        balance -= amount;
        return true;
    }

    // Getters
    std::string getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    // Set output precision globally for main
    std::cout << std::fixed << std::setprecision(2);

    // Test Case 1: Create a BankAccount
    BankAccount account1("ACC12345");
    std::cout << "Account created: " << account1.getAccountNumber() << ", Initial Balance: " << account1.getBalance() << std::endl;

    // Test Case 2: Valid Deposit
    if (account1.deposit(100.50)) {
        std::cout << "Deposited 100.50. New Balance: " << account1.getBalance() << std::endl;
    } else {
        std::cout << "Deposit of 100.50 failed." << std::endl;
    }

    // Test Case 3: Invalid Deposit (negative amount)
    if (account1.deposit(-20.00)) {
        std::cout << "Deposited -20.00. New Balance: " << account1.getBalance() << std::endl;
    } else {
        std::cout << "Deposit of -20.00 failed (as expected)." << std::endl;
    }

    // Test Case 4: Invalid Deposit (zero amount)
    if (account1.deposit(0.00)) {
        std::cout << "Deposited 0.00. New Balance: " << account1.getBalance() << std::endl;
    } else {
        std::cout << "Deposit of 0.00 failed (as expected)." << std::endl;
    }

    // Test Case 5: Valid Withdrawal
    if (account1.withdraw(50.25)) {
        std::cout << "Withdrew 50.25. New Balance: " << account1.getBalance() << std::endl;
    } else {
        std::cout << "Withdrawal of 50.25 failed." << std::endl;
    }

    // Test Case 6: Invalid Withdrawal (insufficient balance)
    if (account1.withdraw(200.00)) {
        std::cout << "Withdrew 200.00. New Balance: " << account1.getBalance() << std::endl;
    } else {
        std::cout << "Withdrawal of 200.00 failed (insufficient balance, as expected)." << std::endl;
    }

    // Test Case 7: Invalid Withdrawal (negative amount)
    if (account1.withdraw(-10.00)) {
        std::cout << "Withdrew -10.00. New Balance: " << account1.getBalance() << std::endl;
    } else {
        std::cout << "Withdrawal of -10.00 failed (as expected)." << std::endl;
    }

    // Test Case 8: Invalid Withdrawal (zero amount)
    if (account1.withdraw(0.00)) {
        std::cout << "Withdrew 0.00. New Balance: " << account1.getBalance() << std::endl;
    } else {
        std::cout << "Withdrawal of 0.00 failed (as expected)." << std::endl;
    }

    // Test Case 9: Withdrawal exactly equal to balance
    if (account1.deposit(100.00)) { // Bring balance to 150.25 + 100.00 = 200.25
        std::cout << "Deposited 100.00. New Balance: " << account1.getBalance() << std::endl;
    }
    if (account1.withdraw(200.25)) {
        std::cout << "Withdrew 200.25. New Balance: " << account1.getBalance() << std::endl;
    } else {
        std::cout << "Withdrawal of 200.25 failed." << std::endl;
    }

    std::cout << "\nFinal state for account " << account1.getAccountNumber()
              << ": Balance: " << account1.getBalance() << std::endl;

    // Another account
    BankAccount account2("ACC99887");
    std::cout << "\nAccount created: " << account2.getAccountNumber() << ", Initial Balance: " << account2.getBalance() << std::endl;
    account2.deposit(500.00);
    account2.withdraw(150.00);
    account2.deposit(75.00);
    account2.withdraw(425.00); // Should succeed, balance becomes 0
    account2.withdraw(1.00); // Should fail
    std::cout << "\nFinal state for account " << account2.getAccountNumber()
              << ": Balance: " << account2.getBalance() << std::endl;

    return 0;
}