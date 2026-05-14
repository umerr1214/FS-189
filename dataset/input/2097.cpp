#include <iostream>
#include <string>
#include <iomanip>

class BankAccount {
private:
    double balance;

public:
    // Constructor to initialize balance, preventing negative initial balance
    BankAccount(double initialBalance = 0.0) : balance(initialBalance) {
        if (balance < 0) {
            balance = 0.0;
            // Using cerr for warnings/errors that don't prevent program execution
            std::cerr << "Warning: Initial balance cannot be negative. Setting to 0.0." << std::endl;
        }
    }

    // Deposits a positive amount into the account
    void deposit(double amount) {
        if (amount <= 0) { // Prevents negative or zero amounts
            std::cout << "Deposit failed: amount must be positive." << std::endl;
            return;
        }
        balance += amount;
        std::cout << "Deposit successful." << std::endl;
    }

    // Withdraws a positive amount from the account, preventing overdrafts
    void withdraw(double amount) {
        if (amount <= 0) { // Prevents negative or zero amounts
            std::cout << "Withdrawal failed: amount must be positive." << std::endl;
            return;
        }
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawal successful." << std::endl;
        } else {
            std::cout << "Withdrawal failed: insufficient funds." << std::endl;
        }
    }

    // Returns the current balance
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
    account.deposit(0.0);
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "\n--- Withdraw Tests ---" << std::endl;
    std::cout << "Withdrawing 30.0..." << std::endl;
    account.withdraw(30.0);
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Attempting to withdraw 150.0 (overdraft)..." << std::endl;
    account.withdraw(150.0);
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Attempting to withdraw -10.0..." << std::endl;
    account.withdraw(-10.0);
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Attempting to withdraw 0.0..." << std::endl;
    account.withdraw(0.0);
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Withdrawing 120.0 (to zero)..." << std::endl;
    account.withdraw(120.0);
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Attempting to withdraw 1.0 from zero..." << std::endl;
    account.withdraw(1.0);
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "\nFinal balance: " << account.getBalance() << std::endl;

    return 0;
}