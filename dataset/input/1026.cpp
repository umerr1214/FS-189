#include <iostream>

class BankAccount {
private:
    static int totalAccountsCreated;
    int accountNumber;
    double balance;

public:
    BankAccount(int accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {
        totalAccountsCreated++;
    }

    // Semantic Error: Function is not declared static, but the question requires it to be.
    // Attempting to call BankAccount::getTotalAccounts() from main will result in a compilation error.
    int getTotalAccounts() { // Missing 'static' keyword
        return totalAccountsCreated;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "Insufficient balance." << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int BankAccount::totalAccountsCreated = 0;

int main() {
    BankAccount acc1(101, 1000.0);
    BankAccount acc2(102, 500.0);

    // This line will cause a compilation error because getTotalAccounts is not static
    // and cannot be called using the class name directly.
    std::cout << "Total accounts created: " << BankAccount::getTotalAccounts() << std::endl;

    return 0;
}