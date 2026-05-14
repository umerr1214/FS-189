#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    // Constructor: Initializes account details, ensures initial balance is non-negative.
    // Uses const std::string& for efficiency and good practice.
    BankAccount(const std::string& accountNumber, const std::string& accountHolderName, double initialBalance)
        : accountNumber(accountNumber), accountHolderName(accountHolderName) {
        if (initialBalance >= 0) {
            this->balance = initialBalance;
        } else {
            // A robust choice: set to 0 or throw an exception. Setting to 0 here.
            this->balance = 0.0; 
            std::cerr << "Warning: Initial balance cannot be negative. Setting balance to 0.00 for account " 
                      << accountNumber << "." << std::endl;
        }
        std::cout << "Account " << this->accountNumber << " (" << this->accountHolderName 
                  << ") created with initial balance: " << std::fixed << std::setprecision(2) << this->balance << std::endl;
    }

    // Deposit method: Accepts only positive amounts and returns true on success, false otherwise.
    bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Depositing " << std::fixed << std::setprecision(2) << amount 
                      << "... Successful. New balance: " << balance << std::endl;
            return true;
        } else {
            std::cout << "Attempting to deposit " << std::fixed << std::setprecision(2) << amount 
                      << "... Failed. Amount must be positive." << std::endl;
            return false;
        }
    }

    // Withdraw method: Prevents overdrafts and ensures withdrawal amount is positive.
    // Returns true on success, false otherwise.
    bool withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Attempting to withdraw " << std::fixed << std::setprecision(2) << amount 
                      << "... Failed. Amount must be positive." << std::endl;
            return false;
        }
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawing " << std::fixed << std::setprecision(2) << amount 
                      << "... Successful. New balance: " << balance << std::endl;
            return true;
        } else {
            std::cout << "Attempting to withdraw " << std::fixed << std::setprecision(2) << amount 
                      << "... Failed. Insufficient funds." << std::endl;
            return false;
        }
    }

    // getBalance method: Returns the current balance. Marked const as it does not modify the object.
    double getBalance() const {
        return balance;
    }

    // Accessor for account number. Marked const.
    std::string getAccountNumber() const {
        return accountNumber;
    }
    
    // Accessor for account holder name. Marked const.
    std::string getAccountHolderName() const {
        return accountHolderName;
    }
};

int main() {
    // Correct Version Demonstration
    BankAccount myAccount("12345", "Alice", 100.00); 
    
    myAccount.deposit(50.00);
    myAccount.withdraw(30.00);

    // Test invalid deposits
    myAccount.deposit(-10.00); 
    myAccount.deposit(0.00);   

    // Test invalid withdrawals
    myAccount.withdraw(200.00); // Overdraft
    myAccount.withdraw(-20.00); // Negative amount

    // Test initial negative balance handling
    BankAccount anotherAccount("67890", "Bob", -25.00); // Should issue warning and set to 0.00

    std::cout << "Current balance for " << myAccount.getAccountNumber() << " (" << myAccount.getAccountHolderName() 
              << "): " << std::fixed << std::setprecision(2) << myAccount.getBalance() << std::endl;
    std::cout << "Current balance for " << anotherAccount.getAccountNumber() << " (" << anotherAccount.getAccountHolderName() 
              << "): " << std::fixed << std::setprecision(2) << anotherAccount.getBalance() << std::endl;

    return 0;
}