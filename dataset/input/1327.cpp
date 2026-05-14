#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    // Constructor: Allows negative initial balance (Robustness Issue)
    BankAccount(std::string accNum, std::string holderName, double initialBalance)
        : accountNumber(accNum), accountHolderName(holderName), balance(initialBalance) {
        std::cout << "Account " << accountNumber << " created for " << accountHolderName 
                  << " with initial balance: " << std::fixed << std::setprecision(2) << balance << std::endl;
    }

    // Deposit method: Accepts zero amount (Robustness Issue)
    void deposit(double amount) {
        if (amount >= 0) { // Should be amount > 0 for "positive amounts only"
            balance += amount;
            std::cout << "Depositing " << std::fixed << std::setprecision(2) << amount 
                      << "... Success. New balance: " << balance << std::endl;
        } else {
            std::cout << "Attempting to deposit " << std::fixed << std::setprecision(2) << amount 
                      << "... Failed. Amount must be non-negative." << std::endl;
        }
    }

    // Withdraw method: Does not prevent withdrawal of negative amounts (Robustness Issue)
    void withdraw(double amount) {
        // Doesn't check if amount > 0. A negative 'amount' will effectively be a deposit.
        if (balance >= amount) { // Overdraft check is still here
            balance -= amount;
            std::cout << "Withdrawing " << std::fixed << std::setprecision(2) << amount 
                      << "... Success. New balance: " << balance << std::endl;
        } else {
            std::cout << "Attempting to withdraw " << std::fixed << std::setprecision(2) << amount 
                      << "... Insufficient funds." << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    std::string getAccountNumber() const {
        return accountNumber;
    }
    
    std::string getAccountHolderName() const {
        return accountHolderName;
    }
};

int main() {
    // Demonstrating Robustness Issues:
    // 1. Constructor allows negative initial balance
    BankAccount myAccount("12345", "Alice", -50.00); 
    
    // 2. deposit accepts 0
    myAccount.deposit(50.00); // Should work
    myAccount.deposit(0.00);  // Robustness issue: Accepts 0, which is not strictly positive

    // 3. withdraw allows negative amounts (effectively a deposit)
    myAccount.withdraw(30.00); // Normal withdrawal
    myAccount.withdraw(-20.00); // Robustness issue: Withdraws a negative amount, effectively depositing 20.00

    // Other cases
    myAccount.deposit(-10.00); // Should fail (correctly handled here)
    myAccount.withdraw(100.00); // Should fail (overdraft, correctly handled)

    std::cout << "Current balance for " << myAccount.getAccountNumber() << ": " 
              << std::fixed << std::setprecision(2) << myAccount.getBalance() << std::endl;

    return 0;
}