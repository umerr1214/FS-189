#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    // Readability issue: Inconsistent naming convention (acc_num_ vs bal_)
    std::string acc_num_; // Should be const
    double bal_; // Should be balance

public:
    // Constructor
    // Efficiency issue: Passing std::string by value (acc) instead of const reference
    BankAccount(std::string acc, double initBal)
        : acc_num_(acc), bal_(initBal) {
        // No validation for acc_num or initBal
    }

    // Public method to deposit funds
    void deposit(double amt) { // Readability issue: 'amt' is short for amount
        if (amt > 0.0) {
            bal_ += amt;
            std::cout << "Deposit of " << std::fixed << std::setprecision(2) << amt
                      << " successful. New balance: " << bal_ << std::endl;
        } else {
            // Readability issue: Redundant else branch, could just do nothing
            std::cout << "Deposit amount must be positive. No action taken. Current balance: " << bal_ << std::endl;
        }
    }

    // Public method to withdraw funds
    bool withdraw(double amt) { // Readability issue: 'amt' is short for amount
        if (amt > 0.0) { // Checks if amount is positive
            if (bal_ >= amt) { // Checks if sufficient funds
                bal_ -= amt;
                std::cout << "Withdrawal of " << std::fixed << std::setprecision(2) << amt
                          << " successful. New balance: " << bal_ << std::endl;
                return true;
            } else {
                std::cout << "Withdrawal of " << std::fixed << std::setprecision(2) << amt
                          << " failed. Insufficient funds. Current balance: " << bal_ << std::endl;
                return false;
            }
        } else {
            // Readability issue: Redundant else branch, could just return false
            std::cout << "Withdrawal amount must be positive. No action taken. Current balance: " << bal_ << std::endl;
            return false;
        }
    }

    // Read-only access to accountNumber
    // Readability issue: Not a const method, even though it doesn't modify state
    std::string getAccNum() { // Readability issue: Short, inconsistent getter name
        return acc_num_;
    }

    // Read-only access to balance
    // Readability issue: Not a const method, even though it doesn't modify state
    double getBal() { // Readability issue: Short, inconsistent getter name
        return bal_;
    }
};

int main() {
    std::cout << "--- Testing BankAccount (Readability / Efficiency Issue) ---" << std::endl;

    // Create an account
    BankAccount my_account("ACC002", 500.00); // Readability issue: my_account instead of account2
    std::cout << "Account " << my_account.getAccNum() << " created with balance: "
              << std::fixed << std::setprecision(2) << my_account.getBal() << std::endl;

    // Test cases
    my_account.deposit(100.00); // Expected: Balance 600.00
    my_account.withdraw(50.00); // Expected: Balance 550.00
    my_account.deposit(-20.00); // Expected: Failed, Balance 550.00
    my_account.withdraw(600.00); // Expected: Failed, Balance 550.00
    my_account.withdraw(-10.00); // Expected: Failed, Balance 550.00
    my_account.withdraw(0.00); // Expected: Failed, Balance 550.00

    std::cout << "\nFinal balance for " << my_account.getAccNum() << ": "
              << std::fixed << std::setprecision(2) << my_account.getBal() << std::endl;

    return 0;
}