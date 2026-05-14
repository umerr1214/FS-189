#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Required for std::fixed, std::setprecision
#include <cmath>   // Required for std::abs

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(std::string accNum) : accountNumber(accNum), balance(0.0) {
        // Robustness issue: No validation for accountNumber in constructor (e.g., empty string is allowed)
        // This could lead to issues later if an empty account number is considered invalid by other systems.
    }

    // Deposit method
    void deposit(double amount) {
        // Robustness issue: Accepts negative amounts, but then takes absolute value.
        // This hides an invalid input instead of rejecting it, which is not robust error handling.
        if (std::isnan(amount) || std::isinf(amount)) {
            std::cout << "Deposit failed for account " << accountNumber << ": Invalid amount (NaN/Inf)." << std::endl;
            return;
        }
        double actualAmount = std::abs(amount); // Automatically converts negative deposits to positive
        if (actualAmount == 0.0) {
            std::cout << "Deposit failed for account " << accountNumber << ": Amount must be positive." << std::endl;
            return;
        }
        balance += actualAmount;
        std::cout << "Deposited " << std::fixed << std::setprecision(2) << actualAmount
                  << " to account " << accountNumber << ". New balance: " << balance << std::endl;
    }

    // Withdraw method
    void withdraw(double amount) {
        // Robustness issue: Direct comparison of doubles (balance >= amount) can be problematic
        // when balance is very close to amount due to floating-point inaccuracies.
        // Also, it doesn't explicitly check for NaN/Inf for amount, which could lead to unexpected behavior.
        if (amount < 0.0) {
            std::cout << "Withdrawal failed for account " << accountNumber << ": Amount cannot be negative." << std::endl;
            return;
        }
        if (amount == 0.0) {
            std::cout << "Withdrawal failed for account " << accountNumber << ": Amount must be positive." << std::endl;
            return;
        }
        if (balance >= amount) { // Potential floating-point precision issue here
            balance -= amount;
            std::cout << "Withdrew " << std::fixed << std::setprecision(2) << amount
                      << " from account " << accountNumber << ". New balance: " << balance << std::endl;
        } else {
            std::cout << "Withdrawal failed for account " << accountNumber
                      << ": Insufficient balance. Current balance: " << std::fixed << std::setprecision(2) << balance
                      << ", requested: " << amount << std::endl;
        }
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
    std::cout << std::fixed << std::setprecision(2); // Set precision for all outputs

    // Test Case 1: Create an account with an empty account number (robustness issue scenario)
    BankAccount acc1("");
    std::cout << "Created account: " << acc1.getAccountNumber() << ", Balance: " << acc1.getBalance() << std::endl;

    // Test Case 2: Standard deposit
    acc1.deposit(100.0); // Should deposit 100.00

    // Test Case 3: Deposit a negative amount (robustness issue scenario)
    acc1.deposit(-50.0); // Should become positive 50.00 due to std::abs

    // Test Case 4: Standard withdrawal
    acc1.withdraw(75.0); // Should withdraw 75.00

    // Test Case 5: Withdrawal with insufficient balance
    acc1.withdraw(500.0); // Should fail

    // Test Case 6: Deposit zero
    acc1.deposit(0.0); // Should fail

    // Test Case 7: Withdraw zero
    acc1.withdraw(0.0); // Should fail

    // Test Case 8: Withdrawal exactly equal to balance (potential precision issue)
    acc1.deposit(25.0); // Balance becomes 100.00
    acc1.withdraw(100.0); // Should succeed, if precision allows

    std::cout << "\nFinal state for account " << acc1.getAccountNumber()
              << ": Balance: " << acc1.getBalance() << std::endl;

    // Another account
    BankAccount acc2("ACC789");
    std::cout << "\nCreated account: " << acc2.getAccountNumber() << ", Balance: " << acc2.getBalance() << std::endl;
    acc2.deposit(1000.0);
    acc2.withdraw(500.0);
    acc2.deposit(250.0);
    acc2.withdraw(750.0);
    acc2.withdraw(1.0); // Should fail
    std::cout << "\nFinal state for account " << acc2.getAccountNumber()
              << ": Balance: " << acc2.getBalance() << std::endl;

    return 0;
}