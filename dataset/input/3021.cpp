#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For std::fixed and std::setprecision
#include <utility> // For std::move

class BankAccount {
private:
    std::string accountNumber;
    std::string ownerName;
    double balance;

public:
    // Constructor to initialize account details and initial balance.
    // Uses std::move for string parameters to optimize performance by avoiding unnecessary copies.
    BankAccount(std::string accNum, std::string owner, double initialBalance)
        : accountNumber(std::move(accNum)),
          ownerName(std::move(owner)),
          balance(initialBalance) {
        // Ensures the initial balance is not negative.
        if (balance < 0.0) {
            balance = 0.0;
        }
    }

    // Deposits a specified amount into the account.
    // Returns true if the deposit was successful (amount > 0), false otherwise.
    bool deposit(double amount) {
        if (amount > 0.0) {
            balance += amount;
            return true;
        }
        return false; // Cannot deposit a non-positive amount.
    }

    // Withdraws a specified amount from the account.
    // Returns true if the withdrawal was successful (amount > 0 and sufficient funds), false otherwise.
    bool withdraw(double amount) {
        if (amount > 0.0 && balance - amount >= 0.0) {
            balance -= amount;
            return true;
        }
        return false; // Withdrawal failed due to insufficient funds or non-positive amount.
    }

    // Returns the current balance of the account.
    // Marked `const` as it does not modify the object's state.
    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount myAccount("12345", "Alice Wonderland", 1000.0);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Initial balance: $" << myAccount.getBalance() << std::endl;

    // Test successful deposit
    if (myAccount.deposit(250.0)) {
        std::cout << "Deposited $250.00. New balance: $" << myAccount.getBalance() << std::endl;
    } else {
        std::cout << "Failed to deposit $250.00." << std::endl;
    }

    // Test successful withdrawal
    if (myAccount.withdraw(300.0)) {
        std::cout << "Withdrew $300.00. New balance: $" << myAccount.getBalance() << std::endl;
    } else {
        std::cout << "Failed to withdraw $300.00." << std::endl;
    }

    // Test withdrawal with insufficient funds
    if (myAccount.withdraw(1000.0)) {
        std::cout << "Withdrew $1000.00. New balance: $" << myAccount.getBalance() << std::endl;
    } else {
        std::cout << "Failed to withdraw $1000.00 (insufficient funds). Current balance: $" << myAccount.getBalance() << std::endl;
    }

    // Test deposit of zero amount (should fail)
    if (myAccount.deposit(0.0)) {
        std::cout << "Deposited $0.00. New balance: $" << myAccount.getBalance() << std::endl;
    } else {
        std::cout << "Failed to deposit $0.00 (invalid amount). Current balance: $" << myAccount.getBalance() << std::endl;
    }

    // Test withdrawal of negative amount (should fail)
    if (myAccount.withdraw(-50.0)) {
        std::cout << "Withdrew $-50.00. New balance: $" << myAccount.getBalance() << std::endl;
    } else {
        std::cout << "Failed to withdraw $-50.00 (invalid amount). Current balance: $" << myAccount.getBalance() << std::endl;
    }

    // Test another successful withdrawal
    if (myAccount.withdraw(50.0)) {
        std::cout << "Withdrew $50.00. New balance: $" << myAccount.getBalance() << std::endl;
    } else {
        std::cout << "Failed to withdraw $50.00." << std::endl;
    }

    return 0;
}