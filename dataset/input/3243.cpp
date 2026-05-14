#include <iostream>

class Wallet {
private:
    int balance;

public:
    // Constructor initializes balance to 0
    Wallet() : balance(0) {}

    // Deposits a positive amount into the wallet.
    // Returns true on success, false otherwise.
    bool deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited " << amount << ". New balance: " << balance << std::endl;
            return true;
        } else {
            std::cout << "Error: Deposit amount must be positive. Received: " << amount << std::endl;
            return false;
        }
    }

    // Withdraws a positive amount from the wallet if sufficient funds are available.
    // Returns true on success, false otherwise.
    bool withdraw(int amount) {
        if (amount <= 0) {
            std::cout << "Error: Withdraw amount must be positive. Received: " << amount << std::endl;
            return false;
        }
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrew " << amount << ". New balance: " << balance << std::endl;
            return true;
        } else {
            std::cout << "Insufficient funds to withdraw " << amount << ". Current balance: " << balance << std::endl;
            return false;
        }
    }

    // Returns the current balance of the wallet.
    int getBalance() const {
        return balance;
    }
};

int main() {
    Wallet myWallet;

    std::cout << "Initial balance: " << myWallet.getBalance() << std::endl;

    // Test deposit method
    myWallet.deposit(100);  // Valid deposit
    myWallet.deposit(50);   // Valid deposit
    myWallet.deposit(0);    // Invalid deposit (non-positive)
    myWallet.deposit(-20);  // Invalid deposit (negative)
    std::cout << "Balance after deposits: " << myWallet.getBalance() << std::endl;

    // Test withdraw method
    myWallet.withdraw(30);  // Valid withdrawal
    myWallet.withdraw(150); // Valid withdrawal (balance 120, withdraw 150 -> insufficient funds)
    myWallet.withdraw(120); // Valid withdrawal
    myWallet.withdraw(0);   // Invalid withdrawal (non-positive)
    myWallet.withdraw(-10); // Invalid withdrawal (negative)
    std::cout << "Balance after withdrawals: " << myWallet.getBalance() << std::endl;

    // Final balance check
    myWallet.deposit(200);
    std::cout << "Final balance: " << myWallet.getBalance() << std::endl;

    return 0;
}