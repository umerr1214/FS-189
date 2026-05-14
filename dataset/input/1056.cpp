#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    BankAccount(std::string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Deposit amount must be positive." << std::endl;
        } else {
            balance += amount;
            std::cout << "Deposited " << amount << ". New balance: " << balance << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Withdrawal amount must be positive." << std::endl;
        } else if (amount > balance) {
            std::cout << "Insufficient funds. Current balance: " << balance << std::endl;
        } else {
            balance -= amount;
            std::cout << "Withdrew " << amount << ". New balance: " << balance << std::endl;
        }
    }

    // Semantic Error: Returns a reference to a private member.
    // This allows direct modification of the 'balance' from outside the class,
    // bypassing all validation logic (e.g., negative balance, withdrawal limits).
    double& getBalance() { // Should be 'double getBalance() const' to return by value and be const-correct
        return balance;
    }

    std::string getAccountNumber() const {
        return accountNumber;
    }
};

int main() {
    BankAccount myAccount("11223", 500.0);
    std::cout << "Initial balance: " << myAccount.getBalance() << std::endl; // Expected: 500
    myAccount.deposit(200.0); // Balance: 700.0
    
    // Semantic error exploitation: Directly modify balance via the returned reference
    double& refBalance = myAccount.getBalance();
    refBalance = -1000.0; // Set balance to a negative value, bypassing any deposit/withdrawal validation

    std::cout << "Balance after direct modification: " << myAccount.getBalance() << std::endl; // Expected: -1000.0

    myAccount.withdraw(50.0); // This will now act on -1000.0, resulting in -1050.0
    std::cout << myAccount.getBalance() << std::endl; // Expected: -1050.0
    return 0;
}