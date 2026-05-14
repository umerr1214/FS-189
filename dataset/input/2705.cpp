#include <iostream>
#include <string>

class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(int accNum, double initialBalance) {
        accountNumber = accNum;
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0; // Ensure initial balance is not negative
        }
    }

    // Deposit method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // Withdraw method
    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            return true;
        }
        // LOGICAL ERROR: Returns true even if withdrawal fails due to insufficient funds,
        // misrepresenting the success of the operation.
        return true; // Should be 'return false;' here
    }

    // Getter for balance
    double getBalance() const {
        return balance;
    }

    // Getter for account number
    int getAccountNumber() const {
        return accountNumber;
    }
};

int main() {
    BankAccount account1(1001, 500.0);
    std::cout << "Account " << account1.getAccountNumber() << " initial balance: " << account1.getBalance() << std::endl;

    account1.deposit(200.0);
    std::cout << "Balance after deposit: " << account1.getBalance() << std::endl;

    if (account1.withdraw(300.0)) {
        std::cout << "Withdrawal successful. New balance: " << account1.getBalance() << std::endl;
    } else {
        std::cout << "Withdrawal failed." << std::endl;
    }

    std::cout << "Current balance before large withdraw: " << account1.getBalance() << std::endl;
    if (account1.withdraw(1000.0)) { // This will incorrectly return true
        std::cout << "Withdrawal successful. New balance: " << account1.getBalance() << std::endl;
    } else {
        std::cout << "Withdrawal failed." << std::endl;
    }
    std::cout << "Balance after large withdraw attempt: " << account1.getBalance() << std::endl;

    BankAccount account2(1002, -100.0);
    std::cout << "Account " << account2.getAccountNumber() << " initial balance (negative input): " << account2.getBalance() << std::endl;

    return 0;
}