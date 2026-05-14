#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip> // For output consistency

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    // Constructor: Initializes account with a number and an optional initial balance.
    BankAccount(std::string accNum, double initialBalance = 0.0)
        : accountNumber(accNum), balance(initialBalance) {}

    // Robustness Issue: Does not validate amount > 0. Allows negative deposits.
    void deposit(double amount) {
        // A negative amount will reduce the balance, which is an incorrect behavior for a deposit.
        balance += amount;
    }

    // Robustness Issue: Does not validate amount > 0 and does not prevent overdrafts.
    // Allows negative withdrawals (which increase balance) and allows balance to go negative.
    void withdraw(double amount) {
        // If amount is negative, balance increases (acting as a deposit).
        // If amount is positive and greater than balance, balance goes negative (overdraft).
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }

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
    // Robustness issue: allows overdraft, balance goes negative
    acc1.withdraw(1500.0);
    oss << "Account " << acc1.getAccountNumber() << " after withdraw 1500: " << acc1.getBalance() << std::endl;

    // Test Case 5: Attempt to deposit negative amount
    // Robustness issue: allows negative deposit, balance decreases
    acc1.deposit(-100.0);
    oss << "Account " << acc1.getAccountNumber() << " after deposit -100: " << acc1.getBalance() << std::endl;

    // Test Case 6: Attempt to withdraw negative amount
    // Robustness issue: allows negative withdrawal, balance increases
    acc1.withdraw(-50.0);
    oss << "Account " << acc1.getAccountNumber() << " after withdraw -50: " << acc1.getBalance() << std::endl;

    // Additional test case for robustness
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