#include <iostream>

class Wallet {
private:
    int balance; // Using int, could overflow with very large amounts, but the main issue will be input validation.

public:
    Wallet() : balance(0) {}

    // Deposit method with robustness issue: allows 0 and adds negative amounts.
    void deposit(int amount) {
        if (amount >= 0) { // Should be strictly > 0 for "positive amounts"
            balance += amount;
            std::cout << "Deposited " << amount << ". New balance: " << balance << std::endl;
        } else {
            // Robustness issue: If amount is negative, it gets added, which is effectively a withdrawal
            // without proper validation or intention for a deposit method.
            balance += amount; // This is the flaw. It should reject negative amounts.
            std::cout << "Warning: Added negative amount " << amount << ". New balance: " << balance << std::endl;
        }
    }

    // Withdraw method with robustness issue: allows 0 and withdraws negative amounts (effectively a deposit).
    bool withdraw(int amount) {
        if (amount < 0) { // Robustness issue: If amount is negative, it's treated as a deposit.
            balance -= amount; // Subtracting a negative is adding.
            std::cout << "Warning: Withdrew negative amount " << amount << " (effectively deposited). New balance: " << balance << std::endl;
            return true; // Consider it "successful" in its flawed logic
        }
        if (amount == 0) { // Robustness issue: Allowing 0 withdrawal is pointless but not explicitly disallowed.
            std::cout << "Attempted to withdraw 0. Balance unchanged: " << balance << std::endl;
            return true; // "Successful" no-op
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

    int getBalance() const {
        return balance;
    }
};

int main() {
    Wallet myWallet;

    std::cout << "Initial balance: " << myWallet.getBalance() << std::endl;

    // Test deposit robustness issues
    myWallet.deposit(100);  // Valid deposit
    myWallet.deposit(0);    // Robustness: 0 is not strictly positive, but accepted
    myWallet.deposit(-50);  // Robustness: Negative amount added (should be rejected by deposit)
    std::cout << "Balance after deposits: " << myWallet.getBalance() << std::endl;

    // Test withdraw robustness issues
    myWallet.withdraw(20);  // Valid withdraw
    myWallet.withdraw(0);   // Robustness: 0 withdrawal accepted
    myWallet.withdraw(-30); // Robustness: Negative amount withdrawn (effectively deposited)
    std::cout << "Balance after withdrawals: " << myWallet.getBalance() << std::endl;

    myWallet.withdraw(500); // Insufficient funds
    myWallet.withdraw(80);  // Valid withdraw
    std::cout << "Final balance: " << myWallet.getBalance() << std::endl;

    return 0;
}