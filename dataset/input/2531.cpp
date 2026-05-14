#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance = 0.0) : balance(initialBalance) {}

    bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            return true;
        }
        return false;
    }

    bool withdraw(double amount) {
        // LOGICAL ERROR: Does not check for sufficient funds (amount <= balance)
        if (amount > 0) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account(50.0);
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Initial: " << account.getBalance() << std::endl; // Expected: 50.00

    // Test case for logical error: withdraw more than available
    bool success = account.withdraw(100.0); // Should fail, but will succeed and make balance negative
    std::cout << "Withdraw 100: " << (success ? "true" : "false") << std::endl; // Expected: false, Actual: true
    std::cout << "Balance: " << account.getBalance() << std::endl; // Expected: 50.00, Actual: -50.00

    success = account.deposit(20.0);
    std::cout << "Deposit 20: " << (success ? "true" : "false") << std::endl;
    std::cout << "Balance: " << account.getBalance() << std::endl; // Expected: -30.00

    return 0;
}