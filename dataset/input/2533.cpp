#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    double balance;

public:
    // Constructor initializes balance to 0.0
    // Robustness issue: deposit/withdraw accept 0, violating 'positive amounts'
    BankAccount() : balance(0.0) {}

    bool deposit(double amount) {
        // Robustness issue: Accepts 0.0, which is not strictly positive.
        if (amount >= 0.0) {
            balance += amount;
            return true;
        }
        return false;
    }

    bool withdraw(double amount) {
        // Robustness issue: Accepts 0.0, which is not strictly positive.
        // Also, it's possible for floating point arithmetic to cause issues if balance is very close to amount,
        // but for this example, the main robustness issue is accepting 0.
        if (amount >= 0.0 && balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    BankAccount account;

    // Test cases
    std::cout << "Initial balance: " << account.getBalance() << std::endl;

    // Deposit tests
    std::cout << "\n--- Deposit Tests ---" << std::endl;
    std::cout << "Depositing 100.50... " << (account.deposit(100.50) ? "SUCCESS" : "FAILURE") << std::endl;
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Depositing -20.00... " << (account.deposit(-20.00) ? "SUCCESS" : "FAILURE") << std::endl;
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Depositing 0.00... " << (account.deposit(0.00) ? "SUCCESS" : "FAILURE") << std::endl; // Robustness issue: Should fail, but succeeds
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Depositing 50.00... " << (account.deposit(50.00) ? "SUCCESS" : "FAILURE") << std::endl;
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    // Withdraw tests
    std::cout << "\n--- Withdraw Tests ---" << std::endl;
    std::cout << "Withdrawing 75.25... " << (account.withdraw(75.25) ? "SUCCESS" : "FAILURE") << std::endl;
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Withdrawing 100.00 (insufficient funds)... " << (account.withdraw(100.00) ? "SUCCESS" : "FAILURE") << std::endl;
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Withdrawing -10.00... " << (account.withdraw(-10.00) ? "SUCCESS" : "FAILURE") << std::endl;
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Withdrawing 0.00... " << (account.withdraw(0.00) ? "SUCCESS" : "FAILURE") << std::endl; // Robustness issue: Should fail, but succeeds
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Withdrawing 75.25... " << (account.withdraw(75.25) ? "SUCCESS" : "FAILURE") << std::endl;
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "\nFinal balance: " << account.getBalance() << std::endl;

    return 0;
}