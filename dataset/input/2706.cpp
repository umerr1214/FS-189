#include <iostream>
#include <string>

class BankAccount {
public: // SEMANTIC ERROR: accountNumber should be private as per question.
    int accountNumber; 
private:
    double balance;

public:
    // Constructor
    BankAccount(int accNum, double initialBalance) {
        accountNumber = accNum;
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
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
        return false;
    }

    // Getter for balance
    double getBalance() const {
        return balance;
    }

    // Getter for account number (still provided, but direct access is also possible)
    int getAccountNumber() const {
        return accountNumber;
    }
};

int main() {
    BankAccount account1(1001, 500.0);
    std::cout << "Account " << account1.getAccountNumber() << " initial balance: " << account1.getBalance() << std::endl;

    // Demonstrating the semantic error: direct access to accountNumber is possible
    account1.accountNumber = 9999; // This line highlights the semantic error
    std::cout << "Account number after direct modification (via public access): " << account1.getAccountNumber() << std::endl;

    account1.deposit(200.0);
    std::cout << "Balance after deposit: " << account1.getBalance() << std::endl;

    if (account1.withdraw(300.0)) {
        std::cout << "Withdrawal successful. New balance: " << account1.getBalance() << std::endl;
    } else {
        std::cout << "Withdrawal failed." << std::endl;
    }

    if (account1.withdraw(1000.0)) {
        std::cout << "Withdrawal successful. New balance: " << account1.getBalance() << std::endl;
    } else {
        std::cout << "Withdrawal failed." << std::endl;
    }

    BankAccount account2(1002, -100.0);
    std::cout << "Account " << account2.getAccountNumber() << " initial balance (negative input): " << account2.getBalance() << std::endl;

    return 0;
}