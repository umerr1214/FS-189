#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip> // For output consistency
#include <utility> // For std::move

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    // Constructor: Initializes account with a number and an optional initial balance.
    // Uses member initializer list for efficiency and clarity.
    // Uses std::move for accountNumber to optimize string construction.
    BankAccount(std::string accNum, double initialBalance = 0.0)
        : accountNumber(std::move(accNum)), balance(initialBalance) {}

    // Deposit method: Adds a positive amount to the account balance.
    // Returns true if deposit was successful, false otherwise.
    void deposit(double amount) { // Changed return type to void as per question
        if (amount > 0.0) {
            balance += amount;
        }
        // No action for zero or negative amounts, consistent with safe management.
    }

    // Withdraw method: Removes a positive amount from the account balance,
    // provided there are sufficient funds.
    // Returns true if withdrawal was successful, false otherwise.
    void withdraw(double amount) { // Changed return type to void as per question
        if (amount > 0.0 && balance >= amount) {
            balance -= amount;
        }
        // No action for zero/negative amounts or insufficient funds, consistent with safe management.
    }

    // getBalance method: Returns the current balance.
    // Marked const as it does not modify the object's state.
    double getBalance() const {
        return balance;
    }

    // getAccountNumber method: Returns the account number.
    // Marked const as it does not modify the object's state.
    std::string getAccountNumber() const {
        return accountNumber;
    }
};

int main() {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(0); // For consistent output of whole numbers

    // Test Case 1: Initial creation and balance
    BankAccount acc1("ACC001", 1000.0);
    oss << "Account " << acc1.getAccountNumber() << " initial balance: " << acc1.getBalance() << std::endl;

    // Test Case 2: Deposit
    acc1.deposit(500.0);
    oss << "Account " << acc1.getAccountNumber() << " after deposit 500: " << acc1.getBalance() << std::endl;

    // Test Case 3: Valid withdrawal
    acc1.withdraw(200.0);
    oss << "Account " << acc1.getAccountNumber() << " after withdraw 200: " << acc1.getBalance() << std::endl;

    // Test Case 4: Attempt to withdraw more than balance (overdraft)
    // Correct version: prevents overdraft, balance remains unchanged
    acc1.withdraw(1500.0);
    oss << "Account " << acc1.getAccountNumber() << " after withdraw 1500: " << acc1.getBalance() << std::endl;

    // Test Case 5: Attempt to deposit negative amount
    // Correct version: prevents negative deposit, balance remains unchanged
    acc1.deposit(-100.0);
    oss << "Account " << acc1.getAccountNumber() << " after deposit -100: " << acc1.getBalance() << std::endl;

    // Test Case 6: Attempt to withdraw negative amount
    // Correct version: prevents negative withdrawal, balance remains unchanged
    acc1.withdraw(-50.0);
    oss << "Account " << acc1.getAccountNumber() << " after withdraw -50: " << acc1.getBalance() << std::endl;

    // Additional test case
    BankAccount acc2("ACC002"); // Initial balance 0.0
    oss << "Account " << acc2.getAccountNumber() << " initial balance: " << acc2.getBalance() << std::endl;
    acc2.deposit(250.0);
    oss << "Account " << acc2.getAccountNumber() << " after deposit 250: " << acc2.getBalance() << std::endl;
    acc2.withdraw(250.0);
    oss << "Account " << acc2.getAccountNumber() << " after withdraw 250: " << acc2.getBalance() << std::endl;
    acc2.withdraw(1.0); // Attempt to overdraft from 0
    oss << "Account " << acc2.getAccountNumber() << " after withdraw 1: " << acc2.getBalance() << std::endl;


    std::cout << oss.str();
    return 0;
}