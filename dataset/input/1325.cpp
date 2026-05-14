#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount(std::string accNum, std::string holderName, double initialBalance = 0.0)
        : accountNumber(accNum), accountHolderName(holderName), balance(initialBalance) {}

    void deposit(double amount) {
        // LOGICAL ERROR: This method accepts negative amounts, violating the requirement
        balance += amount; // Should have an 'if (amount > 0)' check
        std::cout << "Deposited: " << amount << ". New balance: " << balance << std::endl;
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Withdrawal amount must be positive." << std::endl;
            return false;
        }
        if (balance - amount >= 0) { // Correctly prevents overdrafts
            balance -= amount;
            std::cout << "Withdrew: " << amount << ". New balance: " << balance << std::endl;
            return true;
        } else {
            std::cout << "Insufficient funds. Current balance: " << balance << std::endl;
            return false;
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
    BankAccount myAccount("12345", "Alice Smith", 1000.0);
    std::cout << "Account: " << myAccount.getAccountNumber() << ", Holder: " << myAccount.getAccountHolderName() << std::endl;
    std::cout << "Initial Balance: " << myAccount.getBalance() << std::endl;

    myAccount.deposit(500.0);
    myAccount.withdraw(200.0);
    myAccount.withdraw(1500.0); // Should fail
    myAccount.deposit(-100.0); // This will incorrectly succeed due to the logical error

    std::cout << "Final Balance: " << myAccount.getBalance() << std::endl;

    BankAccount otherAccount("67890", "Bob Johnson");
    std::cout << "Account: " << otherAccount.getAccountNumber() << ", Holder: " << otherAccount.getAccountHolderName() << std::endl;
    std::cout << "Initial Balance: " << otherAccount.getBalance() << std::endl;

    return 0;
}