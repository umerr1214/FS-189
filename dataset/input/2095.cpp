#include <iostream>
#include <string>
#include <iomanip>
#include <limits> // For std::numeric_limits and isnan

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance = 0.0) : balance(initialBalance) {
        // A truly robust constructor might also validate initialBalance
        // For this robustness example, we assume initialBalance is valid.
    }

    void deposit(double amount) {
        if (std::isnan(amount) || amount < 0) { // Prevents NaN and negative amounts
            std::cout << "Deposit failed: amount must be a non-negative number." << std::endl;
            return;
        }
        // Robustness Issue 1: Allows positive infinity to be deposited, corrupting the balance.
        // A robust system should typically reject infinite amounts.
        // E.g., if (std::isinf(amount)) { ... handle error ... }

        // Robustness Issue 2: Gives a "successful" message for a zero-amount deposit,
        // which is misleading as no actual change occurs.
        if (amount == 0) {
            std::cout << "Deposit successful (no change to balance for zero amount)." << std::endl;
        } else {
            balance += amount;
            std::cout << "Deposit successful." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (std::isnan(amount) || amount < 0) { // Prevents NaN and negative amounts
            std::cout << "Withdrawal failed: amount must be a non-negative number." << std::endl;
            return;
        }
        // Robustness Issue 3: Gives a "successful" message for a zero-amount withdrawal,
        // which is misleading as no actual change occurs.
        if (amount == 0) {
            std::cout << "Withdrawal successful (no change to balance for zero amount)." << std::endl;
            return;
        }
        
        // If balance is infinity, balance >= amount will always be true for finite amount,
        // and balance - amount will still be infinity. This is part of robustness issue 1.
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawal successful." << std::endl;
        } else {
            std::cout << "Withdrawal failed: insufficient funds." << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::fixed << std::setprecision(2);

    BankAccount account(100.0);
    std::cout << "Initial balance: " << account.getBalance() << std::endl;

    std::cout << "\n--- Deposit Tests ---" << std::endl;
    std::cout << "Depositing 50.0..." << std::endl;
    account.deposit(50.0);
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Attempting to deposit -20.0..." << std::endl;
    account.deposit(-20.0);
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Attempting to deposit 0.0..." << std::endl;
    account.deposit(0.0); // Robustness Issue 2: Misleading success message for zero amount
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Attempting to deposit infinity..." << std::endl;
    account.deposit(std::numeric_limits<double>::infinity()); // Robustness Issue 1: Corrupts balance
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "\n--- Withdraw Tests ---" << std::endl;
    std::cout << "Withdrawing 30.0..." << std::endl;
    account.withdraw(30.0); // If balance is inf, this "succeeds" but balance remains inf
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Attempting to withdraw 150.0 (overdraft)..." << std::endl;
    account.withdraw(150.0); // If balance is inf, this "succeeds" but balance remains inf
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Attempting to withdraw -10.0..." << std::endl;
    account.withdraw(-10.0);
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Attempting to withdraw 0.0..." << std::endl;
    account.withdraw(0.0); // Robustness Issue 3: Misleading success message for zero amount
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Withdrawing 120.0 (to zero)..." << std::endl;
    account.withdraw(120.0); // If balance is inf, this "succeeds" but balance remains inf
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Attempting to withdraw 1.0 from zero..." << std::endl;
    account.withdraw(1.0); // If balance is inf, this "succeeds" but balance remains inf
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "\nFinal balance: " << account.getBalance() << std::endl;

    return 0;
}